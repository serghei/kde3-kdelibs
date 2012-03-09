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
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
  ${X11_INCLUDE_DIRS}
  ${ZLIB_INCLUDE_DIRS}
)


##### headers ###################################

install( FILES
    kpixmap.h kpixmapsplitter.h kpixmapeffect.h
    kimageeffect.h kdrawutil.h kstyle.h kcpuinfo.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### libkdefx ##################################

kde_add_library( kdefx SHARED AUTOMOC
  SOURCES
    kpixmap.cpp kpixmapsplitter.cpp kpixmapeffect.cpp
    kimageeffect.cpp kdrawutil.cpp kstyle.cpp kcpuinfo.cpp
  VERSION 4.2.0
  LINK ${QT_LIBRARY} ${XRENDER_LIBRARIES} ${X11_LIBRARIES} ${ZLIB_LIBRARIES}
  DESTINATION ${LIB_INSTALL_DIR}
)
