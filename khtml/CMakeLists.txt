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

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WOVERLOADED_VIRTUAL}" )

add_subdirectory( misc )
add_subdirectory( dom )
add_subdirectory( css )
add_subdirectory( xml )
add_subdirectory( html )
add_subdirectory( rendering )
add_subdirectory( pics )
add_subdirectory( java )
add_subdirectory( ecma )
add_subdirectory( kmultipart )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kjs
  ${CMAKE_BINARY_DIR}/kio/kssl
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${CMAKE_SOURCE_DIR}/kio/kssl
  ${CMAKE_SOURCE_DIR}/kutils
  ${CMAKE_SOURCE_DIR}/kwallet/client
  ${CMAKE_SOURCE_DIR}/kdeprint
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    khtmlview.h khtml_part.h khtml_events.h
    khtml_settings.h khtmldefaults.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

install( FILES khtml.desktop khtmlimage.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES khtml.rc khtml_browser.rc khtml_popupmenu.rc DESTINATION ${DATA_INSTALL_DIR}/khtml )


##### khtml #####################################

set( target khtml )

set( ${target}_SRCS
  khtmlview.cpp khtml_part.cpp khtml_run.cpp
  khtml_factory.cpp khtml_settings.cc khtml_events.cpp
  khtml_ext.cpp khtml_pagecache.cpp khtml_iface.cc
  khtml_printsettings.cpp khtmlimage.cpp kjserrordlg.ui
  htmlpageinfo.ui khtml_iface.skel
)

### FIXME what is this?
### if include_VERSION_SCRIPT
### VSCRIPT = -Wl,--version-script=$(srcdir)/libkhtml.map
### endif

### FIXME what about java?
### FIXME maybe static libs must be embedded?

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 4.2.0
  LINK ${VSCRIPT} kjava-static kjs_html-static khtmldom-static khtmlcss-static
    khtmlhtml-static khtmlxml-static khtmlrender-static khtmlmisc-static
    kutils-shared kdeprint-shared kjs-shared ${JPEG_LIBRARY}
  DESTINATION ${LIB_INSTALL_DIR}
  DEPENDENCIES dcopidl
)


##### libkhtmlpart ##############################

set( target libkhtmlpart )

set( ${target}_SRCS
  dummy.cpp
)

file( WRITE ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp
"#include <kdelibs_export.h>
extern \"C\" KDE_EXPORT void* init_libkhtml();
extern \"C\" KDE_EXPORT void* init_libkhtmlpart() { return init_libkhtml(); }
" )

kde_add_kpart( ${target}
  SOURCES ${${target}_SRCS}
  LINK khtml-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### khtmlimagepart ############################

set( target khtmlimagepart )

set( ${target}_SRCS
  imgdummy.cpp
)

file( WRITE ${CMAKE_CURRENT_BINARY_DIR}/imgdummy.cpp
"
#include <kdelibs_export.h>
extern \"C\"  KDE_EXPORT void* init_khtmlimagefactory();
extern \"C\"  KDE_EXPORT void* init_khtmlimagepart() { return init_khtmlimagefactory(); }
" )

kde_add_kpart( ${target}
  SOURCES ${${target}_SRCS}
  LINK khtml-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
