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
  ${QT_INCLUDE_DIR}
)


##### dcopidl2cpp ###############################

kde_add_executable( dcopidl2cpp
  SOURCES main.cpp skel.cpp stub.cpp stubimpl.cpp
  LINK ${QT_LIBRARY}
  DESTINATION ${BIN_INSTALL_DIR}
)
