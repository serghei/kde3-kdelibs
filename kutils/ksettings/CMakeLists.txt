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
  ${CMAKE_SOURCE_DIR}/kutils
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    dispatcher.h dialog.h pluginpage.h componentsdialog.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/ksettings )


##### ksettings #################################

set( target ksettings )

set( ${target}_SRCS
  dispatcher.cpp dialog.cpp pluginpage.cpp componentsdialog.cpp
)

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
)
