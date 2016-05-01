#################################################
#
#  (C) 2016 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

if( NOT COMPILER_CHECKED )
  message( "\n** Checking for compiler capabilities..." )
  set( COMPILER_CHECKED 1 CACHE INTERNAL "" )
endif( )


include( CheckCXXCompilerFlag )
include( CheckSymbolExists )


#################################################
#####
##### set default compiler options

set( CMAKE_CXX_STANDARD 11 )

check_cxx_compiler_flag( -fvisibility=hidden GCC_VISIBILITY )
if( GCC_VISIBILITY )
  set( __KDE_HAVE_GCC_VISIBILITY 1 )
  add_definitions( -fvisibility=hidden )
endif( )

check_symbol_exists( __GNU_LIBRARY__ "features.h" _GNU_SOURCE )
if( _GNU_SOURCE )
    add_definitions( -D_GNU_SOURCE )
endif( )


#################################################
#####
##### set default linker options

#set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--disable-new-dtags" )
#set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined -Wl,--disable-new-dtags" )
#set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined -Wl,--disable-new-dtags" )
set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined" )
set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined" )
