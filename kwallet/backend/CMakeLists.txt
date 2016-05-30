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
  ${CMAKE_SOURCE_DIR}/kwallet/client
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### libkwalletbackend #########################

set( target kwalletbackend )

set( ${target}_SRCS
  blockcipher.cpp blowfish.cpp
  cbc.cpp sha1.cpp kwalletentry.cpp
  kwalletbackend.cpp
)

kde_add_library( ${target} SHARED
  SOURCES ${${target}_SRCS}
  VERSION 1.0.0
  LINK kdecore-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
