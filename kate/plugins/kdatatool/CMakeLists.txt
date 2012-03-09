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
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/interfaces
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES ktexteditor_kdatatool.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES ktexteditor_kdatatoolui.rc DESTINATION ${DATA_INSTALL_DIR}/ktexteditor_kdatatool )


##### ktexteditor_kdatatool #####################

set( target ktexteditor_kdatatool )

set( ${target}_SRCS
  kate_kdatatool.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK ktexteditor-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
