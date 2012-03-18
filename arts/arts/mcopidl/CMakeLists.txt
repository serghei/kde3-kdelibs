#################################################
#
#  (C) 2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/../mcop
  ${CMAKE_CURRENT_SOURCE_DIR}/../mcop
)


##### mcopidl (executable) ######################

kde_add_executable( mcopidl AUTOMOC
  SOURCES mcopidl.cc yacc.cc scanner.cc namespace.cc
  LINK mcop-shared
  DESTINATION ${BIN_INSTALL_DIR}
)
