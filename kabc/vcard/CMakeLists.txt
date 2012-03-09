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
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/generated
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### vcard #####################################

set( target vcard )

set( ${target}_SRCS
  vCard-all.cpp
)

kde_add_library( ${target} SHARED
  SOURCES ${${target}_SRCS}
  VERSION 0.0.0
  LINK kdecore-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
