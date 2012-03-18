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

include( ConfigureChecks.cmake )

configure_file( artsc-config.cmake artsc-config @ONLY )
configure_file( artsc_export.h.cmake artsc_export.h @ONLY )
configure_file( artsdsp.cmake artsdsp @ONLY )

add_definitions( -DARTSC_BACKEND="${LIB_INSTALL_DIR}/libartscbackend.so" )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/../mcop
  ${CMAKE_CURRENT_BINARY_DIR}/../flow
  ${CMAKE_CURRENT_BINARY_DIR}/../soundserver
  ${CMAKE_CURRENT_SOURCE_DIR}/../mcop
  ${CMAKE_CURRENT_SOURCE_DIR}/../flow
  ${CMAKE_BINARY_DIR}
)


##### headers ###################################

install( FILES
    artsc.h ${CMAKE_CURRENT_BINARY_DIR}/artsc_export.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/artsc )


##### scripts ###################################

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/artsc-config
    ${CMAKE_CURRENT_BINARY_DIR}/artsdsp
  DESTINATION ${BIN_INSTALL_DIR} )


##### artsc (shared) ############################

kde_add_library( artsc SHARED
  SOURCES artsc.c
  VERSION 0.0.0
  LINK ${DL_LIBRARY}
  DESTINATION ${LIB_INSTALL_DIR}
)


##### libartsdsp (module) #######################

kde_add_kpart( libartsdsp
  SOURCES artsdsp.c
  LINK artsc-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### libartsdsp_st (module) ####################

kde_add_kpart( libartsdsp_st
  SOURCES artsc.c artsdsp.c
  LINK ${DL_LIBRARY}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### libartscbackend (module) ##################

kde_add_kpart( libartscbackend
  SOURCES artscbackend.cc
  LINK soundserver_idl-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
