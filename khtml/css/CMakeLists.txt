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
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/khtml
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kwallet/client
  ${CMAKE_SOURCE_DIR}/kutils
  ${QT_INCLUDE_DIR}
)


##### other data ################################

install( FILES html4.css quirks.css DESTINATION ${DATA_INSTALL_DIR}/khtml/css )


##### khtmlcss (static) #########################

set( target khtmlcss )

set( ${target}_SRCS
  css_stylesheetimpl.cpp css_ruleimpl.cpp css_valueimpl.cpp
  css_base.cpp cssparser.cpp cssstyleselector.cpp
  csshelper.cpp parser.cpp css_renderstyledeclarationimpl.cpp
)

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
)

