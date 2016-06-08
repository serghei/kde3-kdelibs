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

if( NOT WITH_DCOP_DBUS )
  add_subdirectory( KDE-ICE )
elseif( BUILD_DCOP_TESTS )
  add_subdirectory( tests )
endif( )

add_subdirectory( dcopidl )
add_subdirectory( dcopidlng )
add_subdirectory( dcopidl2cpp )
add_subdirectory( client )

set( DCOP_PATH "${BIN_INSTALL_DIR}" )
configure_file( dcop-path.h.cmake dcop-path.h @ONLY )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    dcopclient.h dcopobject.h dcopstub.h dcopref.h
    dcoptypes.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### libDCOP ###################################

if( WITH_DCOP_DBUS )
    include_directories( ${CMAKE_SOURCE_DIR}/dbus/src )
    set( KDEDBUS kdedbus-shared )
    set( DCOPCLIENT dcopclient.cpp )
else( )
    set( KICE kICE-static )
    set( DCOPCLIENT dcopclient_ice.cpp )
endif( )

kde_add_library( DCOP SHARED AUTOMOC
  SOURCES dcopstub.cpp dcopref.cpp dcopobject.cpp ${DCOPCLIENT}
  VERSION 4.2.0
  LINK ${KICE} ${KDEDBUS} ${QT_LIBRARY}
  DESTINATION ${LIB_INSTALL_DIR}
)


#### dcopserver (kdeinit) #######################

if( NOT WITH_DCOP_DBUS )
  kde_add_kdeinit_executable( dcopserver AUTOMOC
    SOURCES dcopserver.cpp dcopsignals.cpp
    LINK kICE-static DCOP-shared
  )
endif( )


#### dcopserver_shutdown ########################

if( NOT WITH_DCOP_DBUS )
  kde_add_executable( dcopserver_shutdown
    SOURCES dcopserver_shutdown.c
    DESTINATION ${BIN_INSTALL_DIR}
  )
endif( )
