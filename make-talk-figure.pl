#!/usr/bin/perl -w

#    This file is part of SCIgen.
#
#    SCIgen is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    SCIgen is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with SCIgen; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


use strict;
use scigen;
use Getopt::Long;

my $tmp_dir = "/tmp";
my $tmp_pre = "/$tmp_dir/scimaketalkfig.$$";
my $svg_file = "$tmp_pre.svg";
my $eps_file = "$tmp_pre.eps";

my $sysname;
my $filename;
my $seed;

sub usage {
    select(STDERR);
    print <<EOUsage;
    
$0 [options]
  Options:

    --help                    Display this help message
    --seed <seed>             Seed the prng with this
    --file <file>             Save the postscript in this file
    --sysname <file>          What is the system called?

EOUsage

    exit(1);

}

# Get the user-defined parameters.
# First parse options
my %options;
&GetOptions( \%options, "help|?", "seed=s", "file=s", "sysname=s" )
    or &usage;

if( $options{"help"} ) {
    &usage();
}
if( defined $options{"file"} ) {
    $filename = $options{"file"};
}
if( defined $options{"sysname"} ) {
    $sysname = $options{"sysname"};
}
if( defined $options{"seed"} ) {
    $seed = $options{"seed"};
} else {
    $seed = int rand 0xffffffff;
}
srand($seed);

if( defined $filename ) {
    $eps_file = $filename;
}

my $dat = {};
my $RE = undef;

my $fh = new IO::File ("<svg_figures.in");
scigen::read_rules ($fh, $dat, \$RE, 0);

my $svg = scigen::generate ($dat, "SVG_FIG", $RE, 0, 0);

# file needs pwd I guess
$svg =~ s/href=\"(.*)\"/href=\"$ENV{'PWD'}\/$1\"/gi;

open( SVG, ">$svg_file" ) or die( "Can't open $svg_file for writing" );
print SVG $svg;
close( SVG );

system( "inkscape -z --export-eps=$eps_file $svg_file" ) and
    die( "Can't run inkscape on $svg_file" );

if( !defined $filename ) {
    system( "gv $eps_file" ) and
	die( "Can't run gv on $eps_file" );
}

system( "rm -f $tmp_pre*" ) and die( "Couldn't rm" );
