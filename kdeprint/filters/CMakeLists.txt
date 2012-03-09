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
    enscript.desktop enscript.xml psnup.desktop psnup.xml
    imagetops.desktop imagetops.xml pdfwrite.desktop
    pdfwrite.xml psbook1.desktop psbook1.xml psbook2.desktop
    psbook2.xml psbook.desktop psbook.xml psselect.desktop
    psselect.xml ps2pdf.desktop ps2pdf.xml pdf2ps.desktop
    pdf2ps.xml poster.desktop poster.xml
  DESTINATION ${DATA_INSTALL_DIR}/kdeprint/filters )

install( PROGRAMS imagetops DESTINATION ${BIN_INSTALL_DIR} )
