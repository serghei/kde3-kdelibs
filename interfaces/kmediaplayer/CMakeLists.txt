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

if( ARTS_FOUND )
  add_subdirectory( kfileaudiopreview )
endif( ARTS_FOUND )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/interfaces
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    player.h playerdcopobject.h view.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kmediaplayer )


##### other data ################################

install( FILES
    kmediaplayerengine.desktop kmediaplayer.desktop
  DESTINATION ${SERVICETYPES_INSTALL_DIR} )


##### kmediaplayer ##############################

set( target kmediaplayer )

set( ${target}_SRCS
  player.cpp view.cpp playerdcopobject.skel
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 0.0.0
  LINK kparts-shared
  DESTINATION ${LIB_INSTALL_DIR}
  DEPENDENCIES dcopidl
)
