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

add_subdirectory( cupsdconf2 )

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
  ${CMAKE_SOURCE_DIR}/kdecore/network
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${CMAKE_SOURCE_DIR}/kdeprint
  ${CMAKE_SOURCE_DIR}/kdeprint/management
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES cups.print DESTINATION ${DATA_INSTALL_DIR}/kdeprint/plugins )
install( FILES preview.png preview-mini.png DESTINATION ${DATA_INSTALL_DIR}/kdeprint )


#### kdeprint_cups ##############################

set( target kdeprint_cups )

set( ${target}_SRCS
  cupsinfos.cpp ipprequest.cpp kmcupsfactory.cpp
  kmcupsjobmanager.cpp kmcupsmanager.cpp kmcupsuimanager.cpp
  kmpropbanners.cpp kmwbanners.cpp kmwipp.cpp kmwippselect.cpp
  kcupsprinterimpl.cpp kmcupsconfigwidget.cpp kmconfigcups.cpp
  kmconfigcupsdir.cpp kmwippprinter.cpp kmwfax.cpp kmwquota.cpp
  kmpropquota.cpp kmwusers.cpp kmpropusers.cpp kpschedulepage.cpp
  image.cpp imagepreview.cpp imageposition.cpp kpimagepage.cpp
  kptextpage.cpp kphpgl2page.cpp cupsaddsmb2.cpp
  kmwother.cpp ippreportdlg.cpp kptagspage.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdeprint_management-shared ${CUPS_LIBRARIES}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


#### make_driver_db_cups ########################

set( target make_driver_db_cups )

set( ${target}_SRCS
  make_driver_db_cups.c
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK driverparse-static kdefakes-shared ${ZLIB_LIBRARIES} ${DL_LIBRARIES}
  DESTINATION ${BIN_INSTALL_DIR}
)


#### cupsdoprint ################################

set( target cupsdoprint )

set( ${target}_SRCS
  cupsdoprint.c
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kdefakes-shared ${CUPS_LIBRARIES}
  DESTINATION ${BIN_INSTALL_DIR}
)
