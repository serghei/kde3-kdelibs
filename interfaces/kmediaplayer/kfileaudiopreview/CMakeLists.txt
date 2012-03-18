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
  ${CMAKE_BINARY_DIR}/arts/arts/mcop
  ${CMAKE_BINARY_DIR}/arts/arts/flow
  ${CMAKE_BINARY_DIR}/arts/arts/soundserver
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/interfaces
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${CMAKE_SOURCE_DIR}/arts/arts/mcop
  ${CMAKE_SOURCE_DIR}/arts/kde
  ${QT_INCLUDE_DIR}
)


##### kfileaudiopreview #########################

set( target kfileaudiopreview )

set( ${target}_SRCS
  kfileaudiopreview.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kmediaplayer-shared artskde-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
