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

add_definitions(
  -D_KDEPRINT_COMPILE
)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kdeprint
  ${CMAKE_SOURCE_DIR}/kdeprint/management
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES rlpr.print DESTINATION ${DATA_INSTALL_DIR}/kdeprint/plugins )


##### kdeprint_rlpr #############################

set( target kdeprint_rlpr )

set( ${target}_SRCS
  kmrlprfactory.cpp kmrlprmanager.cpp krlprprinterimpl.cpp
  kmrlpruimanager.cpp kmwrlpr.cpp kmproprlpr.cpp
  kmproxywidget.cpp kmconfigproxy.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdeprint_management-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
