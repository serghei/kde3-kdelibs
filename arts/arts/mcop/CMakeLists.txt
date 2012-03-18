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

configure_file( arts_export.h.cmake arts_export.h )

add_definitions( -DEXTENSION_DIR="${LIB_INSTALL_DIR}" -DTRADER_DIR="${LIB_INSTALL_DIR}/mcop" )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
)


##### headers ###################################

install( FILES
    buffer.h common.h connection.h core.h dispatcher.h
    factory.h flowsystem.h idlfilereg.h ifacerepo_impl.h
    iomanager.h mcoputils.h object.h objectmanager.h
    pool.h socketconnection.h startupmanager.h tcpconnection.h
    tcpserver.h type.h unixconnection.h unixserver.h
    referenceclean.h datapacket.h asyncstream.h notification.h
    extensionloader.h mcopconfig.h connect.h reference.h
    weakreference.h dynamicrequest.h anyref.h debug.h
    delayedreturn.h dynamicskeleton.h thread.h core.idl
    ${CMAKE_CURRENT_BINARY_DIR}/arts_export.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/arts )


##### mcop (shared) #############################

kde_add_library( mcop SHARED
  SOURCES
    buffer.cc connection.cc core.cc debug.cc dispatcher.cc iomanager.cc
    object.cc socketconnection.cc tcpconnection.cc unixconnection.cc
    tcpserver.cc unixserver.cc objectmanager.cc factory.cc idlfilereg.cc
    ifacerepo_impl.cc mcoputils.cc startupmanager.cc md5.c md5auth.cc
    referenceclean.cc datapacket.cc asyncstream.cc notification.cc
    flowsystem.cc extensionloader.cc tmpglobalcomm.cc mcopconfig.cc
    connect.cc reference.cc type.cc trader_impl.cc dynamicrequest.cc
    anyref.cc loopback.cc delayedreturn.cc thread.cc dynamicskeleton.cc
  VERSION 1.0.0
  LINK ${DL_LIBRARY}
  DESTINATION ${LIB_INSTALL_DIR}
)
