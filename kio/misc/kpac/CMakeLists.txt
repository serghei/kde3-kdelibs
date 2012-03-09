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
  ${CMAKE_BINARY_DIR}/kjs
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore/network
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kded
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES proxyscout.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kded )
install( FILES eventsrc DESTINATION ${DATA_INSTALL_DIR}/proxyscout )


##### kded_proxyscout ###########################

kde_add_kpart( kded_proxyscout AUTOMOC
  SOURCES
    proxyscout.cpp proxyscout.skel script.cpp
    downloader.cpp discovery.cpp
  LINK kdeinit_kded-shared kjs-shared ${RESOLV_LIBRARY}
  DEPENDENCIES dcopidl
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kpac_dhcp_helper ##########################

# FIXME on Gentoo this binary is not suided
kde_add_executable( kpac_dhcp_helper SETUID
  SOURCES kpac_dhcp_helper.c
  DESTINATION ${BIN_INSTALL_DIR}
)
