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

add_subdirectory( ksendbugmail )
add_subdirectory( kpac )
add_subdirectory( kdesasl )
add_subdirectory( kssld )
add_subdirectory( kfile )
add_subdirectory( kwalletd )
add_subdirectory( kntlm )

add_definitions(
  -D_LARGEFILE64_SOURCE
)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_BINARY_DIR}/kio
  ${CMAKE_BINARY_DIR}/kio/kio
  ${CMAKE_BINARY_DIR}/kio/kssl
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kssl
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES uiserver.h DESTINATION ${INCLUDE_INSTALL_DIR}/kio )


##### other data ################################

install(FILES
    kio_uiserver.desktop kmailservice.protocol
    telnet.protocol rlogin.protocol rtsp.protocol
    ssh.protocol mms.protocol mmst.protocol mmsu.protocol
    pnm.protocol rtspt.protocol rtspu.protocol
  DESTINATION ${SERVICES_INSTALL_DIR} )

install( FILES fileshareset DESTINATION ${BIN_INSTALL_DIR}
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE SETUID )


#### kio_uiserver ###############################

set( target kio_uiserver )

set( ${target}_SRCS
  uiserver.cpp uiserver.skel
)

kde_add_kdeinit_executable( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared
  DEPENDENCIES dcopidl
)


##### kmailservice ##############################

set( target kmailservice )

kde_add_executable( ${target}
  SOURCES ${target}.cpp
  LINK kdecore-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


##### ktelnetservice ############################

set( target ktelnetservice )

kde_add_executable( ${target}
  SOURCES ${target}.cpp
  LINK kdeui-shared
  DESTINATION ${BIN_INSTALL_DIR}
)

kde_install_symlink( ${target} ${BIN_INSTALL_DIR}/filesharelist )
