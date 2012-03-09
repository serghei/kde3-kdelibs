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

add_subdirectory( config )

add_definitions(
  -DQT_PLUGIN
)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES plastik.themerc DESTINATION ${DATA_INSTALL_DIR}/kstyle/themes )


##### plastik ###################################

set( target plastik )

set( ${target}_SRCS
  plastik.cpp misc.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdefx-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}/plugins/styles
)
