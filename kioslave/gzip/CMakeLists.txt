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
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES kgzipfilter.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


##### kgzipfilter ###############################

set( target kgzipfilter )

set( ${target}_SRCS
  kgzipfilter.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
