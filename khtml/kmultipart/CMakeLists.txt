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
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/khtml
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kutils
  ${QT_INCLUDE_DIR}
)

link_directories(
  ${TQT_LIBRARY_DIRS}
)


##### other data ################################

install( FILES kmultipart.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


##### libkmultipart #############################

set( target libkmultipart )

set( ${target}_SRCS
  kmultipart.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK httpfilter-static kparts-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
