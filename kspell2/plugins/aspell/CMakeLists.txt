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
  ${ASPELL_INCLUDE_DIR}
)


##### other data ################################

install( FILES kspell_aspell.desktop DESTINATION ${SERVICES_INSTALL_DIR} )


#### kspell_aspell ##############################

kde_add_kpart( kspell_aspell SHARED AUTOMOC
  SOURCES kspell_aspellclient.cpp kspell_aspelldict.cpp
  LINK kspell2-shared ${ASPELL_LIBRARY}
  DESTINATION ${PLUGIN_INSTALL_DIR}
)
