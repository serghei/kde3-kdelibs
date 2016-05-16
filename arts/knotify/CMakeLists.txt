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

# enable c++11 support (for <atomic.h>)
#add_definitions( -std=c++11 )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES knotify.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


##### knotify ###################################

if( WITH_PULSEAUDIO )
  set( SRCS kpulseplayer.cpp )
  set( LIBS kdeui-shared ${PULSEAUDIO_LIBRARIES} ${VORBISFILE_LIBRARIES} ${AUDIOFILE_LIBRARIES} )
else( )
  set( LIBS kdeui-shared )
endif( )

kde_add_kpart( knotify AUTOMOC
  SOURCES knotify.cpp knotify.skel ${SRCS}
  LINK ${LIBS}
  DEPENDENCIES dcopidl
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
