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
  ${CMAKE_CURRENT_BINARY_DIR}/../misc
  ${CMAKE_BINARY_DIR}/kio/kssl
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore/network
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kssl
  ${CMAKE_SOURCE_DIR}/interfaces
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kservicetype.h kmimetype.h kmimemagic.h kservice.h
    krun.h kdirwatch.h kautomount.h kuserprofile.h
    kshred.h kar.h ktar.h kzip.h ktrader.h kurifilter.h
    kurlcompletion.h kshellcompletion.h kfileitem.h
    kfileshare.h ksambashare.h knfsshare.h kdirlister.h
    kservicegroup.h kimageio.h kdirnotify.h kdirnotify_stub.h
    kurlpixmapprovider.h kprotocolinfo.h kprotocolmanager.h
    kfilterbase.h kfilterdev.h kemailsettings.h kscan.h
    kdatatool.h karchive.h kfilefilter.h kfilemetainfo.h
    renamedlgplugin.h kmimetyperesolver.h kdcopservicestarter.h
    kremoteencoding.h kmimetypechooser.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )

# FIXME seems that ACL is no longer optional
#if( USE_POSIX_ACL )
  install( FILES kacl.h DESTINATION ${INCLUDE_INSTALL_DIR} )
#endif( USE_POSIX_ACL )

install( FILES
    connection.h slaveinterface.h slave.h slaveconfig.h
    sessiondata.h global.h passdlg.h netaccess.h job.h
    scheduler.h jobclasses.h paste.h slavebase.h
    progressbase.h defaultprogress.h statusbarprogress.h
    tcpslavebase.h forwardingslavebase.h observer.h
    chmodjob.h kmdbase.h authinfo.h ioslave_defaults.h
    http_slave_defaults.h previewjob.h thumbcreator.h
    metainfojob.h davjob.h renamedlg.h skipdlg.h
    ${CMAKE_CURRENT_BINARY_DIR}/uiserver_stub.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kio )


##### kiocore ###################################

set( target kiocore )

set( ${target}_SRCS
  authinfo.cpp kshred.cpp kprotocolmanager.cpp slave.cpp
  slaveinterface.cpp observer.stub sessiondata.cpp
  scheduler.cpp connection.cpp job.cpp global.cpp
  slaveconfig.cpp kurlpixmapprovider.cpp netaccess.cpp
  paste.cpp pastedialog.cpp kmimemagic.cpp tcpslavebase.cpp
  slavebase.cpp passdlg.cpp forwardingslavebase.cpp
  progressbase.cpp defaultprogress.cpp statusbarprogress.cpp
  kdirnotify.cpp kdirnotify.skel kdirnotify_stub.cpp
  observer.cpp ../misc/uiserver.stub observer.skel kemailsettings.cpp
  kprotocolinfo.cpp renamedlg.cpp skipdlg.cpp kremoteencoding.cpp
  kmimetypechooser.cpp
)

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
  DEPENDENCIES dcopidl
)


##### ksycoca ###################################

set( target ksycoca )

set( ${target}_SRCS
  kdirwatch.cpp kfileshare.cpp ksambashare.cpp
  knfsshare.cpp ktrader.cpp ktraderparse.cpp
  ktraderparsetree.cpp kservicetypefactory.cpp
  kservicetype.cpp kmimetype.cpp kservicegroup.cpp
  kservice.cpp kservicefactory.cpp kuserprofile.cpp
  kservicegroupfactory.cpp kurifilter.cpp kfilterbase.cpp
  kfilterdev.cpp kshellcompletion.cpp kurlcompletion.cpp
  kautomount.cpp krun.cpp kfileitem.cpp kdirlister.cpp
  kimageio.cpp yacc.c lex.c chmodjob.cpp kscan.cpp
  kar.cpp ktar.cpp kzip.cpp previewjob.cpp metainfojob.cpp
  davjob.cpp kdatatool.cpp karchive.cpp kfilefilter.cpp
  kfilemetainfo.cpp kdcopservicestarter.cpp dataslave.cpp
  dataprotocol.cpp
)

# FIXME seems that ACL is no longer optional
#if( USE_POSIX_ACL )
  set( ${target}_SRCS ${${target}_SRCS} kacl.cpp posixacladdons.cpp )
#endif( USE_POSIX_ACL )

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
)
