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
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/kmdi
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kutils
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    global.h mainwindow.h toolviewaccessor.h tabwidget.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kmdi )


#### kmdi2 ######################################

set( target kmdi2 )

set( ${target}_SRCS
  mainwindow.cpp dockcontainer.cpp toolviewaccessor.cpp
  guiclient.cpp tabwidget.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 1.0.0
  LINK kutils-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
