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

project( kdelibs )


##### cmake setup ###############################

cmake_minimum_required( VERSION 2.8 )
include( cmake/SetupCompiler.cmake )


##### features ##################################

option( WITH_ALL_FEATURES "Enable all possible features" OFF )
option( WITH_FREETYPE "Enable freetype2 support" ${WITH_ALL_FEATURES} )
option( WITH_FONTCONFIG "Enable fontconfig support" ${WITH_ALL_FEATURES} )
option( WITH_XFT "Enable xft support" ${WITH_ALL_FEATURES} )
option( WITH_XRANDR "Enable xrandr support" ${WITH_ALL_FEATURES} )
option( WITH_XRENDER "Enable xrender support" ${WITH_ALL_FEATURES} )
option( WITH_XCOMPOSITE "Enable xcomposite support" ${WITH_ALL_FEATURES} )
option( WITH_XEXT "Enable xext support" ${WITH_ALL_FEATURES} )
option( WITH_PULSEAUDIO "Enable PulseAudio support" ${WITH_ALL_FEATURES} )
option( WITH_AUDIOFILE "Enable audiofile support (wav decoder used by PulseAudio support)" ${WITH_ALL_FEATURES} )
option( WITH_VORBIS "Enable vorbis support (PulseAudio)" ${WITH_ALL_FEATURES} )
option( WITH_LIBART "Enable libart support (for SVG icons)" ${WITH_ALL_FEATURES} )
option( WITH_LIBIDN "Enable support for libidn" ${WITH_ALL_FEATURES} )
option( WITH_CUPS "Enable CUPS support" ${WITH_ALL_FEATURES} )
option( WITH_LUA "Enable LUA support" ${WITH_ALL_FEATURES} )
option( WITH_TIFF "Enable tiff support" ${WITH_ALL_FEATURES} )
option( WITH_JASPER "Enable jasper (jpeg2k) support" ${WITH_ALL_FEATURES} )
option( WITH_OPENEXR "Enable openexr support" ${WITH_ALL_FEATURES} )
option( WITH_UTEMPTER "Use utempter for utmp management" ${WITH_ALL_FEATURES} )
option( WITH_AVAHI "Enable AVAHI support" ${WITH_ALL_FEATURES} )

option( WITH_ASPELL "Enable aspell support" ${WITH_ALL_FEATURES} )
option( WITH_HUNSPELL "Enable hunspell support" ${WITH_ALL_FEATURES} )

# this option is only for development
option( WITH_QT5 "Enable Qt5 development support" OFF )

# NOTE at this moment (Mar 8, 2012) su and sudo cannot be automatically detected
# see bug http://public.kitware.com/Bug/print_bug_page.php?bug_id=10468
if( NOT DEFINED WITH_SU_PATH )
  set( WITH_SU_PATH "/bin/su" )
endif( )
if( NOT DEFINED WITH_SUDO_PATH )
  set( WITH_SUDO_PATH "/usr/bin/sudo" )
endif( )
if( NOT DEFINED WITH_DEFAULT_SUPER_USER_COMMAND )
  set( WITH_DEFAULT_SUPER_USER_COMMAND "${WITH_SU_PATH}" )
endif( )


##### check for requirements ####################

include( ConfigureChecks.cmake )


##### components ################################

add_subdirectory( arts )
add_subdirectory( cmake )
add_subdirectory( dbus )
add_subdirectory( dcop )
add_subdirectory( dnssd )
add_subdirectory( doc )
add_subdirectory( interfaces )
add_subdirectory( kab )
add_subdirectory( kabc )
add_subdirectory( kate )
add_subdirectory( kcert )
add_subdirectory( kcmshell )
add_subdirectory( kconf_update )
add_subdirectory( kdecore )
add_subdirectory( kded )
add_subdirectory( kdefx )
add_subdirectory( kdeprint )
add_subdirectory( kdesu )
add_subdirectory( kdeui )
add_subdirectory( kdewidgets )
add_subdirectory( kdoctools )
add_subdirectory( khtml )
add_subdirectory( kimgio )
add_subdirectory( kinit )
add_subdirectory( kio )
add_subdirectory( kioslave )
add_subdirectory( kjs )
add_subdirectory( kmdi )
add_subdirectory( knewstuff )
add_subdirectory( kparts )
add_subdirectory( kresources )
add_subdirectory( kspell2 )
add_subdirectory( kstyles )
add_subdirectory( kunittest )
add_subdirectory( kutils )
add_subdirectory( kwallet )
add_subdirectory( libkscreensaver )
add_subdirectory( licenses )
add_subdirectory( mimetypes )
add_subdirectory( pics )
add_subdirectory( triq )


##### write config ##############################

configure_file( config.h.cmake config.h @ONLY )


##### install cmake modules ###############

kde_install_export( )
