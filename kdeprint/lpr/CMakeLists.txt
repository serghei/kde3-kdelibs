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
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kdeprint
  ${CMAKE_SOURCE_DIR}/kdeprint/management
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    printcapentry.h lprhandler.h lprsettings.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kdeprint/lpr )


##### other data ################################

install( FILES lpr.print DESTINATION ${DATA_INSTALL_DIR}/kdeprint/plugins )
install( FILES apsdriver1 apsdriver2 lprngtooldriver1 DESTINATION ${DATA_INSTALL_DIR}/kdeprint )


#### kdeprint_lpr ###############################

set( target kdeprint_lpr )

set( ${target}_SRCS
  printcapreader.cpp lprhandler.cpp matichandler.cpp
  klprfactory.cpp kmlprmanager.cpp kmlpruimanager.cpp
  lpchelper.cpp lpqhelper.cpp kmlprjobmanager.cpp
  matichelper.cpp klprprinterimpl.cpp printcapentry.cpp
  lprsettings.cpp kmconfiglpr.cpp apshandler.cpp
  lprngtoolhandler.cpp editentrydialog.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdeprint_management-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


#### make_driver_db_lpr #########################

set( target make_driver_db_lpr )

set( ${target}_SRCS
  make_driver_db_lpr.c
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK driverparse-static kdefakes-shared ${DL_LIBRARY}
  DESTINATION ${BIN_INSTALL_DIR}
)
