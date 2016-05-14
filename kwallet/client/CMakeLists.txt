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
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kwallet.h kwallettypes.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### libkwalletclient ##############################

set( target kwalletclient )

set( ${target}_SRCS
  kwallet.skel kwallet.cc
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 1.0.1
  LINK kdecore-shared
  DEPENDENCIES dcopidl
  DESTINATION ${LIB_INSTALL_DIR}
)
