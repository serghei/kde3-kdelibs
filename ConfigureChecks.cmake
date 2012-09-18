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

include( CheckCSourceCompiles )
include( CheckCXXCompilerFlag )
include( CheckFunctionExists )
include( CheckIncludeFile )
include( CheckLibraryExists )
include( CheckSymbolExists )
include( CheckTypeSize )
include( FindPkgConfig )

set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )
include( ${CMAKE_SOURCE_DIR}/cmake/KDE3Macros.cmake )
include( ${CMAKE_SOURCE_DIR}/cmake/SetupPaths.cmake )


##### check for compiler capabilities ###########

if( NOT COMPILER_CHECKED )
  message( "\n** Checking for compiler capabilities..." )
  set( COMPILER_CHECKED 1 CACHE INTERNAL "" )
endif( )

check_cxx_compiler_flag( -fvisibility __KDE_HAVE_GCC_VISIBILITY )

check_cxx_compiler_flag( -Woverloaded-virtual WOVERLOADED_VIRTUAL )
if( WOVERLOADED_VIRTUAL )
  set( WOVERLOADED_VIRTUAL -Woverloaded-virtual CACHE INTERNAL "" )
endif( )

check_cxx_compiler_flag( -fno-builtin NO_BUILTIN )
if( NO_BUILTIN )
  set( NO_BUILTIN -fno-builtin CACHE INTERNAL "" )
endif( NO_BUILTIN )

check_c_source_compiles("
  #include <features.h>
  #ifndef __GNU_LIBRARY__
  #error
  #endif
  int main(int argc, char *argv[]) { return 0; } "
  _GNU_SOURCE )

# currently I think is sane to assume that is true (at least on GNU/Linux)
set( STDC_HEADERS 1 CACHE INTERNAL "" )

# we really want to use kde's malloc?
set( KDE_MALLOC_GLIBC 1 CACHE INTERNAL "" )


##### check of include files ####################

if( NOT HEADERS_CHECKED )
  message( "\n** Checking for header files..." )
  set( HEADERS_CHECKED 1 CACHE INTERNAL "" )
endif( )
check_include_file( "alloca.h" HAVE_ALLOCA_H )
check_include_file( "arpa/nameser8_compat.h" HAVE_ARPA_NAMESER8_COMPAT_H )
check_include_file( "crt_externs.h" HAVE_CRT_EXTERNS_H )
check_include_file( "ctype.h" HAVE_CTYPE_H )
check_include_file( "dirent.h" HAVE_DIRENT_H )
check_include_file( "dld.h" HAVE_DLD_H )
check_include_file( "dl.h" HAVE_DL_H )
check_include_file( "execinfo.h" HAVE_EXECINFO_H )
check_include_file( "float.h" HAVE_FLOAT_H )
check_include_file( "fstab.h" HAVE_FSTAB_H )
check_include_file( "ieeefp.h" HAVE_IEEEFP_H )
check_include_file( "inttypes.h" HAVE_INTTYPES_H )
check_include_file( "libutil.h" HAVE_LIBUTIL_H )
check_include_file( "limits.h" HAVE_LIMITS_H )
check_include_file( "locale.h" HAVE_LOCALE_H )
check_include_file( "malloc.h" HAVE_MALLOC_H )
check_include_file( "memory.h" HAVE_MEMORY_H )
check_include_file( "mntent.h" HAVE_MNTENT_H )
check_include_file( "ndir.h" HAVE_NDIR_H )
check_include_file( "net/if.h" HAVE_NET_IF_H )
check_include_file( "netinet/in.h" HAVE_NETINET_IN_H )
check_include_file( "paths.h" HAVE_PATHS_H )
check_include_file( "pthread.h" HAVE_LIBPTHREAD )
check_include_file( "pty.h" HAVE_PTY_H )
check_include_file( "stdint.h" HAVE_STDINT_H )
check_include_file( "stdio.h" HAVE_STDIO_H )
check_include_file( "stdlib.h" HAVE_STDLIB_H )
check_include_file( "string.h" HAVE_STRING_H )
check_include_file( "strings.h" HAVE_STRINGS_H )
check_include_file( "sys/bitypes.h" HAVE_SYS_BITYPES_H )
check_include_file( "sys/dir.h" HAVE_SYS_DIR_H )
check_include_file( "sysent.h" HAVE_SYSENT_H )
check_include_file( "sys/filio.h" HAVE_SYS_FILIO_H )
check_include_file( "sys/mman.h" HAVE_SYS_MMAN_H )
check_include_file( "sys/mntent.h" HAVE_SYS_MNTENT_H )
check_include_file( "sys/mnttab.h" HAVE_SYS_MNTTAB_H )
check_include_file( "sys/mount.h" HAVE_SYS_MOUNT_H )
check_include_file( "sys/ndir.h" HAVE_SYS_NDIR_H )
check_include_file( "sys/param.h" HAVE_SYS_PARAM_H )
check_include_file( "sys/prctl.h" HAVE_SYS_PRCTL_H )
check_include_file( "sys/select.h" HAVE_SYS_SELECT_H )
check_include_file( "sys/soundcard.h" HAVE_SYS_SOUNDCARD_H )
check_include_file( "sys/stat.h" HAVE_SYS_STAT_H )
check_include_file( "sys/stropts.h" HAVE_SYS_STROPTS_H )
check_include_file( "sys/time.h" HAVE_SYS_TIME_H )
check_include_file( "sys/types.h" HAVE_SYS_TYPES_H )
check_include_file( "sys/ucred.h" HAVE_SYS_UCRED_H )
check_include_file( "sys/xattr.h" SYS_XATTR_H )
check_include_file( "termio.h" HAVE_TERMIO_H )
check_include_file( "termios.h" HAVE_TERMIOS_H )
check_include_file( "time.h" HAVE_TIME_H )
check_include_file( "unistd.h" HAVE_UNISTD_H )
check_include_file( "util.h" HAVE_UTIL_H )
check_include_file( "valgrind/memcheck.h" HAVE_VALGRIND_MEMCHECK_H )
check_include_file( "values.h" HAVE_VALUES_H )
check_include_file( "X11/extensions/shape.h" HAVE_X11_EXTENSIONS_SHAPE_H )

# FIXME should be implemented a real check for this
if( HAVE_TIME_H AND HAVE_SYS_TIME_H )
  set( TIME_WITH_SYS_TIME 1 CACHE INTERNAL "" )
endif( )


##### check for standard functions ##############

if( NOT STDFUNC_CHECKED )
  message( "\n** Checking for standard functions..." )
  set( STDFUNC_CHECKED 1 CACHE INTERNAL "" )
endif( )
check_function_exists( alloca HAVE_ALLOCA )
check_function_exists( bcopy HAVE_BCOPY )
check_function_exists( _finite HAVE_FUNC__FINITE )
check_function_exists( finite HAVE_FUNC_FINITE )
check_function_exists( freeaddrinfo HAVE_FREEADDRINFO )
check_function_exists( getcwd HAVE_GETCWD )
check_function_exists( getgroups HAVE_GETGROUPS )
check_function_exists( gethostname HAVE_GETHOSTNAME )
check_function_exists( getmntinfo HAVE_GETMNTINFO )
check_function_exists( getnameinfo HAVE_GETNAMEINFO )
check_function_exists( getpagesize HAVE_GETPAGESIZE )
check_function_exists( getpeereid HAVE_GETPEEREID )
check_function_exists( getpeername HAVE_GETPEERNAME )
check_function_exists( getprotobyname_r HAVE_GETPROTOBYNAME_R )
check_function_exists( getpt HAVE_GETPT )
check_function_exists( _getpty HAVE__GETPTY )
check_function_exists( getservbyname_r HAVE_GETSERVBYNAME_R )
check_function_exists( getservbyport_r HAVE_GETSERVBYPORT_R )
check_function_exists( getsockname HAVE_GETSOCKNAME )
check_function_exists( getsockopt HAVE_GETSOCKOPT )
check_function_exists( gettimeofday HAVE_GETTIMEOFDAY )
check_function_exists( grantpt HAVE_GRANTPT )
check_function_exists( if_nametoindex HAVE_IF_NAMETOINDEX )
check_function_exists( index HAVE_INDEX)
check_function_exists( inet_ntop HAVE_INET_NTOP )
check_function_exists( inet_pton HAVE_INET_PTON )
check_function_exists( initgroups HAVE_INITGROUPS )
check_function_exists( isinf HAVE_FUNC_ISINF )
check_function_exists( isnan HAVE_FUNC_ISNAN )
check_function_exists( madvise HAVE_MADVISE )
check_function_exists( memcpy HAVE_MEMCPY )
check_function_exists( mkdtemp HAVE_MKDTEMP )
check_function_exists( mkstemp HAVE_MKSTEMP )
check_function_exists( mkstemps HAVE_MKSTEMPS )
check_function_exists( mmap HAVE_MMAP )
check_function_exists( munmap HAVE_MUNMAP )
check_function_exists( poll HAVE_POLL )
check_function_exists( ptsname HAVE_PTSNAME )
check_function_exists( putenv HAVE_PUTENV )
check_function_exists( random HAVE_RANDOM )
check_function_exists( readdir_r HAVE_READDIR_R )
check_function_exists( revoke HAVE_REVOKE )
check_function_exists( rindex HAVE_RINDEX )
check_function_exists( sendfile HAVE_SENDFILE )
check_function_exists( setegid HAVE_SETEGID )
check_function_exists( setenv HAVE_SETENV )
check_function_exists( seteuid HAVE_SETEUID )
check_function_exists( setfsent HAVE_SETFSENT )
check_function_exists( setgroups HAVE_SETGROUPS )
check_function_exists( setlocale HAVE_SETLOCALE )
check_function_exists( setmntent HAVE_SETMNTENT )
check_function_exists( setpriority HAVE_SETPRIORITY )
check_function_exists( snprintf HAVE_SNPRINTF )
check_function_exists( socket HAVE_SOCKET )
check_function_exists( srandom HAVE_SRANDOM )
check_function_exists( stpcpy HAVE_STPCPY )
check_function_exists( strcasecmp HAVE_STRCASECMP )
check_function_exists( strchr HAVE_STRCHR )
check_function_exists( strcmp HAVE_STRCMP )
check_function_exists( strfmon HAVE_STRFMON )
check_function_exists( strlcat HAVE_STRLCAT )
check_function_exists( strlcpy HAVE_STRLCPY )
check_function_exists( strrchr HAVE_STRRCHR )
check_function_exists( strtoll HAVE_STRTOLL )
check_function_exists( tcgetattr HAVE_TCGETATTR )
check_function_exists( tcsetattr HAVE_TCSETATTR )
check_function_exists( unlockpt HAVE_UNLOCKPT )
check_function_exists( unsetenv HAVE_UNSETENV )
check_function_exists( usleep HAVE_USLEEP )
check_function_exists( vsnprintf HAVE_VSNPRINTF )

# backtrace
if( HAVE_EXECINFO_H )
  check_function_exists( backtrace HAVE_BACKTRACE )
endif( )

# dl
kde_save_and_set( CMAKE_REQUIRED_LIBRARIES dl )
check_function_exists( dlerror HAVE_DLERROR )
kde_restore( )

# crypt
kde_save_and_set( CMAKE_REQUIRED_LIBRARIES crypt )
check_function_exists( crypt HAVE_CRYPT )
kde_restore( )

# openpty
kde_save_and_set( CMAKE_REQUIRED_LIBRARIES util )
check_function_exists( openpty HAVE_OPENPTY )
kde_restore( )

# res_init
kde_save_and_set( CMAKE_REQUIRED_LIBRARIES resolv )
check_function_exists( __res_init HAVE_RES_INIT )
if( HAVE_RES_INIT )
  set( RESOLV_LIBRARY resolv CACHE INTERNAL "" )
endif( )
kde_restore( )


##### check for symbols #########################

if( NOT PROTO_CHECKED )
  message( "\n** Checking for prototypes..." )
  set( PROTO_CHECKED 1 CACHE INTERNAL "" )
endif( )
check_symbol_exists( gai_strerror "sys/types.h;sys/socket.h;netdb.h" HAVE_GAI_STRERROR )
check_symbol_exists( getaddrinfo "sys/types.h;sys/socket.h;netdb.h" HAVE_GETADDRINFO )
check_symbol_exists( gethostbyname2 "netdb.h" HAVE_GETHOSTBYNAME2 )
check_symbol_exists( gethostbyname2_r "netdb.h" HAVE_GETHOSTBYNAME2_R )
check_symbol_exists( gethostbyname_r "netdb.h" HAVE_GETHOSTBYNAME_R )
check_symbol_exists( gethostname "unistd.h" HAVE_GETHOSTNAME_PROTO )
check_symbol_exists( initgroups "grp.h" HAVE_INITGROUPS_PROTO )
check_symbol_exists( mkdtemp "stdlib.h" HAVE_MKDTEMP_PROTO )
check_symbol_exists( mkstemps "stdlib.h" HAVE_MKSTEMPS_PROTO )
check_symbol_exists( mkstemp "stdlib.h" HAVE_MKSTEMP_PROTO )
check_symbol_exists( random "stdlib.h" HAVE_RANDOM_PROTO )
check_symbol_exists( res_init "resolv.h" HAVE_RES_INIT_PROTO )
check_symbol_exists( setenv "stdlib.h" HAVE_SETENV_PROTO )
check_symbol_exists( S_ISSOCK "sys/stat.h" HAVE_S_ISSOCK )
check_symbol_exists( srandom "stdlib.h" HAVE_SRANDOM_PROTO )
check_symbol_exists( strlcat "string.h" HAVE_STRLCAT_PROTO )
check_symbol_exists( strlcpy "string.h" HAVE_STRLCPY_PROTO )
check_symbol_exists( unsetenv "stdlib.h" HAVE_UNSETENV_PROTO )
check_symbol_exists( usleep "unistd.h" HAVE_USLEEP_PROTO )


##### check for structs #########################

if( NOT STRUCTS_CHECKED )
  message( "\n** Checking for structs..." )
  set( STRUCTS_CHECKED 1 CACHE INTERNAL "" )
endif( )

set( CMAKE_EXTRA_INCLUDE_FILES "netdb.h" )
check_type_size( "struct addrinfo" STRUCT_ADDRINFO )
set( CMAKE_EXTRA_INCLUDE_FILES "netinet/in.h" )
check_type_size( "struct sockaddr_in6" HAVE_STRUCT_SOCKADDR_IN6 )
unset( CMAKE_EXTRA_INCLUDE_FILES )


##### processing requirements ###################

if( NOT REQUIREMENTS_CHECKED )
  message( "\n** Checking for requirements..." )
  set( REQUIREMENTS_CHECKED 1 CACHE INTERNAL "" )
endif( )

# operating system
if( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
  set( KDEINIT_SETUID 1 CACHE INTERNAL "" )
  set( KDEINIT_OOM_PROTECT 1 CACHE INTERNAL "" )
endif( )

# openssl
kde_search_module( SSL openssl )
set( KSSL_HAVE_SSL 1 )

# libdl
kde_search_library( DL_LIBRARY dlfcn.h dl )
if( DL_LIBRARY )
  set( HAVE_LIBDL 1 CACHE INTERNAL "" )
endif( )

# pthread
find_library( PTHREAD_LIBRARY pthread )
if( NOT PTHREAD_LIBRARY )
  kde_message_fatal( "pthread library is required, but was not found on your system" )
endif( )

kde_search_module( X11 x11 )
kde_search_module( DBUS dbus-1 )
kde_search_module( LIBXML2 libxml-2.0 )
kde_search_module( LIBXSLT libxslt )

# pcre
kde_search_library( PCRE_LIBRARY pcre.h pcre )
if( PCRE_LIBRARY )
  set( HAVE_PCREPOSIX 1 CACHE INTERNAL "" )
endif( )

# zlib
kde_search_module( ZLIB zlib )
set( HAVE_LIBZ 1 CACHE INTERNAL "" )

# bzip2
kde_search_library( BZIP2_LIBRARY bzlib.h bz2 )
check_library_exists( ${BZIP2_LIBRARY} BZ2_bzCompressInit "" NEED_BZ2_PREFIX )
set( HAVE_BZIP2_SUPPORT 1 )

# libpng
kde_search_module( PNG libpng )

# libjpeg
kde_save_and_set( CMAKE_REQUIRED_FLAGS "-include sys/types.h -include stdio.h" )
kde_search_library( JPEG_LIBRARY jpeglib.h jpeg )
kde_restore( CMAKE_REQUIRED_FLAGS )
set( HAVE_LIBJPEG 1 )

# jasper
if( WITH_JASPER )
  kde_search_library( JASPER_LIBRARY jasper/jasper.h jasper )
  set( HAVE_JASPER 1 CACHE INTERNAL "" )
endif( )

# openxr
if( WITH_OPENEXR )
  kde_search_module( OPENEXR OpenEXR )
  set( HAVE_EXR 1 CACHE INTERNAL "" )
endif( )

# libtiff
if( WITH_TIFF )
  kde_search_module( TIFF libtiff-4 )
  set( HAVE_LIBTIFF 1 CACHE INTERNAL "" )
endif( )

# cups
if( WITH_CUPS )
  kde_search_config( CUPS cups )
  set( HAVE_CUPS_NO_PWD_CACHE 1 CACHE INTERNAL "" )
endif( )

kde_conditional_search_module( ${WITH_LIBART} LIBART libart-2.0 )
kde_conditional_search_module( ${WITH_FREETYPE} FREETYPE freetype2 )

# fontconfig
if( WITH_FONTCONFIG )
  kde_search_module( FONTCONFIG fontconfig )
  set( KDEINIT_USE_FONTCONFIG 1 CACHE INTERNAL "" )
endif( )

# xft
if( WITH_XFT )
  kde_search_module( XFT xft )
  set( KDEINIT_USE_XFT 1 CACHE INTERNAL "" )
endif( )

# xrandr
if( WITH_XRANDR )
  kde_search_module( XRANDR xrandr )
  set( XRANDR_SUPPORT 1 CACHE INTERNAL "" )
endif( )

# xext
if( WITH_XEXT )
  kde_search_module( XEXT xext )
  kde_save_and_set( CMAKE_REQUIRED_FLAGS "-include X11/Xlib.h" )
  check_include_file( "X11/extensions/XShm.h" HAVE_MITSHM )
  kde_restore( CMAKE_REQUIRED_FLAGS )
endif( )

kde_conditional_search_module( ${WITH_XRENDER} XRENDER xrender )
kde_conditional_search_module( ${WITH_XCOMPOSITE} XCOMPOSITE xcomposite )

# aspell
if( WITH_ASPELL )
  kde_search_library( ASPELL_LIBRARY aspell.h aspell )
  # WITH_ASPELL_DATADIR is not set, so try to detect it automatically
  if( NOT DEFINED WITH_ASPELL_DATADIR )
    find_program( __pspell_config pspell-config )
    if( NOT __pspell_config )
      kde_message_notfound( "${__pspell_config}" )
    endif( )
    execute_process(
        COMMAND ${__pspell_config} --pkgdatadir
        RESULT_VARIABLE __result
        OUTPUT_VARIABLE WITH_ASPELL_DATADIR
        OUTPUT_STRIP_TRAILING_WHITESPACE )
    if( __result )
      kde_message_fatal( "Unable to run ${__pspell_config}" )
    endif( )
  endif( )
endif( )

# hunspell
if( WITH_HUNSPELL )
  # kde_search_module( HUNSPELL hunspell )
  kde_message_fatal( "hunspell support is not ready yet" )
endif( )

# libidn
if( WITH_LIBIDN )
  kde_search_module( LIBIDN libidn )
  check_include_file( "idna.h" HAVE_IDNA_H )
  check_include_file( "punycode.h" HAVE_PUNYCODE_H )
  check_include_file( "stringprep.h" HAVE_STRINGPREP_H )
endif( )

# utempter
if( WITH_UTEMPTER )
  kde_search_library( UTEMPTER_LIBRARY utempter.h utempter )
  set( HAVE_UTEMPTER 1 CACHE INTERNAL "" )
endif( )

# alsa
if( WITH_ALSA )
  kde_search_module( ALSA alsa )
  check_include_file( alsa/asoundlib.h HAVE_ALSA_ASOUNDLIB_H )
  if( NOT HAVE_ALSA_ASOUNDLIB_H )
    check_include_file( "sys/asoundlib.h" HAVE_SYS_ASOUNDLIB_H )
  endif( )
  find_library( ASOUND_LIBRARY asound )
  if( NOT ASOUND_LIBRARY )
    kde_message_fatal( "libasound.so.2 is required, but was not found on your system" )
  endif( )
  check_library_exists( ${ASOUND_LIBRARY} snd_pcm_resume "" HAVE_SND_PCM_RESUME )
  set( HAVE_LIBASOUND2 1 CACHE INTERNAL "" )
  set( ALSA_PCM_OLD_SW_PARAMS_API 1 CACHE INTERNAL "" )
  set( ALSA_PCM_OLD_HW_PARAMS_API 1 CACHE INTERNAL "" )
endif( )

# arts
if( WITH_ARTS )
  kde_search_module( GLIB2 glib-2.0 )
  kde_search_module( GTHREAD2 gthread-2.0 )
  kde_conditional_search_module( ${WITH_AUDIOFILE} AUDIOFILE audiofile )
else( )
  set( WITHOUT_ARTS 1 )
endif( )

# Qt3
include( FindQt3 )


##### check for system things ###################

# mtab
foreach( _file "/etc/mtab" "/etc/mnttab" )
  if( EXISTS ${_file} )
    set( MTAB_FILE ${_file} CACHE INTERNAL "" )
    break( )
  endif( )
endforeach( )

find_program( XMLLINT xmllint )


##### global compiler settings ##################

add_definitions( -DHAVE_CONFIG_H )
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--disable-new-dtags" )
set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined -Wl,--disable-new-dtags" )
set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--no-undefined -Wl,--disable-new-dtags" )


##### internal tools ############################

set( KDE_MCOPIDL_EXECUTABLE "${CMAKE_BINARY_DIR}/arts/arts/mcopidl/mcopidl" )
set( KDE_DBUSXML2QT3_EXECUTABLE "${CMAKE_BINARY_DIR}/dbus/dbusxml2qt3/dbusxml2qt3" )
set( KDE_DCOPIDL_EXECUTABLE "${CMAKE_BINARY_DIR}/dcop/dcopidl/dcopidl" )
set( KDE_DCOPIDL2CPP_EXECUTABLE "${CMAKE_BINARY_DIR}/dcop/dcopidl2cpp/dcopidl2cpp" )
set( KDE_KCFGC_EXECUTABLE "${CMAKE_BINARY_DIR}/kdecore/kconfig_compiler/kconfig_compiler" )
set( KDE_MEINPROC_EXECUTABLE "${CMAKE_BINARY_DIR}/kdoctools/meinproc" )


##### cmake templates ###########################

set( TEMPLATE_DUMMY_CPP "${CMAKE_SOURCE_DIR}/cmake/template_dummy_cpp.cmake" )
set( TEMPLATE_EXPORT_LIBRARY "${CMAKE_SOURCE_DIR}/cmake/template_export_library.cmake" )
set( TEMPLATE_KDEINIT_EXECUTABLE "${CMAKE_SOURCE_DIR}/cmake/template_kdeinit_executable.cmake" )
set( TEMPLATE_KDEINIT_MODULE "${CMAKE_SOURCE_DIR}/cmake/template_kdeinit_module.cmake" )
set( TEMPLATE_LIBTOOL_FILE "${CMAKE_SOURCE_DIR}/cmake/template_libtool_file.cmake" )


##### processing CMakeLists.txt #################

message( "\n** Processing CMakeLists.txt files..." )
