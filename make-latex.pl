#!/usr/bin/perl -w

use strict;

my $tmp_dir = "/tmp";
my $tmp_pre = "$tmp_dir/scimakelatex.";
my $tex_prefix = "scimakelatex.$$";
my $tex_file = "$tmp_pre$$.tex";
my $dvi_file = "$tmp_pre$$.dvi";
my $ps_file = "$tmp_pre$$.ps";
my $bib_file = "$tmp_dir/scigenbibfile.bib";

my $sysname = &get_system_name();
system( "perl scigen.pl -f scirules.in -s SCIPAPER_LATEX SYSNAME=\"$sysname\""
	. " > $tex_file" ) and
    die( "Couldn't make SCIPAPER_LATEX into file $tex_file" );

# for every figure you find in the file, generate a figure
open( TEX, "<$tex_file" ) or die( "Couldn't read $tex_file" );
my %citelabels = ();
my @figures = ();
while( <TEX> ) {

    my $line = $_;

    if( /figure=(.*),/ ) {
	my $figfile = "$tmp_dir/$1";
	my $done = 0;
	while( !$done ) {
	    system( "./make-graph.pl $figfile" ) or $done=1;
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
foreach my $clabel (keys(%citelabels)) {
    my $sysname_cite = &get_system_name();
    system( "perl scigen.pl -f scirules.in -s BIBTEX_ENTRY " . 
	    "CITE_LABEL_GIVEN=$clabel SYSNAME=\"$sysname_cite\" >> $bib_file" ) 
      and die( "Couldn't make a bibtex entry" );
}

system( "cd $tmp_dir; latex $tex_prefix; bibtex $tex_prefix; latex $tex_prefix; latex $tex_prefix; " . 
	"dvips -o $ps_file $dvi_file" )
    and die( "Couldn't latex nothing." );

system( "gv $ps_file" ) and die( "Couldn't gv $ps_file" );

system( "rm $tmp_pre*" ) and die( "Couldn't rm" );
unlink( @figures );
unlink( "$bib_file" );

sub get_system_name {

    my $name = `perl scigen.pl -f system_names.in -s SYSTEM_NAME -p 0`;
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
