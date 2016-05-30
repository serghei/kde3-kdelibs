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
  ${CMAKE_BINARY_DIR}
  ${QT_INCLUDE_DIR}
)


##### dcopidl ###################################

kde_add_executable( dcopidl
  SOURCES main.cpp yacc.cpp scanner.cpp
  LINK DCOP-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
