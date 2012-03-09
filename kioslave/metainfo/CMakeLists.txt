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
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES metainfo.protocol DESTINATION ${SERVICES_INSTALL_DIR} )


##### kio_metainfo ##############################

kde_add_kpart( kio_metainfo AUTOMOC
  SOURCES metainfo.cpp
  LINK kio-shared ${BZIP2_LIBRARY}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
