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
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
  ${FREETYPE_INCLUDE_DIRS}
)


#### kdeinit ####################################

set( target kdeinit )

set( ${target}_SRCS
  kinit.cpp setproctitle.cpp
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kparts-shared ${XFT_LIBRARIES}
  DESTINATION ${BIN_INSTALL_DIR}
)


#### kdeinit_wrapper ############################

set( target kdeinit_wrapper )

kde_add_executable( ${target}
  SOURCES wrapper.c
  DESTINATION ${BIN_INSTALL_DIR}
)


#### kshell #####################################

set( target kshell )

kde_add_executable( ${target}
  SOURCES shell.c
  DESTINATION ${BIN_INSTALL_DIR}
)


#### kdeinit_shutdown ###########################

set( target kdeinit_shutdown )

kde_add_executable( ${target}
  SOURCES wrapper.c
  DESTINATION ${BIN_INSTALL_DIR}
)


#### lnusertemp #################################

set( target lnusertemp )

kde_add_executable( ${target}
  SOURCES lnusertemp.c
  DESTINATION ${BIN_INSTALL_DIR}
)


#### kwrapper ###################################

set( target kwrapper )

kde_add_executable( ${target}
  SOURCES kwrapper.c
  DESTINATION ${BIN_INSTALL_DIR}
)


#### kioslave ###################################

set( target kioslave )

kde_add_executable( ${target} AUTOMOC
  SOURCES kioslave.cpp
  LINK kio-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


#### kstartupconfig #############################

set( target kstartupconfig )

kde_add_executable( ${target} AUTOMOC
  SOURCES kstartupconfig.cpp
  LINK kdefakes-shared ${TQT_LIBRARIES}
  DESTINATION ${BIN_INSTALL_DIR}
)


#### kdostartupconfig ###########################

set( target kdostartupconfig )

kde_add_executable( ${target} AUTOMOC
  SOURCES kdostartupconfig.cpp
  LINK kdecore-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


#### start_kdeinit ##############################

set( target start_kdeinit )

if( KDEINIT_SETUID )
  set( _setuid SETUID )
endif( KDEINIT_SETUID )

kde_add_executable( ${target} ${_setuid}
  SOURCES start_kdeinit.c
  DESTINATION ${BIN_INSTALL_DIR}
)

set_target_properties( ${target} PROPERTIES COMPILE_FLAGS -DEXECUTE=\\"${BIN_INSTALL_DIR}/kdeinit\\" )


#### start_kdeinit_wrapper ######################

set( target start_kdeinit_wrapper )

kde_add_executable( ${target}
  SOURCES start_kdeinit_wrapper.c
  DESTINATION ${BIN_INSTALL_DIR}
)


#### klauncher ##################################

set( target klauncher )

set( ${target}_SRCS
  klauncher.cpp klauncher_main.cpp autostart.cpp
)

kde_add_kdeinit_executable( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kio-shared
)
