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
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore/network
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES ftp.protocol DESTINATION ${SERVICES_INSTALL_DIR} )


##### kio_ftp ###################################

set( target kio_ftp )

set( ${target}_SRCS
  ftp.cc
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
