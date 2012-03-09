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
)


##### headers ###################################

install( FILES
    vcard.h vcardline.h vcardparser.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kabc )


##### vcards ####################################

set( target vcards )

set( ${target}_SRCS
  vcard.cpp vcardline.cpp vcardparser.cpp
)

kde_add_library( ${target} STATIC_PIC
  SOURCES ${${target}_SRCS}
)
