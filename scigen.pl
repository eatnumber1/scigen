#!/usr/bin/perl

#
# simple context-free grammar expander
#
# $Id$
#

use IO::File;
use strict;
use Data::Dumper;


sub read_rules {
    my ($fh, $rules, $name) = @_;
    my $line;
    while ($line = <$fh>) {
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
	push @{$rules->{$name}}, $rule;
    }
}

sub generate {
    my ($rules, $start) = @_;
    my $in = join "|", keys %$rules;
    my $re = qr/^(.*?)(${in})/s; 
    my $s = expand ($rules, $re, $start);
    print "$s\n";
}

sub pick_rand {
    my ($set) = @_;
    my $n = $#$set + 1;
    return @$set[int (rand () * $n)];
}

sub pop_first_rule {
    my ($rules, $regex, $preamble, $input) = @_;
    print "input -> $$input\n";

    my $ret = undef;
    if ($$input =~ s/$regex//s) {
	$$preamble = $1;
	$ret = $2;
    } else {
	$$preamble = $$input;
    }
    return $ret;
}

sub expand {
    my ($rules, $regex, $start) = @_;

    my $input = pick_rand ($rules->{$start});
    my $res = "";
    my $pre;
    my $rule;
    my @components;
    while (($rule = pop_first_rule ($rules, $regex, \$pre, \$input))) {
	my $ex = expand ($rules, $regex, $rule);
	push @components, $pre if length ($pre);
	push @components, $ex if length ($ex);
    }
    push @components, $pre if length ($pre);
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
			 "start=s"    => \$start );

if ( $filename ) {
    $fh = new IO::File ("<$filename");
    die "cannot open input file: $filename\n" unless $fh;
} else {
    $filename = "STDIN";
    $fh = \*STDIN;
}
			 


# run
read_rules ($fh, $dat, $filename);
generate ($dat, $start);
