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

add_subdirectory( kmdi )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/res
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kutils
  ${CMAKE_SOURCE_DIR}/kmdi
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    kmdichildarea.h kmdichildfrm.h kmdichildfrmcaption.h
    kmdidefines.h kmdiiterator.h kmdilistiterator.h
    kmdimainfrm.h kmdinulliterator.h kmditaskbar.h
    kmdichildview.h kmditoolviewaccessor.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


#### kmdi #######################################

set( target kmdi )

set( ${target}_SRCS
  kmdichildarea.cpp kmdichildfrm.cpp kmdichildfrmcaption.cpp
  kmdichildview.cpp kmdimainfrm.cpp kmditaskbar.cpp
  kmdidockcontainer.cpp kmditoolviewaccessor.cpp
  kmdiguiclient.cpp kmdidocumentviewtabwidget.cpp
  kmdifocuslist.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 1.0.0
  LINK kmdi2-shared
  DESTINATION ${LIB_INSTALL_DIR}
)
