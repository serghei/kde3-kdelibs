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

add_subdirectory( management )
add_subdirectory( lpdunix )
if( CUPS_FOUND )
  add_subdirectory( cups )
endif( CUPS_FOUND )
add_subdirectory( lpr )
add_subdirectory( rlpr )
add_subdirectory( ext )
add_subdirectory( filters )
add_subdirectory( pics )
add_subdirectory( tools )

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
  ${CMAKE_SOURCE_DIR}/kded
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kprinter.h kprintaction.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )

install( FILES
    kprintdialogpage.h kpreloadobject.h kmmanager.h
    kmprinter.h kmobject.h kprintdialog.h driver.h
    kmjobmanager.h kmjob.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kdeprint )


##### other data ################################

install( FILES kprintpreviewui.rc DESTINATION ${CONFIG_INSTALL_DIR}/ui )
install( FILES testprint.ps specials.desktop DESTINATION ${DATA_INSTALL_DIR}/kdeprint )
install( FILES kdeprintd.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kded )
install( FILES kdeprintrc DESTINATION ${CONFIG_INSTALL_DIR} )
install( FILES kdeprintrc.upd DESTINATION ${KCONF_UPDATE_INSTALL_DIR} )


##### driverparse ###############################

set( target driverparse )

kde_add_library( ${target} STATIC_PIC
  SOURCES driverparse.c
)


##### kded_kdeprintd ############################

set( target kded_kdeprintd )

set( ${target}_SRCS
  kdeprintd.cpp kprintprocess.cpp kdeprintd.skel
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared kdeinit_kded-shared
  DEPENDENCIES dcopidl dcopidl2cpp
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


#### kdeprint ###################################

set( target kdeprint )

set( ${target}_SRCS
  kmfactory.cpp kmjob.cpp kmjobmanager.cpp kmmanager.cpp
  kmprinter.cpp kmuimanager.cpp kmvirtualmanager.cpp
  driver.cpp driveritem.cpp droptionview.cpp driverview.cpp
  kmdbentry.cpp kprintpreview.cpp kprintdialog.cpp
  kprinter.cpp kprinterimpl.cpp kprintdialogpage.cpp
  kpcopiespage.cpp kpdriverpage.cpp kprinterpropertydialog.cpp
  kpgeneralpage.cpp kpqtpage.cpp kmthreadjob.cpp
  kpipeprocess.cpp kpfilterpage.cpp kmspecialmanager.cpp
  kdeprintcheck.cpp plugincombobox.cpp kpreloadobject.cpp
  kfilelist.cpp kprintaction.cpp kpfileselectpage.cpp
  treecombobox.cpp kxmlcommand.cpp util.cpp printerfilter.cpp
  marginpreview.cpp marginvaluewidget.cpp marginwidget.cpp
  kpmarginpage.cpp messagewindow.cpp posterpreview.cpp
  kpposterpage.cpp foomatic2loader.cpp fooparser.cpp
  fooscanner.cpp ppdparser.cpp ppdscanner.cpp ppdloader.cpp
  kmfactory.skel
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 4.2.0
  LINK kio-shared
  DEPENDENCIES dcopidl dcopidl2cpp
  DESTINATION ${LIB_INSTALL_DIR}
)

set_target_properties( ${target}-shared PROPERTIES COMPILE_FLAGS -D_KDEPRINT_COMPILE )
