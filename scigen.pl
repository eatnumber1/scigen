#!/usr/bin/perl

#
# simple context-free grammar expander
#
# $Id$
#

use IO::File;
use strict;
use scigen;

# main
my $dat = {} ;
my $fh;
my $filename;
my $start = "START";
my $debug = 0;
my $pretty = 1;
my $RE;

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
scigen::read_rules ($fh, $dat, \$RE, $debug);
print scigen::generate ($dat, $start, $RE, $debug, $pretty) . "\n";
