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
  ${CMAKE_CURRENT_BINARY_DIR}/../arts/mcop
  ${CMAKE_CURRENT_BINARY_DIR}/../arts/flow
  ${CMAKE_CURRENT_BINARY_DIR}/../arts/soundserver
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../arts/mcop
  ${CMAKE_CURRENT_SOURCE_DIR}/../arts/flow
  ${CMAKE_CURRENT_SOURCE_DIR}/../arts/qtmcop
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kplayobject.h kplayobjectfactory.h kartsfloatwatch.h
    ${CMAKE_CURRENT_BINARY_DIR}/artskde.h kartsdispatcher.h
    kaudiorecordstream.h kaudioplaystream.h kartsserver.h
    kvideowidget.h kaudiomanagerplay.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/arts )


##### artskde ###################################

set( KDE_MCOPIDL_PARAMS
  -I${CMAKE_CURRENT_SOURCE_DIR}/../arts/flow
  -I${CMAKE_CURRENT_SOURCE_DIR}/../arts/soundserver )

kde_add_library( artskde SHARED AUTOMOC
  SOURCES
    artskde.idl kioinputstream_impl.cpp kplayobject.cc
    kplayobjectfactory.cc kartsfloatwatch.cpp kartsdispatcher.cc
    kaudiorecordstream.cpp kaudioplaystream.cpp kartsserver.cpp
    kdatarequest_impl.cpp kaudioconverter.cc kvideowidget.cpp
    kplayobjectcreator.cc kaudiomanagerplay.cpp
  VERSION 1.2.0
  LINK kio-shared soundserver_idl-shared qtmcop-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
