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

configure_file( ksslconfig.h.cmake ksslconfig.h @ONLY )

add_subdirectory( kssl )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore/network
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kwallet/client
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kssl.h ksslcertificatehome.h ksslsettings.h ksslcertificate.h
    ksslconnectioninfo.h ksslcertificatefactory.h ksslcertificatecache.h
    ksslpeerinfo.h ksslinfodlg.h ksslcertdlg.h ksslutils.h kopenssl.h
    ksslall.h ksslpkcs12.h ksslcertchain.h ksslkeygen.h ksslx509v3.h
    ksslsigners.h ksslpkcs7.h ksslpemcallback.h ksslsession.h
    ${CMAKE_CURRENT_BINARY_DIR}/ksslconfig.h ksslx509map.h ksmimecrypto.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### kssl ######################################

set( target kssl )

set( ${target}_SRCS
  kssl.cc ksslcertificatehome.cc ksslsettings.cc
  ksslcertificate.cc ksslconnectioninfo.cc ksslcertificatefactory.cc
  ksslcertificatecache.cc ksslpeerinfo.cc ksslinfodlg.cc
  ksslcertdlg.cc ksslutils.cc kopenssl.cc ksslpkcs12.cc
  ksslcertchain.cc ksslkeygen.cc ksslx509v3.cc
  ksslsigners.cc ksslpkcs7.cc ksslpemcallback.cc
  ksslx509map.cc ksslsession.cc keygenwizard.ui
  keygenwizard2.ui ksmimecrypto.cc ksslcsessioncache.cc
)

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
)
