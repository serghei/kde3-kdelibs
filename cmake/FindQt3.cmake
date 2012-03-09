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

##### check for qt3 #############################

# priority:
#  1. QT_INCLUDE_DIR, QT_LIBRARY, QT_LIBRARY_DIR, QT_MOC_EXECUTABLE, QT_UIC_EXECUTABLE, QT_BINARY_DIR
#  2. QT_PREFIX_DIR
#  3. QTDIR (environment)

if( NOT DEFINED QT_VERSION )

  message( "\n** Checking for Qt3..." )



  if( NOT QT_PREFIX_DIR )
    set( QT_PREFIX_DIR "$ENV{QTDIR}" )
    if( QT_PREFIX_DIR )
      set( QT_PREFIX_DIR_MSG "${QT_PREFIX_DIR} (from QTDIR)" )
    else( )
      set( QT_PREFIX_DIR_MSG "is not set" )
    endif( )
  endif( )



  if( QT_PREFIX_DIR )
    if( NOT DEFINED QT_BINARY_DIR )
      set( QT_BINARY_DIR "${QT_PREFIX_DIR}/bin" )
    endif( )
    if( NOT DEFINED QT_INCLUDE_DIR )
      set( QT_INCLUDE_DIR "${QT_PREFIX_DIR}/include" )
    endif( )
    if( NOT DEFINED QT_LIBRARY_DIR )
      set( QT_LIBRARY_DIR "${QT_PREFIX_DIR}/lib${LIB_SUFFIX}" CACHE PATH "" )
    endif( )
    if( NOT DEFINED QT_PREFIX_DIR_MSG )
      set( QT_PREFIX_DIR_MSG "${QT_PREFIX_DIR}" )
    endif( )
  endif( )



  if( DEFINED QT_INCLUDE_DIR )
    if( EXISTS "${QT_INCLUDE_DIR}/qapplication.h" )
      set( QT_INCLUDE_DIR_MSG "${QT_INCLUDE_DIR} (ok)" )
      set( QT_INCLUDE_DIR "${QT_INCLUDE_DIR}" CACHE PATH "" )
    else( )
      set( QT_INCLUDE_DIR_MSG "qapplication.h does not exists in ${QT_INCLUDE_DIR}" )
    endif( )
  else( )
    set( QT_INCLUDE_DIR_MSG "is not set" )
  endif( )



  if( DEFINED QT_LIBRARY )
    if( EXISTS "${QT_LIBRARY}" )
      set( QT_LIBRARY_MSG "${QT_LIBRARY} (ok)" )
    else( )
      set( QT_LIBRARY_MSG "invalid path ${QT_LIBRARY}" )
    endif( )
  else( )
    if( DEFINED QT_LIBRARY_DIR )
      find_library( QT_LIBRARY NAMES qt-mt qt HINTS "${QT_LIBRARY_DIR}" NO_DEFAULT_PATH )
      if( QT_LIBRARY )
        set( QT_LIBRARY_MSG "${QT_LIBRARY} (ok)" )
      else( )
        set( QT_LIBRARY_MSG "not found in ${QT_LIBRARY_DIR}" )
      endif( )
    else( )
      set( QT_LIBRARY_MSG "none of QT_LIBRARY_DIR or QT_LIBRARY is set" )
    endif( )
  endif( )



  if( DEFINED QT_MOC_EXECUTABLE )
    if( EXISTS "${QT_MOC_EXECUTABLE}" )
      set( QT_MOC_EXECUTABLE_MSG "${QT_MOC_EXECUTABLE} (ok)" )
    else( )
      set( QT_MOC_EXECUTABLE_MSG "invalid path ${QT_MOC_EXECUTABLE}" )
    endif( )
  else( )
    if( DEFINED QT_BINARY_DIR )
      find_program( QT_MOC_EXECUTABLE NAMES moc HINTS "${QT_BINARY_DIR}" NO_DEFAULT_PATH )
      if( QT_MOC_EXECUTABLE )
        set( QT_MOC_EXECUTABLE_MSG "${QT_MOC_EXECUTABLE} (ok)" )
      else( )
        set( QT_MOC_EXECUTABLE_MSG "not found in ${QT_BINARY_DIR}" )
      endif( )
    else( )
      set( QT_MOC_EXECUTABLE_MSG "none of QT_BINARY_DIR or QT_MOC_EXECUTABLE is set" )
    endif( )
  endif( )



  if( DEFINED QT_UIC_EXECUTABLE )
    if( EXISTS "${QT_UIC_EXECUTABLE}" )
      set( QT_UIC_EXECUTABLE_MSG "${QT_UIC_EXECUTABLE} (ok)" )
    else( )
      set( QT_UIC_EXECUTABLE_MSG "invalid path ${QT_UIC_EXECUTABLE}" )
    endif( )
  else( )
    if( DEFINED QT_BINARY_DIR )
      find_program( QT_UIC_EXECUTABLE NAMES uic HINTS "${QT_BINARY_DIR}" NO_DEFAULT_PATH )
      if( QT_UIC_EXECUTABLE )
        set( QT_UIC_EXECUTABLE_MSG "${QT_UIC_EXECUTABLE} (ok)" )
      else( )
        set( QT_UIC_EXECUTABLE_MSG "not found in ${QT_BINARY_DIR}" )
      endif( )
    else( )
      set( QT_UIC_EXECUTABLE_MSG "none of QT_BINARY_DIR or QT_UIC_EXECUTABLE is set" )
    endif( )
  endif( )



  # attempt to run moc, to check which qt version is using
  if( QT_MOC_EXECUTABLE )
    execute_process( COMMAND ${QT_MOC_EXECUTABLE} -v ERROR_VARIABLE __output
      RESULT_VARIABLE __result ERROR_STRIP_TRAILING_WHITESPACE OUTPUT_QUIET )
    if( __result EQUAL 0 OR __result EQUAL 1 )
      string( REGEX MATCH "^.*Qt (.+)\\)$" __dummy  "${__output}" )
      set( QT_VERSION  "${CMAKE_MATCH_1}" CACHE INTERNAL "" )
      if( NOT QT_VERSION )
        set( QT_MOC_EXECUTABLE_MSG "${QT_MOC_EXECUTABLE} (invalid response)" )
      endif( )
    else( )
      set( QT_MOC_EXECUTABLE_MSG "${QT_MOC_EXECUTABLE} (unable to run)" )
    endif( )
  endif( )


  if( QT_VERSION )
    message( "   QT_VERSION: ${QT_VERSION}" )
  endif( )

  message( "   QT_PREFIX_DIR: ${QT_PREFIX_DIR_MSG}" )
  message( "   QT_INCLUDE_DIR: ${QT_INCLUDE_DIR_MSG}" )
  message( "   QT_LIBRARY: ${QT_LIBRARY_MSG}" )
  message( "   QT_MOC_EXECUTABLE: ${QT_MOC_EXECUTABLE_MSG}" )
  message( "   QT_UIC_EXECUTABLE: ${QT_UIC_EXECUTABLE_MSG}" )


  if( NOT QT_VERSION OR NOT QT_INCLUDE_DIR OR NOT QT_LIBRARY OR NOT QT_MOC_EXECUTABLE OR NOT QT_UIC_EXECUTABLE )
    message( FATAL_ERROR
      "\n"
      "####################################################################\n "
      "One or more Qt3 components are not found. QTDIR is set?\n "
      "Check if your Qt3 is correctly installed, including devel package.\n "
      "Also, double check the arguments passed to cmake.\n"
      "####################################################################\n" )
  endif( )


endif( NOT DEFINED QT_VERSION )


# c++ flags for Qt3
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DQT_SHARED -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_CLEAN_NAMESPACE -DQT_NO_ASCII_CAST -D_REENTRANT" )
