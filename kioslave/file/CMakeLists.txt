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
  -D_LARGEFILE64_SOURCE
)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES file.h DESTINATION ${INCLUDE_INSTALL_DIR}/kio )


##### other data ################################

install( FILES file.protocol DESTINATION ${SERVICES_INSTALL_DIR} )


##### kio_file ##################################

set( target kio_file )

set( ${target}_SRCS
  file.cc
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)

