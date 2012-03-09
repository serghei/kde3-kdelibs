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

add_subdirectory( sample )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    scriptinterface.h scriptclientinterface.h scriptmanager.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

install( FILES scriptinterface.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )


##### kscript ###################################

set( target kscript )

set( ${target}_SRCS
  scriptmanager.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 0.0.0
  LINK kio-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
