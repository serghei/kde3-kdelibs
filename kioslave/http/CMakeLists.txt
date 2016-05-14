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

add_subdirectory( kcookiejar )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore/network
  ${CMAKE_SOURCE_DIR}/interfaces
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/httpfilter
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES
    http_cache_cleaner.desktop http.protocol https.protocol
    webdav.protocol webdavs.protocol
  DESTINATION ${SERVICES_INSTALL_DIR} )


##### kio_http_cache_cleaner ####################

set( target kio_http_cache_cleaner )

set( ${target}_SRCS
  http_cache_cleaner.cpp
)

kde_add_kdeinit_executable( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared
)


##### kio_http ##################################

# FIXME GSSAPI support is not handled yet

set( target kio_http )

set( ${target}_SRCS
  http.cc
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK httpfilter-static kntlm-shared kio-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
