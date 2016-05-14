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

configure_file( kdemacros.h.cmake kdemacros.h @ONLY )

add_subdirectory( malloc )
add_subdirectory( network )
add_subdirectory( kconfig_compiler )

if( WITH_LIBART )
  add_subdirectory( svgicons )
  set( KDESVGICONS kdesvgicons-static )
endif( WITH_LIBART )


include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/network
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/libltdl
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${QT_INCLUDE_DIR}
  ${LIBART_INCLUDE_DIRS}
  ${LIBIDN_INCLUDE_DIRS}
)

link_directories(
  ${LIBIDN_LIBRARY_DIRS}
)


##### headers ###################################

install( FILES
    kconfig.h kconfigskeleton.h kconfigdata.h ksimpleconfig.h
    kconfigdialogmanager.h kconfigbase.h kdesktopfile.h
    kurl.h ksock.h kaboutdata.h kcmdlineargs.h kconfigbackend.h
    kapp.h kapplication.h kuniqueapp.h kuniqueapplication.h
    kcharsets.h kdeversion.h kpty.h kprocess.h kprocctrl.h
    klocale.h kicontheme.h kiconloader.h kdebug.h kwinmodule.h
    kwin.h krootprop.h kshortcut.h kkeynative.h kaccel.h
    kglobalaccel.h kstdaccel.h kshortcutlist.h kcatalogue.h
    kregexp.h kcompletion.h kstringhandler.h kstddirs.h
    kstandarddirs.h kglobal.h kglobalsettings.h ksharedptr.h
    kallocator.h kvmallocator.h kcrash.h krfcdate.h kinstance.h
    kpalette.h kipc.h klibloader.h ktempfile.h ksavefile.h
    krandomsequence.h knotifyclient.h kiconeffect.h kaudioplayer.h
    kdcoppropertyproxy.h netwm.h kaccelmanager.h netwm_def.h
    kpixmapprovider.h kunload.h kstaticdeleter.h kextsock.h
    kextendedsocket.h ksockaddr.h kprocio.h kasyncio.h kbufferedio.h
    kurldrag.h kmimesourcefactory.h kmdcodec.h ksocks.h ksycoca.h
    ksycocaentry.h ksycocatype.h kxmessages.h kstartupinfo.h
    klargefile.h kmultipledrag.h kgenericfactory.h kgenericfactory.tcc
    ktypelist.h ksortablevaluelist.h kdebugclasses.h kclipboard.h
    kcalendarsystem.h kcalendarsystemfactory.h kmacroexpander.h
    kmanagerselection.h kmountpoint.h kuser.h klockfile.h
    kidna.h ktempdir.h kshell.h fixx11h.h kxerrorhandler.h
    kdelibs_export.h kde_file.h ktimezones.h
    ${CMAKE_CURRENT_BINARY_DIR}/kdemacros.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

kde_install_empty_directory( ${LOCALE_INSTALL_DIR}/all_languages )

install( FILES 40.colors Web.colors Royal.colors Rainbow.colors
  DESTINATION ${CONFIG_INSTALL_DIR}/colors )

install( FILES kdebug.areas kdebugrc language.codes
  DESTINATION ${CONFIG_INSTALL_DIR} )

install( FILES kmdcodec_compat.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/kio RENAME kmdcodec.h )

install( FILES eventsrc
  DESTINATION ${DATA_INSTALL_DIR}/knotify )


##### libkdecore ################################

set( target kdecore )

set( ${target}_SRCS
  libintl.cpp kapplication.cpp kdebug.cpp netwm.cpp
  kconfigbase.cpp kconfig.cpp ksimpleconfig.cpp kconfigbackend.cpp
  kmanagerselection.cpp kdesktopfile.cpp kstandarddirs.cpp
  ksock.cpp kpty.cpp kprocess.cpp kprocctrl.cpp klocale.cpp
  krfcdate.cpp kiconeffect.cpp kicontheme.cpp kiconloader.cpp
  kwin.cpp kwinmodule.cpp krootprop.cpp kcharsets.cpp
  kckey.cpp kshortcut.cpp kkeynative_x11.cpp kkeyserver_x11.cpp
  kaccelaction.cpp kshortcutmenu.cpp kaccelbase.cpp kaccel.cpp
  kglobalaccel_x11.cpp kglobalaccel.cpp kstdaccel.cpp kshortcutlist.cpp
  kcrash.cpp kurl.cpp kregexp.cpp kglobal.cpp kglobalsettings.cpp
  kallocator.cpp kvmallocator.cpp kmimesourcefactory.cpp
  kinstance.cpp kpalette.cpp kipc.cpp klibloader.cpp ktempfile.cpp
  kuniqueapplication.cpp kaccelmanager.cpp ksavefile.cpp
  krandomsequence.cpp kstringhandler.cpp kcompletion.cpp
  kcmdlineargs.cpp kaboutdata.cpp kcompletionbase.cpp knotifyclient.cpp
  kaudioplayer.cpp kdcoppropertyproxy.cpp ksockaddr.cpp
  kextsock.cpp netsupp.cpp kprocio.cpp kbufferedio.cpp
  kpixmapprovider.cpp kurldrag.cpp kmdcodec.cpp ksocks.cpp
  fakes.c vsnprintf.c ksycoca.cpp ksycocadict.cpp ksycoca.skel
  ksycocafactory.cpp kxmessages.cpp kstartupinfo.cpp
  kcatalogue.cpp kasyncio.cpp kmultipledrag.cpp kstaticdeleter.cpp
  kappdcopiface.cpp kappdcopiface.skel kclipboard.cpp
  kcheckaccelerators.cpp kdeversion.cpp kdebugdcopiface.cpp
  kdebugdcopiface.skel kcalendarsystem.cpp kcalendarsystemgregorian.cpp
  kcalendarsystemhijri.cpp kcalendarsystemhebrew.cpp
  kcalendarsystemfactory.cpp kmacroexpander.cpp kidna.cpp
  ktempdir.cpp kshell.cpp kmountpoint.cpp kcalendarsystemjalali.cpp
  kprotocolinfo_kdecore.cpp kprotocolinfofactory.cpp kxerrorhandler.cpp
  kuser.cpp kconfigskeleton.cpp kconfigdialogmanager.cpp klockfile.cpp
  kqiodevicegzip_p.cpp ktimezones.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 4.2.0
  EMBED kdecorenetwork-static
  LINK dl ${KDESVGICONS} DCOP-shared kdefx-shared ${ZLIB_LIBRARIES} ${LIBIDN_LIBRARIES} ${XCOMPOSITE_LIBRARIES} ICE SM
  DEPENDENCIES dcopidl dcopidl2cpp
  DESTINATION ${LIB_INSTALL_DIR}
)


##### kdefakes_nonpic ###########################

set( target kdefakes_nonpic )

set( ${target}_SRCS
  fakes.c vsnprintf.c
)

kde_add_library( ${target} STATIC
  SOURCES ${${target}_SRCS}
  DESTINATION ${LIB_INSTALL_DIR}
)

##### kdefakes_pic ##############################

set( target kdefakes_pic )

set( ${target}_SRCS
  fakes.c vsnprintf.c
)

kde_add_library( ${target} STATIC_PIC
  SOURCES ${${target}_SRCS}
  DESTINATION ${LIB_INSTALL_DIR}
)


##### libkdefakes ###############################

set( target kdefakes )

set( ${target}_SRCS
  fakes.c vsnprintf.c
)

kde_add_library( ${target} SHARED
  SOURCES ${${target}_SRCS}
  VERSION 4.2.0
  DESTINATION ${LIB_INSTALL_DIR}
)


##### kde-config ################################

configure_file( kde-config.cpp.cmake kde-config.cpp @ONLY )

kde_add_executable( kde-config
  SOURCES ${CMAKE_CURRENT_BINARY_DIR}/kde-config.cpp
  LINK kdecore-shared
  DESTINATION ${BIN_INSTALL_DIR}
)


##### kgrantpty #################################

# FIXME there is something named KDE_USE_FPIE, I'm not sure what is this
#set_target_properties( kgrantpty PROPERTIES COMPILE_FLAGS ${KDE_USE_FPIE} )
#set_target_properties( kgrantpty PROPERTIES LINK_FLAGS ${KDE_USE_FPIE} )

kde_add_executable(kgrantpty SETUID
  SOURCES kgrantpty.c
  DESTINATION ${BIN_INSTALL_DIR}
)

##### kdetcompmgr #################################

#kde_add_executable( kdetcompmgr
#  SOURCES kdetcompmgr.cpp
#  LINK kdecore-shared
#  DESTINATION ${BIN_INSTALL_DIR}
#)
