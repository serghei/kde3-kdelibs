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

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)

string( REPLACE " -Wl,--no-undefined" "" CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} )


##### headers ###################################

install( FILES
    kscreensaver.h kscreensaver_vroot.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### kscreensaver ##############################

set( target kscreensaver )

set( ${target}_SRCS
  main.cpp kscreensaver.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 4.2.0
  LINK kdecore-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
