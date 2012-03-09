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
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
  ${LIBART_INCLUDE_DIRS}
)


##### headers ###################################

install( FILES
    ksvgiconengine.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### kdesvgicons ###############################

set( target kdesvgicons )

set( ${target}_SRCS
  ksvgiconengine.cpp ksvgiconpainter.cpp
)

kde_add_library( ${target} STATIC_PIC
  SOURCES ${${target}_SRCS}
  LINK ${LIBART_LIBRARIES}
)
