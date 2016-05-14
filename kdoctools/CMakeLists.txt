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

configure_file( checkXML.cmake checkXML @ONLY )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kioslave
  ${QT_INCLUDE_DIR}
  ${LIBXML2_INCLUDE_DIRS}
  ${LIBXSLT_INCLUDE_DIRS}
)


##### other data ################################

install( PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/checkXML DESTINATION ${BIN_INSTALL_DIR} )
install( PROGRAMS move_kio_help_cache.sh DESTINATION ${KCONF_UPDATE_INSTALL_DIR} )
install( FILES kio_help.upd DESTINATION ${KCONF_UPDATE_INSTALL_DIR} )
install( FILES help.protocol ghelp.protocol DESTINATION ${SERVICES_INSTALL_DIR} )
install( DIRECTORY customization docbook DESTINATION ${DATA_INSTALL_DIR}/ksgmltools2 PATTERN ".git" EXCLUDE )


##### kbzipfilter_dummy ##############################

kde_add_library( kbzipfilter_dummy STATIC_PIC
  SOURCES ${CMAKE_SOURCE_DIR}/kioslave/bzip2/kbzip2filter.cpp
)


#### kio_help ###################################

set( target kio_help )

set( ${target}_SRCS
  kio_help.cpp main.cpp xslt.cpp
)

kde_add_kpart( ${target} SHARED
  SOURCES ${${target}_SRCS}
  LINK kbzipfilter_dummy-static kio-shared ${BZIP2_LIBRARY} ${LIBXML2_LIBRARIES} ${LIBXSLT_LIBRARIES}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


#### kio_ghelp ###################################

set( target kio_ghelp )

set( ${target}_SRCS
  kio_help.cpp main_ghelp.cpp xslt.cpp
)

kde_add_kpart( ${target} SHARED
  SOURCES ${${target}_SRCS}
  LINK kbzipfilter_dummy-static kio-shared ${BZIP2_LIBRARY} ${LIBXML2_LIBRARIES} ${LIBXSLT_LIBRARIES}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


#### meinproc ###################################

set( target meinproc )

set( ${target}_SRCS
  meinproc.cpp xslt_pure.cpp
)

# FIXME I think this can be improved
add_custom_command( OUTPUT xslt_pure.cpp COMMAND cp ARGS ${CMAKE_CURRENT_SOURCE_DIR}/xslt.cpp xslt_pure.cpp )
set_source_files_properties( xslt_pure.cpp PROPERTIES COMPILE_FLAGS -DSIMPLE_XSLT )

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kbzipfilter_dummy-static kio-shared ${BZIP2_LIBRARY} ${LIBXML2_LIBRARIES} ${LIBXSLT_LIBRARIES}
  DESTINATION ${BIN_INSTALL_DIR}
)
