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

add_subdirectory( vcard )
add_subdirectory( vcardparser )
add_subdirectory( formats )
add_subdirectory( plugins )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/vcard/include
  ${CMAKE_CURRENT_SOURCE_DIR}/vcard/include/generated
  ${CMAKE_CURRENT_SOURCE_DIR}/vcardparser

  # external includes
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kab
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    address.h addressbook.h  addresseedialog.h
    agent.h distributionlist.h distributionlistdialog.h
    distributionlisteditor.h errorhandler.h field.h
    format.h formatfactory.h formatplugin.h geo.h key.h
    phonenumber.h picture.h plugin.h resource.h secrecy.h
    resourceselectdialog.h sound.h stdaddressbook.h
    timezone.h vcardconverter.h vcardformat.h lock.h
    vcardformatplugin.h ldifconverter.h addresslineedit.h
    ldapclient.h addresseelist.h locknull.h ldif.h
    ldapurl.h ldapconfigwidget.h sortmode.h
    ${CMAKE_CURRENT_BINARY_DIR}/addressee.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kabc )


##### other data ################################

install( FILES kab2kabc.desktop DESTINATION ${AUTOSTART_INSTALL_DIR} )
install( FILES kabc_manager.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kresources )
install( FILES countrytransl.map DESTINATION ${DATA_INSTALL_DIR}/kabc )


##### generated files ###########################
# FIXME this hack make compatibility with out-of-source mode

file( COPY
    scripts/makeaddressee scripts/addressee.src.cpp
    scripts/addressee.src.h scripts/entrylist scripts/field.src.cpp
  DESTINATION scripts )

add_custom_command(
  OUTPUT addressee.cpp addressee.h field.cpp
  COMMAND perl
  ARGS makeaddressee
  DEPENDS scripts/addressee.src.cpp scripts/addressee.src.h scripts/entrylist scripts/field.src.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/scripts
)


##### kabc ######################################

set( target kabc )

set( ${target}_SRCS
  address.cpp addressbook.cpp addressee.cpp addresseedialog.cpp
  agent.cpp distributionlist.cpp distributionlistdialog.cpp
  distributionlisteditor.cpp errorhandler.cpp field.cpp
  formatfactory.cpp geo.cpp key.cpp phonenumber.cpp
  picture.cpp plugin.cpp resource.cpp resourceselectdialog.cpp
  secrecy.cpp sound.cpp stdaddressbook.cpp timezone.cpp
  vcard21parser.cpp vcardconverter.cpp vcardformat.cpp
  vcardformatimpl.cpp vcardformatplugin.cpp ldifconverter.cpp
  addresslineedit.cpp ldapclient.cpp addresseelist.cpp
  vcardtool.cpp addresseehelper.cpp lock.cpp locknull.cpp
  ldif.cpp ldapurl.cpp ldapconfigwidget.cpp sortmode.cpp
  addresseehelper.skel
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 1.2.0
  LINK vcards-static vcard-shared kio-shared kresources-shared
  DEPENDENCIES addressee.h dcopidl
  DESTINATION ${LIB_INSTALL_DIR}
)


##### kab2kabc ##################################

set( target kab2kabc )

set( ${target}_SRCS
  kab2kabc.cpp
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kab-static kabc-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
