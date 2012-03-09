#################################################
#
#  (C) 2010-2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

kde_create_handbook( SRCDIR ${CMAKE_SOURCE_DIR}/kdoctools DESTINATION kspell )
add_dependencies( kspell-en-handbook meinproc )
