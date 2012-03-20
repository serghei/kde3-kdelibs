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
  ${QT_INCLUDE_DIR}
)


##### dbusxml2qt3 (executable) ##################

kde_add_executable( dbusxml2qt3
  SOURCES classgen.cpp main.cpp methodgen.cpp
  LINK ${QT_LIBRARY}
  DESTINATION ${BIN_INSTALL_DIR}
)
