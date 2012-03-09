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
  ${CMAKE_BINARY_DIR}/kabc
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kabc
  ${CMAKE_SOURCE_DIR}/interfaces
  ${QT_INCLUDE_DIR}
)


##### headers ###################################

install( FILES
    document.h view.h editor.h plugin.h editinterface.h
    undointerface.h selectioninterface.h cursorinterface.h
    clipboardinterface.h popupmenuinterface.h viewcursorinterface.h
    searchinterface.h highlightinginterface.h blockselectioninterface.h
    codecompletioninterface.h configinterface.h markinterface.h
    printinterface.h wordwrapinterface.h dynwordwrapinterface.h
    markinterfaceextension.h configinterfaceextension.h
    encodinginterface.h viewstatusmsginterface.h
    sessionconfiginterface.h editorchooser.h documentinfo.h
    selectioninterfaceext.h selectionextdcopinterface.h
    texthintinterface.h editinterfaceext.h variableinterface.h
    templateinterface.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/ktexteditor )


##### other data ################################

install( FILES
    ktexteditor.desktop ktexteditoreditor.desktop
    ktexteditorplugin.desktop
  DESTINATION ${SERVICETYPES_INSTALL_DIR} )

install( FILES
    kcm_ktexteditor.desktop
  DESTINATION ${DATA_INSTALL_DIR}/kcm_componentchooser )



##### ktexteditor ###############################

set( target ktexteditor )

set( ${target}_SRCS
  ktexteditor.cpp
  editinterface.cpp clipboardinterface.cpp  selectioninterface.cpp searchinterface.cpp
  codecompletioninterface.cpp wordwrapinterface.cpp blockselectioninterface.cpp
  configinterface.cpp cursorinterface.cpp  dynwordwrapinterface.cpp
  printinterface.cpp highlightinginterface.cpp markinterface.cpp
  popupmenuinterface.cpp undointerface.cpp viewcursorinterface.cpp
  editdcopinterface.cpp editdcopinterface.skel clipboarddcopinterface.cpp
  clipboarddcopinterface.skel selectiondcopinterface.cpp selectiondcopinterface.skel
  searchdcopinterface.cpp searchdcopinterface.skel markinterfaceextension.cpp
  configinterfaceextension.cpp encodinginterface.cpp sessionconfiginterface.cpp
  viewstatusmsginterface.cpp editorchooser_ui.ui editorchooser.cpp
  blockselectiondcopinterface.cpp documentinfo.cpp documentdcopinfo.cpp
  blockselectiondcopinterface.skel documentdcopinfo.skel encodingdcopinterface.cpp
  encodingdcopinterface.skel printdcopinterface.cpp printdcopinterface.skel
  undodcopinterface.cpp undodcopinterface.skel viewcursordcopinterface.cpp
  viewcursordcopinterface.skel viewstatusmsgdcopinterface.cpp
  viewstatusmsgdcopinterface.skel selectioninterfaceext.cpp selectionextdcopinterface.skel
  texthintinterface.cpp editinterfaceext.cpp variableinterface.cpp templateinterface.cpp
)

kde_add_library( ${target} SHARED AUTOMOC
  SOURCES ${${target}_SRCS}
  VERSION 0.0.0
  LINK kdeui-shared kabc-shared kparts-shared
  DEPENDENCIES dcopidl dcopidl2cpp
  DESTINATION ${LIB_INSTALL_DIR}
)
