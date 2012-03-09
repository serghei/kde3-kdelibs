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
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${CMAKE_SOURCE_DIR}/kjs
  ${CMAKE_SOURCE_DIR}/kutils
  ${CMAKE_SOURCE_DIR}/kdeprint
  ${CMAKE_SOURCE_DIR}/interfaces
  ${CMAKE_SOURCE_DIR}/interfaces/kregexpeditor
  ${QT_INCLUDE_DIR}
  ${LUA_INCLUDE_DIRS}
)

link_directories(
  ${LUA_LIBRARY_DIRS}
)

##### kate (static library) #####################

set( target kate )

set( ${target}_SRCS
  katesearch.cpp katebuffer.cpp katecmds.cpp
  kateundo.cpp katecursor.cpp katedialogs.cpp katedocument.cpp
  katefactory.cpp katehighlight.cpp katesyntaxdocument.cpp
  katetextline.cpp kateview.cpp kateconfig.cpp kateviewhelpers.cpp
  katecodecompletion.cpp katedocumenthelpers.cpp
  katecodefoldinghelpers.cpp kateviewinternal.cpp katebookmarks.cpp
  kateprinter.cpp katefont.cpp katelinerange.cpp katesupercursor.cpp
  katearbitraryhighlight.cpp katerenderer.cpp kateattribute.cpp
  kateautoindent.cpp katefiletype.cpp kateschema.cpp katedocument.skel
  katetemplatehandler.cpp katejscript.cpp katespell.cpp kateindentscriptabstracts.cpp
  kateluaindentscript.cpp
)

kde_add_lut( katejscript.cpp katejscript.lut.h katejscript.cpp )

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
  DEPENDENCIES dcopidl
)


##### libkatepart (module) ######################

set( target libkatepart )

configure_file( ${TEMPLATE_DUMMY_CPP} dummy.cpp COPYONLY )

kde_add_kpart( ${target}
  SOURCES dummy.cpp
  EMBED kate-static
  LINK kjs-shared kdeprint-shared katepartinterfaces-shared kutils-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
