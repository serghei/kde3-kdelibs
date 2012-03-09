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
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES
    kde_logo.png cups_logo.png cupsd.conf.template
  DESTINATION ${DATA_INSTALL_DIR}/kdeprint )


#### cupsdconf ##################################

set( target cupsdconf )

set( ${target}_SRCS
  cupsdconf.cpp cupsddialog.cpp cupsdpage.cpp cupsdcomment.cpp
  cupsdsplash.cpp cupsdserverpage.cpp cupsdlogpage.cpp
  cupsdjobspage.cpp cupsdfilterpage.cpp qdirlineedit.cpp
  cupsddirpage.cpp portdialog.cpp cupsdnetworkpage.cpp
  editlist.cpp cupsdbrowsingpage.cpp browsedialog.cpp
  cupsdsecuritypage.cpp locationdialog.cpp addressdialog.cpp
  cups-util.c qdirmultilineedit.cpp sizewidget.cpp main.cpp
)

kde_add_kdeinit_executable( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared ${CUPS_LIBRARIES}
)
