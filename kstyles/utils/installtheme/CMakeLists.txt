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
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### kinstalltheme #############################

set( target kinstalltheme )

set( ${target}_SRCS
  main.cpp
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kdecore-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
