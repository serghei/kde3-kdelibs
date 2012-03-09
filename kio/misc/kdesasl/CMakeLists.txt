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
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install(FILES kdesasl.h DESTINATION ${INCLUDE_INSTALL_DIR}/kio )


##### kdesasl ###################################

set( target kdesasl )

set( ${target}_SRCS
  kdesasl.cpp
)

kde_add_library( ${target} SHARED
  SOURCES ${${target}_SRCS}
  VERSION 1.2.0
  LINK kdecore-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
