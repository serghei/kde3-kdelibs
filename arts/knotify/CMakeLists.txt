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
  ${CMAKE_SOURCE_DIR}/arts/kde
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES knotify.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


##### knotify ###################################

if( ARTS_FOUND )
  set( LIBS artskde-shared )
else( ARTS_FOUND )
  set( LIBS kdeui-shared )
endif( ARTS_FOUND )

kde_add_kpart( knotify AUTOMOC
  SOURCES knotify.cpp knotify.skel
  LINK ${LIBS}
  DEPENDENCIES dcopidl
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
