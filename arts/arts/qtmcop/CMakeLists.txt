#################################################
#
#  (C) 2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/../mcop
  ${CMAKE_CURRENT_SOURCE_DIR}/../mcop
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    qiomanager.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/arts )


##### qtmcop (shared) ###########################

kde_add_library( qtmcop SHARED AUTOMOC
  SOURCES qiomanager.cc
  VERSION 1.0.0
  LINK mcop-shared ${QT_LIBRARY}
  DESTINATION ${LIB_INSTALL_DIR}
)
