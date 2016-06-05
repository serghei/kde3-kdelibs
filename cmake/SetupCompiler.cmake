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

option( USE_DISTCC "Enable distcc support" OFF )
if( USE_DISTCC )
    set( CMAKE_C_COMPILER_LAUNCHER distcc )
    set( CMAKE_CXX_COMPILER_LAUNCHER distcc )
endif( )

include( CheckCXXCompilerFlag )
include( CheckSymbolExists )


#################################################
#####
##### set default compiler options

set( CMAKE_CXX_STANDARD 11 )
add_definitions( -DHAVE_CONFIG_H )

check_cxx_compiler_flag( -fvisibility=hidden GCC_VISIBILITY )
if( GCC_VISIBILITY )
  set( __KDE_HAVE_GCC_VISIBILITY 1 )
  add_definitions( -fvisibility=hidden )
endif( )

check_symbol_exists( __GNU_LIBRARY__ "features.h" _GNU_SOURCE )
if( _GNU_SOURCE )
  add_definitions( -D_GNU_SOURCE )
endif( )

option( USE_LTO "Enable GCC interprocedural optimizations" OFF )
if( USE_LTO )
  check_cxx_compiler_flag( "-flto;-fno-fat-lto-objects" GCC_LTO )
  if( NOT GCC_LTO )
      message( FATAL_ERROR
        "################################################################\n"
        " You asked for interprocedural optimizations but\n"
        " `-flto -fno-fat-lto-objects` is not supported by your compiler\n"
        "################################################################" )
  endif( )

  add_compile_options( -O2 -flto -fno-fat-lto-objects )
  set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O2 -flto -fuse-linker-plugin" )
  set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -O2 -flto -fuse-linker-plugin" )
  set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -O2 -flto -fuse-linker-plugin" )
  set( CMAKE_AR gcc-ar )
  set( CMAKE_RANLIB gcc-ranlib )
endif( )

option( USE_ASAN "Enable AddressSanitizer" OFF )
if( USE_ASAN )
  add_compile_options( -g -fsanitize=address )
  set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address" )
  set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fsanitize=address" )
  set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -fsanitize=address" )
endif( )


#################################################
#####
##### set default linker options

#set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--disable-new-dtags" )
#set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined -Wl,--disable-new-dtags" )
#set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined -Wl,--disable-new-dtags" )
set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined" )
set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined" )
