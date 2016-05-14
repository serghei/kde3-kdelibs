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
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kded
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES
    kdetrayproxy.desktop
  DESTINATION ${SERVICES_INSTALL_DIR}/kded )


##### kded_kdetrayproxy #########################

kde_add_kpart( kded_kdetrayproxy AUTOMOC
  SOURCES kdetrayproxy.cpp module.cpp module.skel
  LINK kdecore-shared kdeinit_kded-shared
  DEPENDENCIES dcopidl
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
