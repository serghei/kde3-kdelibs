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
  ${CMAKE_CURRENT_BINARY_DIR}/../mcop
  ${CMAKE_CURRENT_BINARY_DIR}/../flow
  ${CMAKE_CURRENT_SOURCE_DIR}/../mcop
  ${CMAKE_CURRENT_SOURCE_DIR}/../flow
  ${CMAKE_BINARY_DIR}
  ${GLIB2_INCLUDE_DIRS}
)


##### mcop_mt (shared) ##########################

kde_add_library( mcop_mt SHARED
  SOURCES threads_posix.cc
  VERSION 1.0.0
  LINK mcop-shared ${PTHREAD_LIBRARY}
  DESTINATION ${LIB_INSTALL_DIR}
)
