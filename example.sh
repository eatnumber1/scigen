#!/bin/sh
#
# short example showing the usage of the scigen generator.
#
# $Id$
#

perl -w scigen.pl  \
     -f therules.in \
     -s LITPAPER_LONG \
   TOPIC='The Return of the Jedi' LASTNAME=Walfish FIRSTNAME=Michael
