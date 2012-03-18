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
  ${CMAKE_CURRENT_BINARY_DIR}/..
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  ${CMAKE_CURRENT_BINARY_DIR}/../../mcop
  ${GLIB2_INCLUDE_DIRS}
)


##### gslpp (static lib) ########################

kde_add_library( gslpp STATIC_PIC
  SOURCES datahandle.cpp
)
