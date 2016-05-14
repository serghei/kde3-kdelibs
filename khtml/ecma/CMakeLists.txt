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
  ${CMAKE_BINARY_DIR}/kjs
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/khtml
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/bookmarks
  ${CMAKE_SOURCE_DIR}/kjs
  ${CMAKE_SOURCE_DIR}/kwallet/client
  ${CMAKE_SOURCE_DIR}/kutils
  ${QT_INCLUDE_DIR}
)


##### kjs_html-static ###########################

set( target kjs_html )

set( ${target}_SRCS
  kjs_binding.cpp kjs_dom.cpp kjs_html.cpp kjs_window.cpp
  kjs_navigator.cpp kjs_proxy.cpp kjs_css.cpp
  kjs_range.cpp kjs_traversal.cpp kjs_events.cpp
  kjs_views.cpp kjs_debugwin.cpp kjs_mozilla.cpp
  xmlhttprequest.cpp xmlserializer.cpp domparser.cpp
)

set( ${target}_LUTS
  kjs_dom.cpp kjs_html.cpp kjs_css.cpp kjs_events.cpp
  kjs_navigator.cpp kjs_mozilla.cpp kjs_range.cpp
  kjs_traversal.cpp kjs_views.cpp kjs_window.cpp
  xmlhttprequest.cpp xmlserializer.cpp domparser.cpp
)

kde_add_luts( ${${target}_LUTS} )

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
)

