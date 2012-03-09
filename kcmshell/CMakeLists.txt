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
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kutils
  ${QT_INCLUDE_DIR}
)


##### kcmshell ##################################

set( target kcmshell )

set( ${target}_SRCS
  main.cpp main.skel
)

kde_add_kdeinit_executable( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kutils-shared
  DEPENDENCIES dcopidl
)
