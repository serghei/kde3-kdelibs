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
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install(FILES kntlm.h DESTINATION ${INCLUDE_INSTALL_DIR}/kio )


##### kntlm ###################################

set( target kntlm )

set( ${target}_SRCS
  kntlm.cpp des.cpp
)

kde_add_library( ${target} SHARED
  SOURCES ${${target}_SRCS}
  VERSION 0.0.0
  LINK kdecore-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
