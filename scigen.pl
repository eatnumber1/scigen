#!/usr/bin/perl

#
# simple context-free grammar expander
#
# $Id$
#

use IO::File;
use strict;
use Data::Dumper;
use Autoformat;

my $debug = 0;
my $pretty = 1;

use vars qw [ $RE ];


sub read_rules {
    my ($fh, $rules, $name) = @_;
    my $line;
    while ($line = <$fh>) {
	next if $line =~ /^#/ ;
	next if $line !~ /\S/ ;
	    
	my @words = split /\s+/, $line;
	my $name = shift @words;
	my $rule = "";
	if ($#words == 0 && $words[0] eq '{') {
	    my $end = 0;
	    while ($line = <$fh>) {
		if ($line eq "}\n") {
		    $end = 1;
		    last;
		} else {
		    $rule .= $line;
		}
	    }
	    if (! $end) {
		die "$name: EOF found before close rule\n";
	    }
	} else {
	    $line =~ s/^\S+\s+//; 
	    chomp ($line);
	    $rule = $line;
	}

	# look for the weight
	my $weight = 1;
	if( $name =~ /([^\+]*)\+(\d+)$/ ) {
	    $name = $1;
	    $weight = $2;
	    if( $debug > 10 ) {
		warn "weighting rule by $weight: $name -> $rule\n";
	    }
	}

	do {
	    push @{$rules->{$name}}, $rule;
	} while( --$weight > 0 );
    }
}


sub generate {
    my ($rules, $start) = @_;

    # must sort; order matters, and we want to make sure that we get
    # the longest matches first
    my $in = join "|", sort { length ($b) <=> length ($a) } keys %$rules;

    $RE = qr/^(.*?)(${in})/s ;
    my $s = expand ($rules, $start);
    if( $pretty ) {
	$s = pretty_print($s);
    }
    print "$s\n";
}

sub pick_rand {
    my ($set) = @_;
    my $n = $#$set + 1;
    my $v =  @$set[int (rand () * $n)];
    return $v;
}

sub pop_first_rule {
    my ($rules, $preamble, $input, $rule) = @_;

    $$preamble = undef;
    $$rule = undef;

    my $ret = undef;
    
    if ($$input =~ s/$RE//s ) {
	$$preamble = $1;
	$$rule = $2;
	return 1;
    }
	
    return 0;
}

sub pretty_print {

    my ($s) = shift;

    my $news = "";
    my @lines = split( /\n/, $s );
    foreach my $line (@lines) {

	my $newline = "";

	$line =~ s/(\s+)([\.\,\?\;\:])/$2/g;

	if( $line =~ /\\section(\*?){(.*)}/ ) {
	    $newline = "\\section${1}{" . 
	      Autoformat::autoformat( $2, { case => 'highlight', squeeze => 0 } );
	    chomp $newline;
	    chomp $newline;
	    $newline .= "}\n";
	} elsif( $line =~ /\\subsection{(.*)}/ ) {
	    $newline = "\\subsection{" . 
	      Autoformat::autoformat( $1, { case => 'highlight', squeeze => 0 } );
	    chomp $newline;
	    chomp $newline;
	    $newline .= "}\n";
	} elsif( $line =~ /\\title{(.*)}/ ) {
	    $newline = "\\title{" . 
	      Autoformat::autoformat( $1, { case => 'highlight', squeeze => 0  } );
	    chomp $newline;
	    chomp $newline;
	    $newline .= "}\n";
	} elsif( $line =~ /title = {{(.*)}}\,/ ) {
	    $newline = "title = {{" . 
	      Autoformat::autoformat( $1, { case => 'highlight', squeeze => 0  } );
	    chomp $newline;
	    chomp $newline;
	    $newline .= "}},\n";
	} else {
	    $newline .= 
	      Autoformat::autoformat( $line, { case => 'sentence', squeeze => 0, 
					       ignore => qr/^\\/ } ) . "\n";
	}

	$news .= $newline;

    }

    return $news;
}

sub expand {
    my ($rules, $start) = @_;

    # check for special rules ending in + and # 
    # Rules ending in + generate a sequential integer
    # The same rule ending in # chooses a random # from among preiously
    # generated integers
    if( $start =~ /(.*)\+$/ ) {
	my $rule = $1;
	my $i = $rules->{$rule};
	if( !defined $i ) {
	    $i = 0;
	    $rules->{$rule} = 1;
	} else {
	    $rules->{$rule} = $i+1;
	}
	return $i;
    } elsif( $start =~ /(.*)\#$/ ) {
	my $rule = $1;
	my $i = $rules->{$rule};
	if( !defined $i ) {
	    $i = 0;
	} else {
	    $i = int rand $i;
	}
	return $i;
    }

    my $input = pick_rand ($rules->{$start});
    if ($debug >= 5) {
	warn "$start -> $input\n";
    }
    my $res = "";
    my ($pre, $rule);
    my @components;

    while (pop_first_rule ($rules, \$pre, \$input, \$rule)) {
	my $ex = expand ($rules, $rule);
	push @components, $pre if length ($pre);
	push @components, $ex if length ($ex);
    }
    push @components, $input if length ($input);
    return  join "", @components ;
}

# main
my $dat = {} ;
my $fh;
my $filename;
my $start = "START";

use Getopt::Long;

# parse args
my $result = GetOptions ("filename=s" => \$filename,
			 "start=s"    => \$start,
			 "pretty=i"    => \$pretty,
			 "debug=i"    => \$debug );

if ( $filename ) {
    $fh = new IO::File ("<$filename");
    die "cannot open input file: $filename\n" unless $fh;
} else {
    $filename = "STDIN";
    $fh = \*STDIN;
}

foreach my $arg (@ARGV) {
    my ($n,$v) = split /=/, $arg;
    push @{$dat->{$n}}, $v;
}

# run
read_rules ($fh, $dat, $filename);
generate ($dat, $start);
