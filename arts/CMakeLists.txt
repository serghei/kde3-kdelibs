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

if( WITH_ARTS )
  add_subdirectory( arts )
  add_subdirectory( kde )
  add_subdirectory( message )
endif( )

 add_subdirectory( knotify )
