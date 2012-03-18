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
  ${CMAKE_CURRENT_SOURCE_DIR}/../arts/arts/mcop
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${QT_INCLUDE_DIR}
)


##### artsmessage ###############################

set( target artsmessage )

set( ${target}_SRCS
  artsmessage.cc
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kdeui-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
