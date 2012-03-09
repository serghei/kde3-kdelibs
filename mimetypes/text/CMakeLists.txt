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
    x-c++src.desktop x-c++hdr.desktop x-csrc.desktop x-java.desktop
    x-makefile.desktop x-moc.desktop x-pascal.desktop x-objchdr.desktop
    x-tcl.desktop x-tex.desktop html.desktop plain.desktop enriched.desktop x-chdr.desktop
    rtf.desktop sgml.desktop xml.desktop css.desktop x-vcard.desktop x-ldif.desktop
    x-vcalendar.desktop x-diff.desktop x-objcsrc.desktop x-log.desktop
    x-bibtex.desktop rdf.desktop rss.desktop calendar.desktop x-adasrc.desktop
    x-csv.desktop x-latex.desktop x-xslfo.desktop x-xslt.desktop vnd.wap.wml.desktop x-katefilelist.desktop
    docbook.desktop x-mswinurl.desktop x-hex.desktop vnd.abc.desktop javascript.desktop x-python.desktop
  DESTINATION ${MIME_INSTALL_DIR}/text )

install( FILES uninstall.desktop DESTINATION ${MIME_INSTALL_DIR}/text RENAME x-perl.desktop )
install( FILES uninstall.desktop DESTINATION ${MIME_INSTALL_DIR}/text RENAME x-python.desktop )
install( FILES uninstall.desktop DESTINATION ${MIME_INSTALL_DIR}/text RENAME x-lyx.desktop )
