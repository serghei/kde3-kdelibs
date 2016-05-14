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
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    defaults.h client.h process.h kdesu_pty.h
    kcookie.h su.h ssh.h stub.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kdesu )


##### libkdesu ##################################

set( target kdesu )

set( ${target}_SRCS
  client.cpp process.cpp kcookie.cpp
  su.cpp ssh.cpp stub.cpp kdesu_pty.cpp
)

kde_add_library( ${target} SHARED
  SOURCES ${${target}_SRCS}
  VERSION 4.2.0
  LINK kdecore-shared ${LIB_UTIL}
  DESTINATION ${LIB_INSTALL_DIR}
)

kde_install_symlink( kdesu_pty.h ${INCLUDE_INSTALL_DIR}/kdesu/pty.h )


##### kdesu_stub ################################

kde_add_executable( kdesu_stub
  SOURCES kdesu_stub.c
  DESTINATION ${BIN_INSTALL_DIR}
)
