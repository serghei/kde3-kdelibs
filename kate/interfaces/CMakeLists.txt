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
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/interfaces
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    document.h view.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kate )


##### katepartinterfaces ########################

set( target katepartinterfaces )

set( ${target}_SRCS
  interfaces.cpp katecmd.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 0.0.0
  LINK ktexteditor-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
