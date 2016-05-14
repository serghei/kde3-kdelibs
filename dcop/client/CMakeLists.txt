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
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_BINARY_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


#### dcop #######################################

kde_add_executable( dcop SOURCES dcop.cpp LINK DCOP-shared X11 DESTINATION ${BIN_INSTALL_DIR} )


#### dcopfind ###################################

kde_add_executable( dcopfind SOURCES dcopfind.cpp LINK DCOP-shared DESTINATION ${BIN_INSTALL_DIR} )


#### dcopclient #################################

kde_add_executable( dcopclient SOURCES dcopclient.c DESTINATION ${BIN_INSTALL_DIR} )


#### dcopobject #################################

kde_add_executable( dcopobject SOURCES dcopobject.c DESTINATION ${BIN_INSTALL_DIR} )


#### dcopref ####################################

kde_add_executable( dcopref SOURCES dcopref.c DESTINATION ${BIN_INSTALL_DIR} )


#### dcopstart ##################################

kde_add_executable( dcopstart SOURCES dcopstart.cpp LINK DCOP-shared DESTINATION ${BIN_INSTALL_DIR} )


#### dcopquit ###################################

kde_add_executable( dcopquit SOURCES dcopquit.cpp LINK DCOP-shared X11 DESTINATION ${BIN_INSTALL_DIR} )
