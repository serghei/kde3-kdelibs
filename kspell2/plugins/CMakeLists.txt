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

if( WITH_ASPELL )
  add_subdirectory( aspell )
endif(WITH_ASPELL)

if( WITH_HSPELL )
  add_subdirectory( hspell )
endif(WITH_HSPELL)

add_subdirectory( ispell )
