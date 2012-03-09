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
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES kdedmodule.h DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

install( FILES kdedmodule.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )
install( FILES applications.menu DESTINATION ${XDG_MENU_INSTALL_DIR} )
install( FILES kded.upd DESTINATION ${KCONF_UPDATE_INSTALL_DIR} )


#### kded #######################################

set( target kded )

set( ${target}_SRCS
  kded.cpp kdedmodule.cpp
)

# we must to export kdeinit_kded-shared because various
# modules need this library
kde_add_kdeinit_executable( ${target} AUTOMOC EXPORT
  SOURCES ${${target}_SRCS}
  LINK kio-shared
)


#### kbuildsycoca ###############################

set( target kbuildsycoca )

set( ${target}_SRCS
  kbuildsycoca.cpp kbuildservicetypefactory.cpp
  kbuildservicefactory.cpp kbuildservicegroupfactory.cpp
  kbuildimageiofactory.cpp kbuildprotocolinfofactory.cpp
  kctimefactory.cpp vfolder_menu.cpp
)

kde_add_kdeinit_executable( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared
)


#### kdontchangethehostname #####################

set( target kdontchangethehostname )

set( ${target}_SRCS
  khostname.cpp
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kdecore-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


#### kde-menu ###################################

set( target kde-menu )

set( ${target}_SRCS
  kde-menu.cpp
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kio-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
