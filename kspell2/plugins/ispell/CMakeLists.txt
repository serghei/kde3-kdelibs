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
)


##### other data ################################

install( FILES kspell_ispell.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


#### kspell_ispell ##############################

set( target kspell_ispell )

set( ${target}_SRCS
  kspell_ispellclient.cpp kspell_ispelldict.cpp
  correct.cpp good.cpp hash.cpp lookup.cpp makedent.cpp
  tgood.cpp ispell_checker.cpp
)

kde_add_kpart( ${target} AUTOMOC
  SOURCES ${${target}_SRCS}
  LINK kspell2-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
