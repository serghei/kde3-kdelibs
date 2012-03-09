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
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    domainbrowser.h query.h remoteservice.h
    publicservice.h servicebase.h servicebrowser.h
    ${CMAKE_CURRENT_BINARY_DIR}/settings.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/dnssd )


##### kdnssd ####################################

set( target kdnssd )

set( ${target}_SRCS
  remoteservice.cpp responder.cpp servicebase.cpp
  settings.kcfgc publicservice.cpp query.cpp
  domainbrowser.cpp servicebrowser.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 1.0.0
  LINK kdecore-shared
  DEPENDENCIES kconfig_compiler
  DESTINATION ${LIB_INSTALL_DIR}
)
