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
  -D_LARGEFILE64_SOURCE=1
)

add_subdirectory( kssl )
add_subdirectory( kio )
add_subdirectory( bookmarks )
add_subdirectory( kfile )
add_subdirectory( pics )
add_subdirectory( kioexec )
add_subdirectory( httpfilter )
add_subdirectory( misc )
add_subdirectory( kpasswdserver )
add_subdirectory( tests )

include_directories(
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES magic DESTINATION ${MIME_INSTALL_DIR} )

install( FILES
    application.desktop kurifilterplugin.desktop
    kcomprfilter.desktop kscan.desktop kdatatool.desktop
    kfileplugin.desktop kcmodule.desktop
  DESTINATION ${SERVICETYPES_INSTALL_DIR} )

install( FILES kioslave.upd DESTINATION ${KCONF_UPDATE_INSTALL_DIR} )
install( PROGRAMS useragent.pl proxytype.pl DESTINATION ${KCONF_UPDATE_INSTALL_DIR} )
install( FILES renamedlgplugin.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )
install( FILES kpasswdserver.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kded )
install( FILES data.protocol DESTINATION ${SERVICES_INSTALL_DIR} )


##### libkio ####################################

set( target kio )

configure_file( ${TEMPLATE_DUMMY_CPP} dummy.cpp COPYONLY )

kde_add_library( ${target} SHARED
  SOURCES ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp
  VERSION 4.2.0
  EMBED kssl-static kiocore-static ksycoca-static kbookmarks-static kfile-static
  LINK kdeui-shared kdesu-shared kwalletclient-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
