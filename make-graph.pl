#!/usr/bin/perl -w

use strict;

# noise margin
my $MARGIN = .1;

my $XMAX = 3.1;
my $XMIN = -3.1;

my $NUM_POINTS = 1000;

sub add_noise {

    my $x = shift;
    my $n = rand abs($x*($MARGIN*2));

    return $x + ($n-$MARGIN);

}

my $func = `./scigen.pl -f functions.in -s EXPR`;
#print "func = $func\n";

for( my $j = 0; $j < $NUM_POINTS; $j++ ) {

    my $x = (rand ($XMAX-$XMIN))+$XMIN;
    my $expr = $func . " ";
    $expr =~ s/xxx/$x/g;
    #print "expr = $expr\n";
    my $y = eval( $expr );
    if( !defined $y ) {
	print "UNDEF!\n";
	exit -1;
    }

    my $yn = &add_noise($y);

    print "$x $yn\n";

}


