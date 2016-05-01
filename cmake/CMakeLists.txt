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

configure_file( FindKDE3.cmake.cmake FindKDE3.cmake @ONLY )

install( FILES
    FindQt3.cmake ${CMAKE_CURRENT_BINARY_DIR}/FindKDE3.cmake KDE3Macros.cmake
    SetupCompiler.cmake template_export_library.cmake template_kdeinit_module.cmake
    template_dummy_cpp.cmake template_kdeinit_executable.cmake
    template_libtool_file.cmake uic.cmake
  DESTINATION ${CMAKE_INSTALL_DIR} )
