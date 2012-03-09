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
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kwallet/client
  ${CMAKE_SOURCE_DIR}/kwallet/backend
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install(FILES kwalletd.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kded )


#### kded_kwalletd ##############################

set( target kded_kwalletd )

set( ${target}_SRCS
  kwalletd.cpp kwalletd.skel ktimeout.cpp kwalletwizard.ui
  kbetterthankdialogbase.ui
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdeinit_kded-shared kwalletbackend-shared
  DEPENDENCIES dcopidl
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
