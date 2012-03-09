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
  ${CMAKE_SOURCE_DIR}/interfaces/kscript
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES shellscript.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


##### libshellscript ############################

set( target libshellscript )

set( ${target}_SRCS
  shellscript.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kscript-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
