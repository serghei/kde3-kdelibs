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

macro( message_fatal )
  message( FATAL_ERROR
    "#################################################\n"
    " ${ARGV}\n"
    "#################################################" )
endmacro( )


if( PLUGIN_DIR )
  set( L -L "${PLUGIN_DIR}" )
endif( )

execute_process( COMMAND "${UIC_EXECUTABLE}"
    -nounload -tr tr2i18n
    ${L}
    "${UI_FILE}"
  RESULT_VARIABLE _result
  OUTPUT_VARIABLE _h_content )

if( _result )
  message_fatal( "Cannot generate ${H_FILE}" )
endif( )

if( _h_content )
  string( REGEX REPLACE "#ifndef " "#ifndef UI_" _h_content "${_h_content}" )
  string( REGEX REPLACE "#define " "#define UI_" _h_content "${_h_content}" )
  string( REGEX REPLACE "public QWizard" "public KWizard" _h_content "${_h_content}" )
  string( REGEX REPLACE "#include <qwizard.h>" "#include <kwizard.h>" _h_content "${_h_content}" )
  file( WRITE "${H_FILE}" "${_h_content}" )
endif( )

execute_process( COMMAND "${UIC_EXECUTABLE}"
    -nounload -tr tr2i18n
    ${L}
    -impl "${H_FILE}"
    "${UI_FILE}"
  RESULT_VARIABLE _result
  OUTPUT_VARIABLE _cpp_content )

if( _result )
  message_fatal( "Cannot generate ${CPP_FILE}" )
endif( )

if( _cpp_content )
  string( REGEX REPLACE "tr2i18n\\(\"\"\\)" "QString::null" _cpp_content "${_cpp_content}" )
  string( REGEX REPLACE "tr2i18n\\(\"\", \"\"\\)" "QString::null" _cpp_content "${_cpp_content}" )
  string( REGEX REPLACE ": QWizard\\(" ": KWizard(" _cpp_content "${_cpp_content}" )
  file( WRITE "${CPP_FILE}" "#include <kdialog.h>\n#include <klocale.h>\n\n${_cpp_content}\n" )
endif( )
