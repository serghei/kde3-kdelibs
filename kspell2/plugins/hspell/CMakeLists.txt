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
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kspell2
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
  ${HSPELL_INCLUDE_DIRS}
)

link_directories(
  ${HSPELL_LIBARY_DIRS}
)


##### other data ################################

install( FILES kspell_hspell.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


#### kspell_hspell ##############################

### FIXME Not checked because hspell was removed from gentoo few years ago.
### FIXME The maintainer recommend to use aspell with hebrew dictionary.
### FIXME Maybe support for hspell will be removed too?
### FIXME http://bugs.gentoo.org/show_bug.cgi?id=177546

set( target kspell_hspell )

set( ${target}_SRCS
  kspell_hspellclient.cpp kspell_hspelldict.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kspell2-shared ${HSPELL_LIBRARIES}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
