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
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${QT_INCLUDE_DIR}
)


##### kstyle_highcontrast_config ################

set( target kstyle_highcontrast_config )

set( ${target}_SRCS
  highcontrastconfig.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
