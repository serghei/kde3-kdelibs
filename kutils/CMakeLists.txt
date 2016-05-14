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

add_subdirectory( ksettings )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kutils
  ${CMAKE_SOURCE_DIR}/interfaces/kregexpeditor
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kfind.h kfinddialog.h kreplace.h kreplacedialog.h
    kcmoduleinfo.h kcmoduleloader.h kcmultidialog.h
    kmultitabbar.h kplugininfo.h kcmoduleproxy.h
    kpluginselector.h kcmodulecontainer.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

install( FILES kplugininfo.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )


#### kutils #####################################

set( target kutils )

set( ${target}_SRCS
  kfind.cpp kfinddialog.cpp kreplace.cpp
  kreplacedialog.cpp kcmoduleinfo.cpp kcmoduleloader.cpp
  kcmultidialog.cpp kmultitabbar.cpp kplugininfo.cpp
  kcmoduleproxy.cpp kpluginselector.cpp kcmodulecontainer.cpp
  kcmoduleproxyIface.skel kcmoduleproxyIfaceImpl.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 1.2.0
  EMBED ksettings-static
  LINK kparts-shared
  DESTINATION ${LIB_INSTALL_DIR}
  DEPENDENCIES dcopidl
)
