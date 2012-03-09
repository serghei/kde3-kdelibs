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

configure_file( kjava.policy.cmake kjava.policy @ONLY )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_BINARY_DIR}/kio/kssl
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/khtml
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kssl
  ${QT_INCLUDE_DIR}
)

link_directories(
  ${TQT_LIBRARY_DIRS}
)


##### configure #################################

set( KJAVA_POLICYPATH "${CMAKE_INSTALL_PREFIX}/${DATA_INSTALL_DIR}/kjava/-" )
#configure_file( kjava.policy.in kjava.policy @ONLY )


##### install data ##############################

install( FILES kjavaappletviewer.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES kjava.jar ${CMAKE_CURRENT_BINARY_DIR}/kjava.policy pluginsinfo DESTINATION ${DATA_INSTALL_DIR}/kjava )
kde_install_icons( DESTINATION ${DATA_INSTALL_DIR}/kjava/icons )


##### kjava-static ##############################

set( target kjava )

set( ${target}_SRCS
  kjavaapplet.cpp kjavaappletcontext.cpp kjavaappletserver.cpp
  kjavaappletwidget.cpp kjavaprocess.cpp kjavadownloader.cpp
)

kde_add_library( ${target} STATIC_PIC
  SOURCES ${${target}_SRCS}
  LINK ${TQT_LIBRARIES}
)


##### kjavaappletviewer #########################

set( target kjavaappletviewer )

set( ${target}_SRCS
  kjavaapplet.cpp kjavaappletcontext.cpp
  kjavaappletserver.cpp kjavaappletwidget.cpp kjavaprocess.cpp
  kjavadownloader.cpp kjavaappletviewer.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kparts-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
