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
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    resource.h configwidget.h factory.h manageriface.h
    managerimpl.h manager.h selectdialog.h configdialog.h
    configpage.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kresources )


##### other data ################################

install( FILES kresources_plugin.desktop kresources_manager.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )

# FIXME what is xdg_apps_DATA = kresources.desktop
install( FILES kresources.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )


##### kresources ################################

set( target kresources )

set( ${target}_SRCS
  resource.cpp factory.cpp managerimpl.cpp configwidget.cpp
  configdialog.cpp selectdialog.cpp configpage.cpp
  manageriface.skel manageriface.stub
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 1.2.0
  LINK kio-shared
  DESTINATION ${LIB_INSTALL_DIR}
  DEPENDENCIES dcopidl
)


##### kcm_kresources ############################

set( target kcm_kresources )

set( ${target}_SRCS
  kcmkresources.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kresources-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
