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

##### other data ################################

install( FILES
    katepart.desktop
  DESTINATION ${SERVICES_INSTALL_DIR} )

install( FILES
    katepartui.rc katepartreadonlyui.rc
  DESTINATION ${DATA_INSTALL_DIR}/katepart )

install( FILES
    katesyntaxhighlightingrc katefiletyperc
  DESTINATION ${CONFIG_INSTALL_DIR} )

install( FILES
    language.dtd syntax.template cpp.xml c.xml html.xml
    kbasic.xml objectivec.xml changelog.xml ada.xml
    css.xml perl.xml php.xml xml.xml java.xml rpmspec.xml
    sql.xml sql-mysql.xml sql-postgresql.xml vhdl.xml
    diff.xml bash.xml latex.xml postscript.xml ruby.xml
    rhtml.xml desktop.xml eiffel.xml pascal.xml sather.xml
    python.xml makefile.xml ferite.xml scheme.xml matlab.xml
    tcl.xml ilerpg.xml verilog.xml javascript.xml sml.xml
    winehq.xml cs.xml sgml.xml idconsole.xml xmldebug.xml
    fortran.xml haskell.xml literate-haskell.xml r.xml
    gnuassembler.xml mab.xml mason.xml idl.xml prolog.xml
    rsiidl.xml coldfusion.xml picsrc.xml uscript.xml lpc.xml
    velocity.xml sci.xml ldif.xml inform.xml xharbour.xml
    yacas.xml component-pascal.xml asm6502.xml gdl.xml
    bibtex.xml d.xml vrml.xml rexx.xml cue.xml progress.xml
    e.xml sieve.xml modula-2.xml awk.xml cisco.xml doxygen.xml
    lua.xml pike.xml debianchangelog.xml debiancontrol.xml
    fgl-4gl.xml fgl-per.xml alert.xml gettext.xml commonlisp.xml
    clipper.xml povray.xml euphoria.xml mup.xml jsp.xml
    ocaml.xml lex.xml yacc.xml cg.xml ahdl.xml ansic89.xml
    tibasic.xml purebasic.xml mips.xml logtalk.xml txt2tags.xml
    xslt.xml stata.xml glsl.xml lilypond.xml abc.xml asp.xml
    asm-avr.xml rib.xml cmake.xml octave.xml javadoc.xml
    cgis.xml spice.xml nasm.xml mediawiki.xml apache.xml
    m3u.xml ini.xml fstab.xml actionscript.xml email.xml
    ${CMAKE_CURRENT_BINARY_DIR}/html-php.xml
    ${CMAKE_CURRENT_BINARY_DIR}/css-php.xml
    ${CMAKE_CURRENT_BINARY_DIR}/javascript-php.xml
  DESTINATION ${DATA_INSTALL_DIR}/katepart/syntax )


##### generate php headers ######################

add_custom_command( OUTPUT html-php.xml
  COMMAND perl ARGS generate-php.pl < html.xml > ${CMAKE_CURRENT_BINARY_DIR}/html-php.xml
  DEPENDS html.xml
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

add_custom_command( OUTPUT css-php.xml
  COMMAND perl ARGS generate-php.pl < css.xml > ${CMAKE_CURRENT_BINARY_DIR}/css-php.xml
  DEPENDS css.xml
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

add_custom_command( OUTPUT javascript-php.xml
  COMMAND perl ARGS generate-php.pl < javascript.xml > ${CMAKE_CURRENT_BINARY_DIR}/javascript-php.xml
  DEPENDS javascript.xml
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

add_custom_target( php-headers ALL
  DEPENDS html-php.xml css-php.xml javascript-php.xml )
