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
  ${CMAKE_BINARY_DIR}/kio/kssl
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${CMAKE_SOURCE_DIR}/kio/kssl
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES kcertpart.desktop DESTINATION ${SERVICES_INSTALL_DIR} )
install( FILES kcertpart.rc DESTINATION ${DATA_INSTALL_DIR}/kcertpart )


##### libkcertpart ##############################

set( target libkcertpart )

set( ${target}_SRCS
  kcertpart.cc
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared kparts-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
