/* Define where aspell data dir is */
#define ASPELL_DATADIR "@WITH_ASPELL_DATADIR@"

/* Avahi API 0.6 */
#cmakedefine AVAHI_API_0_6 1

/* Define where your dcop binary is */
#define DCOP_PATH "@BIN_INSTALL_DIR@"

/* Use su or sudo */
#define DEFAULT_SUPER_USER_COMMAND "@WITH_DEFAULT_SUPER_USER_COMMAND@"

/* Define if getaddrinfo returns AF_UNIX sockets */
#undef GETADDRINFO_RETURNS_UNIX

/* getmntinfo() uses struct statvfs */
#undef GETMNTINFO_USES_STATVFS

/* Define if you have the MIT Kerberos libraries */
#undef GSSAPI_MIT

/* Define to 1 if you have `alloca', as a function or macro. */
#cmakedefine HAVE_ALLOCA 1

/* Define to 1 if you have the <alloca.h> header file. */
#cmakedefine HAVE_ALLOCA_H 1

/* Define to 1 if you have the <alsa/asoundlib.h> header file. */
#cmakedefine HAVE_ALSA_ASOUNDLIB_H 1

/* Define to 1 if you have the <arpa/nameser8_compat.h> header file. */
#cmakedefine HAVE_ARPA_NAMESER8_COMPAT_H 1

/* Define if execinfo.h exists and defines backtrace (GLIBC >= 2.1) */
#cmakedefine HAVE_BACKTRACE 1

/* Define to 1 if you have the `bcopy' function. */
#cmakedefine HAVE_BCOPY 1

/* Define if getaddrinfo is broken and should be replaced */
#cmakedefine HAVE_BROKEN_GETADDRINFO 1

/* Defines if bzip2 is compiled */
#cmakedefine HAVE_BZIP2_SUPPORT 1
#cmakedefine NEED_BZ2_PREFIX 1

/* Define to 1 if you have the <crt_externs.h> header file. */
#cmakedefine HAVE_CRT_EXTERNS_H 1

/* Defines if your system has the crypt function */
#cmakedefine HAVE_CRYPT 1

/* Define to 1 if you have the <ctype.h> header file. */
#cmakedefine HAVE_CTYPE_H 1

/* Defines if you have CUPS (Common UNIX Printing System) */
#cmakedefine HAVE_CUPS 1

/* CUPS doesn't have password caching */
#cmakedefine HAVE_CUPS_NO_PWD_CACHE 1

/* Define to 1 if you have the declaration of `getservbyname_r', and to 0 if you don't. */
#undef HAVE_DECL_GETSERVBYNAME_R

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'. */
#cmakedefine HAVE_DIRENT_H 1

/* Define if you have the GNU dld library. */
#undef HAVE_DLD

/* Define to 1 if you have the <dld.h> header file. */
#cmakedefine HAVE_DLD_H 1

/* Define to 1 if you have the `dlerror' function. */
#cmakedefine HAVE_DLERROR 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#cmakedefine HAVE_DLFCN_H 1

/* Define to 1 if you have the <dl.h> header file. */
#cmakedefine HAVE_DL_H 1

/* Define if your system has Linux Directory Notification */
#undef HAVE_DNOTIFY

/* Define if you have OpenEXR */
#cmakedefine HAVE_EXR 1

/* Define is posix_fadvise is supported */
#undef HAVE_FADVISE

/* Define if your system has libfam */
#undef HAVE_FAM

/* Define to 1 if you have the <float.h> header file. */
#cmakedefine HAVE_FLOAT_H 1

/* Define to 1 if you have the `freeaddrinfo' function. */
#cmakedefine HAVE_FREEADDRINFO 1

/* Define to 1 if you have the <fstab.h> header file. */
#cmakedefine HAVE_FSTAB_H 1

/* Define if you have finite */
#cmakedefine HAVE_FUNC_FINITE 1

/* Define if you have isinf */
#cmakedefine HAVE_FUNC_ISINF 1

/* Define if you have isnan */
#cmakedefine HAVE_FUNC_ISNAN 1

/* Define if you have _finite */
#cmakedefine HAVE_FUNC__FINITE 1

/* Define to 1 if you have the `gai_strerror' function. */
#cmakedefine HAVE_GAI_STRERROR 1

/* Define to 1 if you have the `getaddrinfo' function. */
#cmakedefine HAVE_GETADDRINFO 1

/* Define to 1 if you have the `getcwd' function. */
#cmakedefine HAVE_GETCWD 1

/* Define to 1 if you have the `getgroups' function. */
#cmakedefine HAVE_GETGROUPS 1

/* Define to 1 if you have the `gethostbyname2' function. */
#cmakedefine HAVE_GETHOSTBYNAME2 1

/* Define to 1 if you have the `gethostbyname2_r' function. */
#cmakedefine HAVE_GETHOSTBYNAME2_R 1

/* Define to 1 if you have the `gethostbyname_r' function. */
#cmakedefine HAVE_GETHOSTBYNAME_R 1

/* Define if you have gethostname */
#cmakedefine HAVE_GETHOSTNAME 1

/* Define if you have the gethostname prototype */
#cmakedefine HAVE_GETHOSTNAME_PROTO 1

/* Define to 1 if you have the `getmntinfo' function. */
#cmakedefine HAVE_GETMNTINFO 1

/* Define to 1 if you have the `getnameinfo' function. */
#cmakedefine HAVE_GETNAMEINFO 1

/* Define to 1 if you have the `getpagesize' function. */
#cmakedefine HAVE_GETPAGESIZE 1

/* Define to 1 if you have the `getpeereid' function. */
#cmakedefine HAVE_GETPEEREID 1

/* Define to 1 if you have the `getpeername' function. */
#cmakedefine HAVE_GETPEERNAME 1

/* Define to 1 if you have the `getprotobyname_r' function. */
#cmakedefine HAVE_GETPROTOBYNAME_R 1

/* Define to 1 if you have the `getpt' function. */
#cmakedefine HAVE_GETPT 1

/* Define to 1 if you have the `getservbyname_r' function. */
#cmakedefine HAVE_GETSERVBYNAME_R 1

/* Define to 1 if you have the `getservbyport_r' function. */
#cmakedefine HAVE_GETSERVBYPORT_R 1

/* Define to 1 if you have the `getsockname' function. */
#cmakedefine HAVE_GETSOCKNAME 1

/* Define to 1 if you have the `getsockopt' function. */
#cmakedefine HAVE_GETSOCKOPT 1

/* Define to 1 if you have the `gettimeofday' function. */
#cmakedefine HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the `grantpt' function. */
#cmakedefine HAVE_GRANTPT 1

/* Define to 1 if you have the <idna.h> header file. */
#cmakedefine HAVE_IDNA_H 1

/* Define to 1 if you have the <ieeefp.h> header file. */
#cmakedefine HAVE_IEEEFP_H 1

/* Define to 1 if you have the `if_nametoindex' function. */
#cmakedefine HAVE_IF_NAMETOINDEX 1

/* Define to 1 if you have the `index' function. */
#cmakedefine HAVE_INDEX 1

/* Define to 1 if you have the `inet_ntop' function. */
#cmakedefine HAVE_INET_NTOP 1

/* Define to 1 if you have the `inet_pton' function. */
#cmakedefine HAVE_INET_PTON 1

/* Define to 1 if you have the `initgroups' function. */
#cmakedefine HAVE_INITGROUPS 1

/* Define if you have the initgroups prototype */
#cmakedefine HAVE_INITGROUPS_PROTO 1

/* Define if your system has Linux Inode Notification */
#undef HAVE_INOTIFY

/* Define to 1 if you have the <inttypes.h> header file. */
#cmakedefine HAVE_INTTYPES_H 1

/* Define if you have jasper */
#cmakedefine HAVE_JASPER 1

/* Define if your locale.h file contains LC_MESSAGES */
#undef HAVE_LC_MESSAGES

/* Defines if your system has the libart library */
#cmakedefine HAVE_LIBART 1

/* Define if you have libasound.so.1 (required for ALSA 0.5.x support) */
#undef HAVE_LIBASOUND

/* Define if you have libasound.so.2 (required for ALSA 0.9.x support) */
#cmakedefine HAVE_LIBASOUND2 1

/* Define if you have the libdl library or equivalent. */
#cmakedefine HAVE_LIBDL 1

/* Define if you have GSSAPI libraries */
#undef HAVE_LIBGSSAPI

/* Defined if you have libidn in your system */
#cmakedefine HAVE_LIBIDN 1

/* Define if you have libjpeg */
#cmakedefine HAVE_LIBJPEG 1

/* Define if you have libpng */
#cmakedefine HAVE_LIBPNG 1

/* Define if you have a working libpthread (will enable threaded code) */
#cmakedefine HAVE_LIBPTHREAD 1

/* Defined if you have libthai and want to have it compiled in */
#undef HAVE_LIBTHAI

/* Define if you have libtiff */
#cmakedefine HAVE_LIBTIFF 1

/* Define to 1 if you have the <libutil.h> header file. */
#cmakedefine HAVE_LIBUTIL_H 1

/* Define if you have libz */
#cmakedefine HAVE_LIBZ 1

/* Define to 1 if you have the <limits.h> header file. */
#cmakedefine HAVE_LIMITS_H 1

/* Define to 1 if you have the <locale.h> header file. */
#cmakedefine HAVE_LOCALE_H 1

/* Define if you have LUA > 5.0 */
#cmakedefine HAVE_LUA 1

/* Define to 1 if you have the `madvise' function. */
#cmakedefine HAVE_MADVISE 1

/* Define to 1 if you have the <malloc.h> header file. */
#cmakedefine HAVE_MALLOC_H 1

/* Define to 1 if you have the `memcpy' function. */
#cmakedefine HAVE_MEMCPY 1

/* Define to 1 if you have the <memory.h> header file. */
#cmakedefine HAVE_MEMORY_H 1

/* Define if you want MIT-SHM support */
#cmakedefine HAVE_MITSHM 1

/* Define if you have mkdtemp */
#cmakedefine HAVE_MKDTEMP 1

/* Define if you have the mkdtemp prototype */
#cmakedefine HAVE_MKDTEMP_PROTO 1

/* Define if you have mkstemp */
#cmakedefine HAVE_MKSTEMP 1

/* Define if you have mkstemps */
#cmakedefine HAVE_MKSTEMPS 1

/* Define if you have the mkstemps prototype */
#cmakedefine HAVE_MKSTEMPS_PROTO 1

/* Define if you have the mkstemp prototype */
#cmakedefine HAVE_MKSTEMP_PROTO 1

/* Define to 1 if you have a working `mmap' system call. */
#cmakedefine HAVE_MMAP 1

/* Define to 1 if you have the <mntent.h> header file. */
#cmakedefine HAVE_MNTENT_H 1

/* Define to 1 if you have the `munmap' function. */
#cmakedefine HAVE_MUNMAP 1

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
#cmakedefine HAVE_NDIR_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#cmakedefine HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <net/if.h> header file. */
#cmakedefine HAVE_NET_IF_H 1

/* Define to 1 if you have the <nl_types.h> header file. */
#undef HAVE_NL_TYPES_H

/* Define if system has non-POSIX extensions to the ACL support. */
#undef HAVE_NON_POSIX_ACL_EXTENSIONS

/* Define if your system needs _NSGetEnviron to set up the environment */
#undef HAVE_NSGETENVIRON

/* Define if you have OpenSSL < 0.9.6 */
#undef HAVE_OLD_SSL_API

/* Define to 1 if you have the `openpty' function. */
#cmakedefine HAVE_OPENPTY 1

/* Define to 1 if you have the <paths.h> header file. */
#cmakedefine HAVE_PATHS_H 1

/* Define if you have pcreposix libraries and header files. */
#cmakedefine HAVE_PCREPOSIX 1

/* Define to 1 if you have the `poll' function. */
#cmakedefine HAVE_POLL 1

/* Define to 1 if the assembler supports AltiVec instructions. */
#undef HAVE_PPC_ALTIVEC

/* Define if libtool can extract symbol lists from object files. */
#undef HAVE_PRELOADED_SYMBOLS

/* Define to 1 if you have the `ptsname' function. */
#cmakedefine HAVE_PTSNAME 1

/* Define to 1 if you have the <pty.h> header file. */
#cmakedefine HAVE_PTY_H 1

/* Define to 1 if you have the <punycode.h> header file. */
#cmakedefine HAVE_PUNYCODE_H 1

/* Define to 1 if you have the `putenv' function. */
#cmakedefine HAVE_PUTENV 1

/* Define if you have random */
#cmakedefine HAVE_RANDOM 1

/* Define if you have the random prototype */
#cmakedefine HAVE_RANDOM_PROTO 1

/* Define to 1 if you have the `readdir_r' function. */
#cmakedefine HAVE_READDIR_R 1

/* Define if you have res_init */
#cmakedefine HAVE_RES_INIT 1

/* Define if you have the res_init prototype */
#cmakedefine HAVE_RES_INIT_PROTO 1

/* Define if revoke(tty) is present in unistd.h */
#cmakedefine HAVE_REVOKE 1

/* Define to 1 if you have the `rindex' function. */
#cmakedefine HAVE_RINDEX 1

/* Define if you want sendfile() support */
#cmakedefine HAVE_SENDFILE 1

/* Define to 1 if you have the `setegid' function. */
#cmakedefine HAVE_SETEGID 1

/* Define if you have setenv */
#cmakedefine HAVE_SETENV 1

/* Define if you have the setenv prototype */
#cmakedefine HAVE_SETENV_PROTO 1

/* Define to 1 if you have the `seteuid' function. */
#cmakedefine HAVE_SETEUID 1

/* Define to 1 if you have the `setfsent' function. */
#cmakedefine  HAVE_SETFSENT 1

/* Define to 1 if you have the `setgroups' function. */
#cmakedefine HAVE_SETGROUPS 1

/* Define to 1 if you have the `setlocale' function. */
#cmakedefine HAVE_SETLOCALE 1

/* Define to 1 if you have the `setmntent' function. */
#cmakedefine HAVE_SETMNTENT 1

/* Define to 1 if you have the `setpriority' function. */
#cmakedefine HAVE_SETPRIORITY 1

/* Define if you have a STL implementation by SGI */
#undef HAVE_SGI_STL

/* Define if you have the shl_load function. */
#undef HAVE_SHL_LOAD

/* if setgroups() takes short *as second arg */
#undef HAVE_SHORTSETGROUPS

/* Define if libasound has snd_pcm_resume() */
#undef HAVE_SND_PCM_RESUME

/* Define to 1 if you have the `snprintf' function. */
#cmakedefine HAVE_SNPRINTF 1

/* Define to 1 if you have the `socket' function. */
#cmakedefine HAVE_SOCKET 1

/* Define if you have srandom */
#cmakedefine HAVE_SRANDOM 1

/* Define if you have the srandom prototype */
#cmakedefine HAVE_SRANDOM_PROTO 1

/* If we are going to use OpenSSL */
#cmakedefine HAVE_SSL 1

/* Define to 1 if you have the <stdint.h> header file. */
#cmakedefine HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#cmakedefine HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#cmakedefine HAVE_STDLIB_H 1

/* Define to 1 if you have the `stpcpy' function. */
#cmakedefine HAVE_STPCPY 1

/* Define to 1 if you have the `strcasecmp' function. */
#cmakedefine HAVE_STRCASECMP 1

/* Define to 1 if you have the `strchr' function. */
#cmakedefine HAVE_STRCHR 1

/* Define to 1 if you have the `strcmp' function. */
#cmakedefine HAVE_STRCMP 1

/* Define to 1 if you have the `strfmon' function. */
#cmakedefine HAVE_STRFMON 1

/* Define to 1 if you have the <stringprep.h> header file. */
#cmakedefine HAVE_STRINGPREP_H 1

/* Define to 1 if you have the <strings.h> header file. */
#cmakedefine HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#cmakedefine HAVE_STRING_H 1

/* Define if you have strlcat */
#cmakedefine HAVE_STRLCAT 1

/* Define if you have the strlcat prototype */
#cmakedefine HAVE_STRLCAT_PROTO 1

/* Define if you have strlcpy */
#cmakedefine HAVE_STRLCPY 1

/* Define if you have the strlcpy prototype */
#cmakedefine HAVE_STRLCPY_PROTO 1

/* Define to 1 if you have the `strrchr' function. */
#cmakedefine HAVE_STRRCHR 1

/* Define to 1 if you have the `strtoll' function. */
#cmakedefine HAVE_STRTOLL 1

/* Define to 1 if the system has the type `struct addrinfo'. */
#cmakedefine HAVE_STRUCT_ADDRINFO 1

/* Define to 1 if the system has the type `struct sockaddr_in6'. */
#cmakedefine HAVE_STRUCT_SOCKADDR_IN6 1

/* Define to 1 if `sin6_scope_id' is member of `struct sockaddr_in6'. */
#undef HAVE_STRUCT_SOCKADDR_IN6_SIN6_SCOPE_ID

/* Define to 1 if `sa_len' is member of `struct sockaddr'. */
#undef HAVE_STRUCT_SOCKADDR_SA_LEN

/* Define if struct ucred is present from sys/socket.h */
#undef HAVE_STRUCT_UCRED

/* Define to 1 if you have the <sysent.h> header file. */
#cmakedefine HAVE_SYSENT_H 1

/* Define to 1 if you have the <sys/asoundlib.h> header file. */
#cmakedefine HAVE_SYS_ASOUNDLIB_H 1

/* Define to 1 if you have the <sys/bitypes.h> header file. */
#cmakedefine HAVE_SYS_BITYPES_H 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'. */
#cmakedefine HAVE_SYS_DIR_H 1

/* Define to 1 if you have the <sys/filio.h> header file. */
#cmakedefine HAVE_SYS_FILIO_H 1

/* Define if your system has glibc support for inotify */
#undef HAVE_SYS_INOTIFY

/* Define to 1 if you have the <sys/mman.h> header file. */
#cmakedefine HAVE_SYS_MMAN_H 1

/* Define to 1 if you have the <sys/mntent.h> header file. */
#cmakedefine HAVE_SYS_MNTENT_H 1

/* Define to 1 if you have the <sys/mnttab.h> header file. */
#cmakedefine HAVE_SYS_MNTTAB_H 1

/* Define to 1 if you have the <sys/mount.h> header file. */
#cmakedefine HAVE_SYS_MOUNT_H 1

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'. */
#cmakedefine HAVE_SYS_NDIR_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#cmakedefine HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/prctl.h> header file. */
#cmakedefine HAVE_SYS_PRCTL_H 1

/* Define to 1 if you have the <sys/select.h> header file. */
#cmakedefine HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/soundcard.h> header file. */
#cmakedefine HAVE_SYS_SOUNDCARD_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#cmakedefine HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/stropts.h> header file. */
#cmakedefine HAVE_SYS_STROPTS_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#cmakedefine HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#cmakedefine HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/ucred.h> header file. */
#cmakedefine HAVE_SYS_UCRED_H 1

/* Define if system has the sys/xattr.h header. */
#cmakedefine HAVE_SYS_XATTR_H 1

/* Define if sys/stat.h declares S_ISSOCK. */
#cmakedefine HAVE_S_ISSOCK 1

/* Define to 1 if you have the `tcgetattr' function. */
#cmakedefine HAVE_TCGETATTR 1

/* Define to 1 if you have the `tcsetattr' function. */
#cmakedefine HAVE_TCSETATTR 1

/* Define to 1 if you have the <termios.h> header file. */
#cmakedefine HAVE_TERMIOS_H 1

/* Define to 1 if you have the <termio.h> header file. */
#cmakedefine HAVE_TERMIO_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#cmakedefine HAVE_UNISTD_H 1

/* Define to 1 if you have the `unlockpt' function. */
#cmakedefine HAVE_UNLOCKPT 1

/* Define if you have unsetenv */
#cmakedefine HAVE_UNSETENV 1

/* Define if you have the unsetenv prototype */
#cmakedefine HAVE_UNSETENV_PROTO 1

/* Define to 1 if you have the `usleep' function. */
#cmakedefine HAVE_USLEEP 1

/* Define if you have the usleep prototype */
#cmakedefine HAVE_USLEEP_PROTO 1

/* Define if you have the utempter helper for utmp managment */
#cmakedefine HAVE_UTEMPTER 1

/* Define to 1 if you have the <util.h> header file. */
#cmakedefine HAVE_UTIL_H 1

/* Define to 1 if you have the <valgrind/memcheck.h> header file. */
#cmakedefine HAVE_VALGRIND_MEMCHECK_H 1

/* Define to 1 if you have the <values.h> header file. */
#cmakedefine HAVE_VALUES_H 1

/* Define, to enable volume management (Solaris 2.x), if you have -lvolmgt */
#undef HAVE_VOLMGT

/* Define to 1 if you have the `vsnprintf' function. */
#cmakedefine HAVE_VSNPRINTF 1

/* Define to 1 if you have the <X11/extensions/shape.h> header file. */
#cmakedefine HAVE_X11_EXTENSIONS_SHAPE_H 1

/* Define to 1 if the assembler supports 3DNOW instructions. */
#undef HAVE_X86_3DNOW

/* Define to 1 if the assembler supports MMX instructions. */
#undef HAVE_X86_MMX

/* Define to 1 if the assembler supports SSE instructions. */
#undef HAVE_X86_SSE

/* Define to 1 if the assembler supports SSE2 instructions. */
#undef HAVE_X86_SSE2

/* Defined if your system has XRender support */
#cmakedefine HAVE_XRENDER 1

/* Defined if your system has XComposite support */
#cmakedefine HAVE_XCOMPOSITE 1

/* Define to 1 if you have the `_getpty' function. */
#cmakedefine HAVE__GETPTY 1

/* The prefix to use as fallback */
#define KDEDIR "@CMAKE_INSTALL_PREFIX@"

/* Enable prevention against poor Linux OOM-killer */
#cmakedefine KDEINIT_OOM_PROTECT 1

/* Use FontConfig in kdeinit */
#cmakedefine KDEINIT_USE_FONTCONFIG 1

/* Use Xft preinitialization in kdeinit */
#cmakedefine KDEINIT_USE_XFT 1

/* Suffix for lib directories */
#define KDELIBSUFF "@KDELIBSUFF@"

/* The compiled in system configuration prefix */
#define KDESYSCONFDIR "@CONFIG_INSTALL_DIR@"

/* what C++ compiler was used for compilation */
#define KDE_COMPILER_VERSION "@KDE_COMPILER_VERSION@"

/* what OS used for compilation */
#define KDE_COMPILING_OS "@CMAKE_SYSTEM_NAME@"

/* Distribution Text to append to OS */
#define KDE_DISTRIBUTION_TEXT "@KDE_DISTRIBUTION_TEXT@"

/* Use own malloc implementation */
#cmakedefine KDE_MALLOC 1

/* Enable debugging in fast malloc */
#cmakedefine KDE_MALLOC_DEBUG 1

/* Make alloc as fast as possible */
#cmakedefine KDE_MALLOC_FULL 1

/* The libc used is glibc */
#cmakedefine KDE_MALLOC_GLIBC 1

/* The platform is x86 */
#cmakedefine KDE_MALLOC_X86 1

/* Define if we shall use KSSL */
#cmakedefine KSSL_HAVE_SSL 1

/* Define if the OS needs help to load dependent libraries for dlopen(). */
#undef LTDL_DLOPEN_DEPLIBS

/* Define to the name of the environment variable that determines the dynamic
   library search path. */
#undef LTDL_SHLIBPATH_VAR

/* Define to the extension used for shared libraries, say, ".so". */
#undef LTDL_SHLIB_EXT

/* Define to the system default library search path. */
#undef LTDL_SYSSEARCHPATH

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#undef LT_OBJDIR

/* Define the file for mount entries */
#cmakedefine MTAB_FILE "@MTAB_FILE@"

/* Define if the libbz2 functions need the BZ2_ prefix */
#cmakedefine NEED_BZ2_PREFIX 1

/* Define if dlsym() requires a leading underscode in symbol names. */
#undef NEED_USCORE

/* Name of package */
#undef PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* Define if you have POSIX.1b scheduling */
#undef POSIX1B_SCHEDULING

/* The size of `short', as computed by sizeof. */
#cmakedefine SIZEOF_SHORT @SIZEOF_SHORT@

/* The size of `size_t', as computed by sizeof. */
#cmakedefine SIZEOF_SIZE_T @SIZEOF_SIZE_T@

/* The size of `unsigned long', as computed by sizeof. */
#cmakedefine SIZEOF_UNSIGNED_LONG @SIZEOF_UNSIGNED_LONG@

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
#undef STACK_DIRECTION

/* Define to 1 if you have the ANSI C header files. */
#cmakedefine STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#cmakedefine TIME_WITH_SYS_TIME 1

/* Define if system has POSIX ACL support. */
#undef USE_POSIX_ACL

/* Version number of package */
#define VERSION "@VERSION@"

/* Defined if compiling without arts */
#cmakedefine WITHOUT_ARTS 1

/* where rgb.txt is in */
#undef X11_RGBFILE

/* Defines the executable of xmllint */
#cmakedefine XMLLINT "@XMLLINT@"

/* Defined if your system has XRandR support */
#cmakedefine XRANDR_SUPPORT 1

/*
 * jpeg.h needs HAVE_BOOLEAN, when the system uses boolean in system
 * headers and I'm too lazy to write a configure test as long as only
 * unixware is related
 */
#ifdef _UNIXWARE
#define HAVE_BOOLEAN
#endif



/*
 * AIX defines FD_SET in terms of bzero, but fails to include <strings.h>
 * that defines bzero.
 */

#if defined(_AIX)
#include <strings.h>
#endif



#if defined(HAVE_NSGETENVIRON) && defined(HAVE_CRT_EXTERNS_H)
# include <sys/time.h>
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif



#ifdef __osf__
#ifdef __cplusplus
extern "C" {
#endif
#include <sys/mount.h>
int getmntinfo(struct statfs **mntbufp, int flags);
#include <sys/fs_types.h>    /* for mnt_names[] */
#ifdef __cplusplus
}
#endif
#endif


/* Define if you need to use the GNU extensions */
#cmakedefine _GNU_SOURCE 1


#if !defined(HAVE_GETHOSTNAME_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
int gethostname (char *, unsigned int);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_INITGROUPS_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
int initgroups(const char *, gid_t);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_MKDTEMP_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
char *mkdtemp(char *);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_MKSTEMPS_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
int mkstemps(char *, int);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_MKSTEMP_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
int mkstemp(char *);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_RANDOM_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
long int random(void);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_RES_INIT_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
int res_init(void);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_SETENV_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
int setenv (const char *, const char *, int);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_SRANDOM_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
void srandom(unsigned int);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_STRLCAT_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
unsigned long strlcat(char*, const char*, unsigned long);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_STRLCPY_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
unsigned long strlcpy(char*, const char*, unsigned long);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_UNSETENV_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
void unsetenv (const char *);
#ifdef __cplusplus
}
#endif
#endif



#if !defined(HAVE_USLEEP_PROTO)
#ifdef __cplusplus
extern "C" {
#endif
int usleep (unsigned int);
#ifdef __cplusplus
}
#endif
#endif



#ifndef HAVE_S_ISSOCK
#define HAVE_S_ISSOCK
#define S_ISSOCK(mode) (1==0)
#endif



/*
 * Steven Schultz <sms at to.gd-es.com> tells us :
 * BSD/OS 4.2 doesn't have a prototype for openpty in its system header files
 */
#ifdef __bsdi__
__BEGIN_DECLS
int openpty(int *, int *, char *, struct termios *, struct winsize *);
__END_DECLS
#endif



/*
 * On HP-UX, the declaration of vsnprintf() is needed every time !
 */

#if !defined(HAVE_VSNPRINTF) || defined(hpux)
#if __STDC__
#include <stdarg.h>
#include <stdlib.h>
#else
#include <varargs.h>
#endif
#ifdef __cplusplus
extern "C"
#endif
int vsnprintf(char *str, size_t n, char const *fmt, va_list ap);
#ifdef __cplusplus
extern "C"
#endif
int snprintf(char *str, size_t n, char const *fmt, ...);
#endif


/* KDE bindir */
#define __KDE_BINDIR "@BIN_INSTALL_DIR@"

/* execprefix or NONE if not set, for libloading */
#define __KDE_EXECPREFIX "@EXEC_INSTALL_PREFIX@"

/* define to 1 if -fvisibility is supported */
#cmakedefine __KDE_HAVE_GCC_VISIBILITY 1

/* path to su */
#define __PATH_SU "@WITH_SU_PATH@"

/* path to sudo */
#define __PATH_SUDO "@WITH_SUDO_PATH@"


#if defined(__SVR4) && !defined(__svr4__)
#define __svr4__ 1
#endif


/* type to use in place of socklen_t if not defined */
#define kde_socklen_t socklen_t

/* type to use in place of socklen_t if not defined (deprecated, use kde_socklen_t) */
#define ksize_t kde_socklen_t

/* Define to `long int' if <sys/types.h> does not define. */
#undef off_t

/* Define to `unsigned int' if <sys/types.h> does not define. */
#undef size_t


/* provide a definition for a 32 bit entity, usable as a typedef, possibly
   extended by "unsigned" */
#undef INT32_BASETYPE
#ifdef SIZEOF_INT
#if SIZEOF_INT == 4
#define INT32_BASETYPE int
#endif
#endif
#if !defined(INT32_BASETYPE) && defined(SIZEOF_LONG)
#if SIZEOF_LONG == 4
#define INT32_BASETYPE long
#endif
#endif
#ifndef INT32_BASETYPE
#define INT32_BASETYPE int
#endif

#ifndef HAVE_SETEUID
#define HAVE_SETEUID
#define HAVE_SETEUID_FAKE
#ifdef __cplusplus
extern "C"
#endif
int seteuid(INT32_BASETYPE euid); /* defined in fakes.c */
#endif
