#!/usr/bin/perl -w

use strict;

# noise margin
my $MARGIN = .1;

my $XMAX = int rand 100 + 10;
my $XMIN = $XMAX - int rand 2*$XMAX;

my $NUM_POINTS_SCATTER =int rand 1000 + 100;
my $NUM_POINTS_CURVE = (int rand 100) + 10;

sub add_noise {

    my $x = shift;
    my $n = rand abs($x*($MARGIN*2));

    return $x + ($n-$MARGIN);

}

my $graph = `perl scigen.pl -f scirules.in -s GNUPLOT`;
#print "# [$$] func = $func\n";

my @graph_lines = split( /\n/, $graph );

my $type;
my $curves;

my $tmp_dir = "/tmp/scigengraph.";
my $gpfile = "$tmp_dir$$.gnuplot";
my $epsfile = "$tmp_dir$$.eps";
my $datafile = "$tmp_dir$$.dat";
my @labels = ();
my $num_points = 10;

open( GPFILE, ">$gpfile" ) or die( "Couldn't write to $gpfile" );

print GPFILE "set terminal postscript eps\n";
print GPFILE "set output \"$epsfile\"\n";

foreach my $line (@graph_lines) {

    if( $line =~ /graphtype (.*)=(.*)/ ) {
	$type = $1;
	$curves = $2;
	if( $type eq "scatter" ) {
	    $num_points = $NUM_POINTS_SCATTER;
	} else {
	    $num_points = $NUM_POINTS_CURVE;
	}
    } elsif( $line =~ /curvelabel (.*)/ ) {
	push @labels, $1;
    } else {
	print GPFILE "$line\n";
    }

}

my @x = ();
for( my $j = 0; $j < $num_points; $j++ ) {
    
    my $x = (rand ($XMAX-$XMIN))+$XMIN;
    push @x, $x;

}
@x = sort { $a <=> $b} @x;

print GPFILE "plot ";
for( my $i = 0; $i < $curves; $i++ ) {
    my $label = $labels[$i];
    print GPFILE "\'$datafile.$i\' $label with ";
    if( $type eq "scatter" ) {
	print GPFILE "points";
    } else {
	print GPFILE "linespoints";
    }

    if( $i != $curves -1 ) {
	print GPFILE ", ";
    } else {
	print GPFILE "\n";
    }

    my $func = `perl scigen.pl -f functions.in -s EXPR`;

    open( DAT, ">$datafile.$i" ) or die( "Couldn't write to $datafile.$i" );

    foreach my $x (@x) {
	
	my $expr = $func . " ";
	$expr =~ s/xxx/$x/g;
	#print "expr = $expr\n";
	my $y = eval( $expr );
	if( !defined $y or $y eq "NaN" ) {
	    next;
	}
	
	my $yn = &add_noise($y);
	
	print DAT "$x $yn\n";
	
    }

    close( DAT );

}

close( GPFILE );

system( "gnuplot $gpfile" ) and die( "Couldn't gnuplot $gpfile" );
system( "gv $epsfile" ) and die( "Couldn't gv $epsfile" );
system( "rm $tmp_dir$$*" ) and die( "Couldn't rm anything" );

