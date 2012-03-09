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
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES kcookiejar.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kded )
install( FILES kcookiescfg.upd DESTINATION ${KCONF_UPDATE_INSTALL_DIR} )
install( FILES domain_info DESTINATION ${DATA_INSTALL_DIR}/khtml )


##### kcookiejar ################################

set( target kcookiejar )

set( ${target}_SRCS
  main.cpp
)

kde_add_kdeinit_executable( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdecore-shared
)


##### kded_kcookiejar ###########################

set( target kded_kcookiejar )

set( ${target}_SRCS
  kcookiejar.cpp kcookieserver.cpp kcookiewin.cpp
  kcookieserver.skel
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdeui-shared kdeinit_kded-shared
  DEPENDENCIES dcopidl
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
