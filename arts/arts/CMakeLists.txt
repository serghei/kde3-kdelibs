#################################################
#
#  (C) 2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

set( ARTS_MAJOR_VERSION 1 )
set( ARTS_MINOR_VERSION 5 )
set( ARTS_MICRO_VERSION 10 )
set( ARTS_VERSION "${ARTS_MAJOR_VERSION}.${ARTS_MINOR_VERSION}.${ARTS_MICRO_VERSION}" )

add_subdirectory( artsc )
add_subdirectory( flow )
add_subdirectory( mcop )
add_subdirectory( mcop_mt )
add_subdirectory( mcopidl )
add_subdirectory( qtmcop )
add_subdirectory( soundserver )
