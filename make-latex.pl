#!/usr/bin/perl -w

use strict;
use scigen;
use IO::File;
use Getopt::Long;

my $tmp_dir = "/tmp";
my $tmp_pre = "$tmp_dir/scimakelatex.";
my $tex_prefix = "scimakelatex.$$";
my $tex_file = "$tmp_pre$$.tex";
my $dvi_file = "$tmp_pre$$.dvi";
my $ps_file = "$tmp_pre$$.ps";
my $bib_file = "$tmp_dir/scigenbibfile.bib";
my @authors;

sub usage {
    select(STDERR);
    print <<EOUsage;
    
$0 [options]
  Options:

    --help                    Display this help message
    --author                  An author of the paper (can be specified 
                              multiple times)

EOUsage

    exit(1);

}

# Get the user-defined parameters.
# First parse options
my %options;
&GetOptions( \%options, "help|?", "author=s@" )
    or &usage;

if( $options{"help"} ) {
    &usage();
}
if( $options{"author"} ) {
    @authors = @{$options{"author"}};
}

my $name_dat = {};
my $name_RE = undef;
my $tex_dat = {};
my $tex_RE = undef;

my $sysname = &get_system_name();
my $tex_fh = new IO::File ("<scirules.in");
my @a = ($sysname);
$tex_dat->{"SYSNAME"} = \@a;
# add in authors
$tex_dat->{"AUTHOR_NAME"} = \@authors;
my $s = "";
for( my $i = 0; $i <= $#authors; $i++ ) {
    $s .= "AUTHOR_NAME";
    if( $i < $#authors-1 ) {
	$s .= ", ";
    } elsif( $i == $#authors-1 ) {
	$s .= " and ";
    }
}
my @b = ($s);
$tex_dat->{"SCIAUTHORS"} = \@b;

scigen::read_rules ($tex_fh, $tex_dat, \$tex_RE, 0);
my $tex = scigen::generate ($tex_dat, "SCIPAPER_LATEX", $tex_RE, 0, 1);
open( TEX, ">$tex_file" ) or die( "Couldn't open $tex_file for writing" );
print TEX $tex;
close( TEX );

# for every figure you find in the file, generate a figure
open( TEX, "<$tex_file" ) or die( "Couldn't read $tex_file" );
my %citelabels = ();
my @figures = ();
while( <TEX> ) {

    my $line = $_;

    if( /figure=(figure.*),/ ) {
	my $figfile = "$tmp_dir/$1";
	my $done = 0;
	while( !$done ) {
	    system( "./make-graph.pl $figfile" ) or $done=1;
	}
	push @figures, $figfile;
    }

    if( /figure=(dia.*),/ ) {
	my $figfile = "$tmp_dir/$1";
	my $done = 0;
	while( !$done ) {
	    if( `which neato` ) {
		(system( "./make-diagram.pl \"$sysname\" $figfile" ) or 
		 !(-f $figfile)) 
		    or $done=1;
	    } else {
		system( "./make-graph.pl $figfile" ) or $done=1;
	    }
	}
	push @figures, $figfile;
    }

    # find citations
    while( $line =~ s/(cite\:\d+)[,\}]// ) {
        my $citelabel = $1;
	$citelabels{$citelabel} = 1;
    }
    if( $line =~ /(cite\:\d+)$/ ) {
        my $citelabel = $1;
	$citelabels{$citelabel} = 1;
    }

}
close( TEX );

# generate bibtex 
open( BIB, ">$bib_file" ) or die( "Couldn't open $bib_file for writing" );
foreach my $clabel (keys(%citelabels)) {
    my $sysname_cite = &get_system_name();
    @a = ($sysname_cite);
    $tex_dat->{"SYSNAME"} = \@a;
    my @b = ($clabel);
    $tex_dat->{"CITE_LABEL_GIVEN"} = \@b;
    scigen::compute_re( $tex_dat, \$tex_RE );
    my $bib = scigen::generate ($tex_dat, "BIBTEX_ENTRY", $tex_RE, 0, 1);
    print BIB $bib;
    
}
close( BIB );

system( "cd $tmp_dir; latex $tex_prefix; bibtex $tex_prefix; latex $tex_prefix; latex $tex_prefix; " . 
	"dvips -o $ps_file $dvi_file" )
    and die( "Couldn't latex nothing." );

system( "gv $ps_file" ) and die( "Couldn't gv $ps_file" );

system( "rm $tmp_pre*" ) and die( "Couldn't rm" );
unlink( @figures );
unlink( "$bib_file" );

sub get_system_name {

    if( !defined $name_RE ) {
	my $fh = new IO::File ("<system_names.in");
        scigen::read_rules ($fh, $name_dat, \$name_RE, 0);
    }

    my $name = scigen::generate ($name_dat, "SYSTEM_NAME", $name_RE, 0, 0);
    chomp($name);

    # how about some effects?
    my $rand = rand;
    if( $rand < .1 ) {
	$name = "{\\em $name}";
    } elsif( length($name) <= 6 and $rand < .4 ) {
	$name = uc($name);
    }

    return $name;
}
