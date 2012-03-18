#################################################
#
#  (C) 2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

configure_file( artsversion.h.cmake artsversion.h )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/../mcop
  ${CMAKE_CURRENT_BINARY_DIR}/../flow
  ${CMAKE_CURRENT_SOURCE_DIR}/../mcop
  ${CMAKE_CURRENT_SOURCE_DIR}/../flow
  ${CMAKE_BINARY_DIR}
)

set( KDE_MCOPIDL_PARAMS
  -I${CMAKE_CURRENT_SOURCE_DIR}
  -I${CMAKE_CURRENT_SOURCE_DIR}/../mcop
  -I${CMAKE_CURRENT_SOURCE_DIR}/../flow
)


##### headers ###################################

install( FILES
    soundserver.idl kmedia2.idl
    ${CMAKE_CURRENT_BINARY_DIR}/artsversion.h
    ${CMAKE_CURRENT_BINARY_DIR}/soundserver.h
    ${CMAKE_CURRENT_BINARY_DIR}/kmedia2.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/arts )


##### other data ################################

if( HAVE_WAVSUPPORT )
  set( WAV_MCOPCLASS WavPlayObject.mcopclass )
endif( )

install( FILES
    FileInputStream.mcopclass ${WAV_MCOPCLASS}
    GSLPlayObject.mcopclass
  DESTINATION ${LIB_INSTALL_DIR}/mcop/Arts )

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/soundserver.mcoptype
    ${CMAKE_CURRENT_BINARY_DIR}/soundserver.mcopclass
    ${CMAKE_CURRENT_BINARY_DIR}/kmedia2.mcoptype
    ${CMAKE_CURRENT_BINARY_DIR}/kmedia2.mcopclass
  DESTINATION ${LIB_INSTALL_DIR}/mcop )


##### kmedia2_idl (shared) #########################

kde_add_library( kmedia2_idl SHARED
  SOURCES kmedia2.idl
  VERSION 1.0.0
  LINK artsflow-shared
  DESTINATION ${LIB_INSTALL_DIR}
)


##### soundserver_idl (shared) ##################

kde_add_library( soundserver_idl SHARED
  SOURCES soundserver.idl
  VERSION 1.0.0
  LINK kmedia2_idl-shared
  DESTINATION ${LIB_INSTALL_DIR}
)


##### kmedia2 (shared) ##########################

kde_add_library( kmedia2 SHARED
  SOURCES fileinputstream_impl.cc stdoutwriter_impl.cc
  VERSION 1.0.0
  LINK kmedia2_idl-shared
  DESTINATION ${LIB_INSTALL_DIR}
)


##### libartsgslplayobject (module) #############

kde_add_kpart( libartsgslplayobject
  SOURCES gslplayobject_impl.cc
  LINK soundserver_idl-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### libartswavplayobject (module) #############

kde_add_kpart( libartswavplayobject
  SOURCES wavplayobject_impl.cc
  LINK soundserver_idl-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### artsd (executable) ########################

kde_add_executable( artsd
  SOURCES
    soundserverv2_impl.cc soundserver_impl.cc simplesoundserver_impl.cc
    artsd.cc cpuusage.cc samplestorage_impl.cc crashhandler.cc soundserverstartup_impl.cc
  LINK soundserver_idl-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


##### artsplay (executable) #####################

kde_add_executable( artsplay
  SOURCES artsplay.cc
  LINK soundserver_idl-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


##### artscat (executable) ######################

kde_add_executable( artscat
  SOURCES artscat.cc
  LINK soundserver_idl-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


##### artswrapper (executable) ##################

kde_add_executable( artswrapper
  SOURCES artswrapper.c
  DESTINATION ${BIN_INSTALL_DIR}
)

set_target_properties( artswrapper PROPERTIES COMPILE_FLAGS -DEXECUTE=\\"${BIN_INSTALL_DIR}/artsd\\" )


##### artsshell (executable) ####################

kde_add_executable( artsshell
  SOURCES artsshell.cc tradercheck.cc
  LINK soundserver_idl-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


##### artsrec (executable) ######################

kde_add_executable( artsrec
  SOURCES artsrec.cc
  LINK soundserver_idl-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
