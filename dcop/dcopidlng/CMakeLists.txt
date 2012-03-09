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

install( PROGRAMS
    dcopidlng
  DESTINATION ${BIN_INSTALL_DIR} )

install( PROGRAMS
    kalyptus
  DESTINATION ${DATA_INSTALL_DIR}/dcopidlng )

install( FILES
    Ast.pm Iter.pm kalyptusCxxToDcopIDL.pm kdocAstUtil.pm
    kdocParseDoc.pm kdocUtil.pm
  DESTINATION ${DATA_INSTALL_DIR}/dcopidlng )
