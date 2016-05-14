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

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/bookmarks
  ${QT_INCLUDE_DIR}
  ${LIBART_INCLUDE_DIRS}
)


##### headers ###################################

install( FILES
    kfiledialog.h kencodingfiledialog.h
    kdiroperator.h kfileview.h kfilefiltercombo.h
    kfiledetailview.h kcombiview.h kdiskfreesp.h
    kfileiconview.h krecentdocument.h
    kurlrequester.h kfilepreview.h kfile.h
    kurlcombobox.h kurlrequesterdlg.h kopenwith.h kpropsdlg.h
    kicondialog.h kdirsize.h kpreviewwidgetbase.h kimagefilepreview.h kfilesharedlg.h
    kfiletreeview.h kfiletreeviewitem.h kfiletreebranch.h
    kdirselectdialog.h kurlbar.h kpropertiesdialog.h knotifydialog.h
    kcustommenueditor.h ${CMAKE_CURRENT_BINARY_DIR}/knotifywidgetbase.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

install( FILES
    kpropsdlgplugin.desktop
 DESTINATION ${SERVICETYPES_INSTALL_DIR} )


##### kfile #####################################

kde_add_library( kfile STATIC_PIC AUTOMOC
  SOURCES
    kfilefiltercombo.cpp kfileview.cpp kfileiconview.cpp
    krecentdocument.cpp kfiledialog.cpp kdiroperator.cpp
    kfiledetailview.cpp kcombiview.cpp kurlrequester.cpp
    kfilepreview.cpp kurlcombobox.cpp kurlrequesterdlg.cpp
    kopenwith.cpp kpropertiesdialog.cpp kicondialog.cpp kdirsize.cpp
    krecentdirs.cpp kdiskfreesp.cpp kimagefilepreview.cpp
    kfilesharedlg.cpp kurlbar.cpp kmetaprops.cpp kpreviewprops.cpp
    kfiletreeview.cpp kfiletreeviewitem.cpp kfiletreebranch.cpp
    kdirselectdialog.cpp kfilebookmarkhandler.cpp kfilemetainfowidget.cpp
    kcustommenueditor.cpp knotifywidgetbase.ui knotifydialog.cpp
    kfilespeedbar.cpp kpreviewwidgetbase.cpp kfilemetapreview.cpp
    kpropertiesdesktopbase.ui kpropertiesdesktopadvbase.ui
    kpropertiesmimetypebase.ui kencodingfiledialog.cpp kacleditwidget.cpp
)
