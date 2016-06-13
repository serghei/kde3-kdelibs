#################################################
#
#  (C) 2016 Serghei Amelian
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
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)

kde_moc( MOCS test_dbus.cpp )

kde_add_executable( test_dbus AUTOMOC
    SOURCES test_dbus.cpp test_dbus.skel
  LINK DCOP-shared
)
