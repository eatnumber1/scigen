#!/usr/bin/perl -w

use strict;

my $tmp_dir = "/tmp";
my $tmp_pre = "$tmp_dir/scimakelatex.";
my $tex_file = "$tmp_pre$$.tex";
my $dvi_file = "$tmp_pre$$.dvi";
my $ps_file = "$tmp_pre$$.ps";

system( "perl scigen.pl -f scirules.in -s SCIPAPER_LATEX > $tex_file" ) and
    die( "Couldn't make SCIPAPER_LATEX into file $tex_file" );

# for every figure you find in the file, generate a figure
open( TEX, "<$tex_file" ) or die( "Couldn't read $tex_file" );
while( <TEX> ) {
    if( /figure=(.*),/ ) {
	my $figfile = "$tmp_dir/$1";
	system( "./make-graph.pl $figfile" ) and
	    die( "couldn't make $figfile" );
    }
}
close( TEX );

system( "cd $tmp_dir; latex $tex_file; latex $tex_file; latex $tex_file; " . 
	"dvips -o $ps_file $dvi_file" )
    and die( "Couldn't latex nothing." );

system( "gv $ps_file" ) and die( "Couldn't gv $ps_file" );

system( "rm $tmp_pre*" ) and die( "Couldn't rm" );

