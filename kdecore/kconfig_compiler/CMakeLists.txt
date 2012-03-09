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


##### kconfig_compiler ##########################

kde_add_executable( kconfig_compiler
  SOURCES kconfig_compiler.cpp
  LINK kdecore-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
