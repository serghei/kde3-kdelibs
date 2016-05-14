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
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${CMAKE_SOURCE_DIR}/kdeprint
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kmmainview.h kmjobviewer.h kmprinterpage.h
    kiconselectaction.h kmtimer.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kdeprint )


##### other data ################################

install( FILES
    tileup.png tiledown.png side.png
  DESTINATION ${DATA_INSTALL_DIR}/kdeprint )


#### kdeprint_management ########################

set( target kdeprint_management )

set( ${target}_SRCS
  kmdbcreator.cpp kmdriverdb.cpp kmdriverdbwidget.cpp
  kmiconview.cpp kminfopage.cpp kmmainview.cpp kmpages.cpp
  kmprinterview.cpp kmjobviewer.cpp jobitem.cpp kmpropwidget.cpp
  kmpropcontainer.cpp kmpropertypage.cpp kmpropgeneral.cpp
  cjanuswidget.cpp kmpropmembers.cpp kmpropbackend.cpp
  kmpropdriver.cpp kmlistview.cpp kminstancepage.cpp
  kmtimer.cpp kmwizard.cpp kmwizardpage.cpp kmwinfopage.cpp
  kmwpassword.cpp kmwsocketutil.cpp kmwbackend.cpp
  kmwsocket.cpp kmwdriver.cpp kmwdriverselect.cpp
  kmwdrivertest.cpp kmwinfobase.cpp kmwname.cpp kmwend.cpp
  kmwclass.cpp kmwlpd.cpp kmwfile.cpp kmdriverdialog.cpp
  kmwsmb.cpp smbview.cpp kmconfigdialog.cpp kmconfigpage.cpp
  kmconfiggeneral.cpp kmspecialprinterdlg.cpp kmwlocal.cpp
  kiconselectaction.cpp kmconfigpreview.cpp sidepixmap.cpp
  pluginaction.cpp kxmlcommanddlg.cpp kxmlcommandselector.cpp
  kmconfigcommand.cpp kmconfigfilter.cpp kmconfigfonts.cpp
  kmconfigjobs.cpp networkscanner.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 4.2.0
  LINK kdeprint-shared
  DESTINATION ${LIB_INSTALL_DIR}
)


#### libkdeprint_management_module ##############

set( target libkdeprint_management_module )

set( ${target}_SRCS
  kdeprint_management_module.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdeprint_management-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


#### kaddprinterwizard ##########################

set( target kaddprinterwizard )

set( ${target}_SRCS
  kaddprinterwizard.cpp
)

kde_add_kdeinit_executable( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdeprint-shared
)
