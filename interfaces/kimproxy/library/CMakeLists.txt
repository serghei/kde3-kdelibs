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

add_subdirectory( icons )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/../interface
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kimproxy.h kimproxyiface.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### kimproxy ##################################

set( target kimproxy )

set( ${target}_SRCS
  kimproxy.cpp kimproxyiface.skel
  ../interface/kimiface.stub
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 0.0.0
  LINK kio-shared
  DESTINATION ${LIB_INSTALL_DIR}
  DEPENDENCIES dcopidl
)
