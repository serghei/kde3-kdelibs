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

add_definitions(
  -DKDE_NO_COMPAT
)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kspell2
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    dialog.h highlighter.h configdialog.h configwidget.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kspell2 )


#### kspell2 (static) ###########################

set( target kspell2 )

set( ${target}_SRCS
   configwidget.cpp highlighter.cpp configdialog.cpp
   kspell2ui.ui configui.ui
)

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
)


#### kspell2 ####################################

set( target kspell2 )

set( ${target}_SRCS
  dialog.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 1.0.0
  LINK kspell2-static kspell2base-static kutils-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
