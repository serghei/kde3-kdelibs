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

# install paths
set( EXEC_INSTALL_PREFIX       "@EXEC_INSTALL_PREFIX@" )
set( SHARE_INSTALL_PREFIX      "@SHARE_INSTALL_PREFIX@" )
set( BIN_INSTALL_DIR           "@BIN_INSTALL_DIR@" )
set( SBIN_INSTALL_DIR          "@SBIN_INSTALL_DIR@" )
set( LIB_INSTALL_DIR           "@LIB_INSTALL_DIR@" )
set( LIBEXEC_INSTALL_DIR       "@LIBEXEC_INSTALL_DIR@" )
set( INCLUDE_INSTALL_DIR       "@INCLUDE_INSTALL_DIR@" )
set( CMAKE_INSTALL_DIR         "@CMAKE_INSTALL_DIR@" )
set( PLUGIN_INSTALL_DIR        "@PLUGIN_INSTALL_DIR@" )
set( CONFIG_INSTALL_DIR        "@CONFIG_INSTALL_DIR@" )
set( DATA_INSTALL_DIR          "@DATA_INSTALL_DIR@" )
set( HTML_INSTALL_DIR          "@HTML_INSTALL_DIR@" )
set( ICON_INSTALL_DIR          "@ICON_INSTALL_DIR@" )
set( KCFG_INSTALL_DIR          "@KCFG_INSTALL_DIR@" )
set( LOCALE_INSTALL_DIR        "@LOCALE_INSTALL_DIR@" )
set( APPS_INSTALL_DIR          "@APPS_INSTALL_DIR@" )
set( MIME_INSTALL_DIR          "@MIME_INSTALL_DIR@" )
set( SERVICES_INSTALL_DIR      "@SERVICES_INSTALL_DIR@" )
set( SERVICETYPES_INSTALL_DIR  "@SERVICETYPES_INSTALL_DIR@" )
set( SOUND_INSTALL_DIR         "@SOUND_INSTALL_DIR@" )
set( TEMPLATES_INSTALL_DIR     "@TEMPLATES_INSTALL_DIR@" )
set( WALLPAPER_INSTALL_DIR     "@WALLPAPER_INSTALL_DIR@" )
set( KCONF_UPDATE_INSTALL_DIR  "@KCONF_UPDATE_INSTALL_DIR@" )
set( AUTOSTART_INSTALL_DIR     "@AUTOSTART_INSTALL_DIR@" )
set( SYSCONF_INSTALL_DIR       "@SYSCONF_INSTALL_DIR@" )
set( MAN_INSTALL_DIR           "@MAN_INSTALL_DIR@" )
set( INFO_INSTALL_DIR          "@INFO_INSTALL_DIR@" )
set( XDG_MENU_INSTALL_DIR      "@XDG_MENU_INSTALL_DIR@" )
set( XDG_APPS_INSTALL_DIR      "@XDG_APPS_INSTALL_DIR@" )
set( XDG_DIRECTORY_INSTALL_DIR "@XDG_DIRECTORY_INSTALL_DIR@" )
set( XDG_MIME_INSTALL_DIR      "@XDG_MIME_INSTALL_DIR@" )

# path to cmake modules
set( CMAKE_MODULE_PATH "${CMAKE_INSTALL_DIR}" )
include( "${CMAKE_INSTALL_DIR}/KDE3Macros.cmake" )
include( "${CMAKE_INSTALL_DIR}/kdelibs.cmake" )

# path to cmake templates
set( TEMPLATE_DUMMY_CPP "${CMAKE_MODULE_PATH}/template_dummy_cpp.cmake" )
set( TEMPLATE_EXPORT_LIBRARY "${CMAKE_MODULE_PATH}/template_export_library.cmake" )
set( TEMPLATE_KDEINIT_EXECUTABLE "${CMAKE_MODULE_PATH}/template_kdeinit_executable.cmake" )
set( TEMPLATE_KDEINIT_MODULE "${CMAKE_MODULE_PATH}/template_kdeinit_module.cmake" )
set( TEMPLATE_LIBTOOL_FILE "${CMAKE_MODULE_PATH}/template_libtool_file.cmake" )

# find Qt3
include( "${CMAKE_INSTALL_DIR}/FindQt3.cmake" )

# kde3 macros
include( "${CMAKE_INSTALL_DIR}/KDE3Macros.cmake" )

# paths to kde3 tools
set( KDE_CONFIG_EXECUTABLE "${BIN_INSTALL_DIR}/kde-config" )
set( KDE_DCOPIDL_EXECUTABLE "${BIN_INSTALL_DIR}/dcopidl" )
set( KDE_DCOPIDLNG_EXECUTABLE "${BIN_INSTALL_DIR}/dcopidlng" )
set( KDE_DCOPIDL2CPP_EXECUTABLE "${BIN_INSTALL_DIR}/dcopidl2cpp" )
set( KDE_KCFGC_EXECUTABLE "${BIN_INSTALL_DIR}/kconfig_compiler" )
set( KDE_MEINPROC_EXECUTABLE "${BIN_INSTALL_DIR}/meinproc" )
set( KDE_MAKEKDEWIDGETS_EXECUTABLE "${BIN_INSTALL_DIR}/makekdewidgets" )

# default c++ flags
add_definitions( -DHAVE_CONFIG_H )
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--disable-new-dtags" )
set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined -Wl,--disable-new-dtags" )
set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined -Wl,--disable-new-dtags" )

# paths to kde
set( KDE_INCLUDE_DIR "${INCLUDE_INSTALL_DIR}" )
set( KDE_LIBRARY_DIR "${LIB_INSTALL_DIR}" )
set( KDE_LIBRARY_DIR "${LIB_INSTALL_DIR}" )
