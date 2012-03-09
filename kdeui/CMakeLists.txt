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

if( BUILD_KDEUI_TESTS )
  add_subdirectory( tests )
endif( BUILD_KDEUI_TESTS )

add_subdirectory( about )
add_subdirectory( kdetrayproxy )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/dcop
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${QT_INCLUDE_DIR}
  ${FREETYPE_INCLUDE_DIRS}
)


##### headers ###################################

install( FILES
    kprogress.h kcolordlg.h kcolordialog.h
    kselect.h kdatepik.h kdatepicker.h kdatetbl.h kfontdialog.h
    kpopupmenu.h kfontrequester.h ktabctl.h kstatusbar.h kmainwindow.h
    kmainwindowiface.h ktoolbar.h kmenubar.h knuminput.h kseparator.h
    klineedit.h krestrictedline.h kcolorbutton.h kcolorbtn.h
    ksystemtray.h kdockwindow.h kbuttonbox.h keditcl.h kled.h
    keditlistbox.h kwizard.h kkeydialog.h kkeybutton.h kurllabel.h
    kruler.h kcursor.h klineeditdlg.h kinputdialog.h kactivelabel.h
    kcharselect.h kcolordrag.h qxembed.h knumvalidator.h kdialog.h
    kdialogbase.h kjanuswidget.h kaboutdialog.h kauthicon.h kmessagebox.h
    ksharedpixmap.h kdualcolorbtn.h kdualcolorbutton.h ktoolbarbutton.h
    ktoolbarradiogroup.h ktextbrowser.h kaction.h kactioncollection.h
    kactionclasses.h khelpmenu.h kswitchlanguagedialog.h kcmodule.h
    kcmenumngr.h kpanelmenu.h kpanelappmenu.h kactionshortcutlist.h
    kstdaction.h kcombobox.h kiconview.h klistview.h klistbox.h
    kbugreport.h kpassdlg.h kxmlguiclient.h kxmlgui.h kxmlguibuilder.h
    kxmlguifactory.h kpixmapio.h kwordwrap.h kedittoolbar.h kdockwidget.h
    kanimwidget.h krootpixmap.h kaboutkde.h kaboutapplication.h
    kpanelapplet.h kpushbutton.h kdcopactionproxy.h kcolorcombo.h
    kpanelextension.h kcompletionbox.h ksqueezedtextlabel.h
    kcommand.h kwindowlistmenu.h kfontcombo.h kaccelgen.h
    ktip.h kdatewidget.h karrowbutton.h kguiitem.h kstdguiitem.h
    kstringvalidator.h kwindowinfo.h ktextedit.h kpassivepopup.h
    kdatetimewidget.h ktimewidget.h ktimezonewidget.h kscrollview.h
    kspell.h ksconfig.h kspelldlg.h ksyntaxhighlighter.h
    ktabbar.h ktabwidget.h ksplashscreen.h kconfigdialog.h
    kactionselector.h klanguagebutton.h klistviewsearchline.h
    kpixmapregionselectorwidget.h kpixmapregionselectordialog.h
    kiconviewsearchline.h ktoolbarlabelaction.h kshortcutdialog.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

install( FILES
    aboutkde.png ktip-bulb.png ktip-background.png
  DESTINATION ${DATA_INSTALL_DIR}/kdeui/pics )

install( FILES
    ui_standards.rc
  DESTINATION ${CONFIG_INSTALL_DIR}/ui )

install( PROGRAMS
    preparetips
  DESTINATION ${BIN_INSTALL_DIR} )


##### libkdeui ##################################

kde_add_library( kdeui SHARED AUTOMOC
  SOURCES
    qxembed.cpp ksharedpixmap.cpp kpixmapio.cpp kpopupmenu.cpp
    ktoolbar.cpp kaction.cpp kstdaction.cpp kactioncollection.cpp
    kactionclasses.cpp kurllabel.cpp kmenubar.cpp kinputdialog.cpp
    knuminput.cpp klineedit.cpp klistview.cpp kprogress.cpp
    kcolordialog.cpp kselect.cpp kdatepicker.cpp kdatetbl.cpp
    kfontrequester.cpp kfontdialog.cpp ktabctl.cpp kstatusbar.cpp
    kmainwindow.cpp keditlistbox.cpp kscrollview.cpp kseparator.cpp
    krestrictedline.cpp kcolorbutton.cpp ksystemtray.cpp kbuttonbox.cpp
    keditcl1.cpp keditcl2.cpp kled.cpp kshortcutdialog_simple.ui
    kshortcutdialog_advanced.ui kshortcutdialog.cpp kkeybutton.cpp
    kkeydialog.cpp kruler.cpp kcursor.cpp klineeditdlg.cpp
    kcharselect.cpp kcolordrag.cpp knumvalidator.cpp kdialog.cpp
    kdialogbase.cpp kjanuswidget.cpp kaboutdialog.cpp kauthicon.cpp
    kmessagebox.cpp kdualcolorbutton.cpp ktoolbarradiogroup.cpp
    ktoolbarbutton.cpp ktextbrowser.cpp khelpmenu.cpp
    kswitchlanguagedialog.cpp kcmenumngr.cpp kpanelmenu.cpp
    kiconview.cpp klistbox.cpp kwordwrap.cpp kbugreport.cpp
    kcombobox.cpp kpassdlg.cpp kxmlguiclient.cpp kxmlguifactory.cpp
    kxmlguifactory_p.cpp kxmlguibuilder.cpp kedittoolbar.cpp
    kpanelappmenu.cpp kdockwidget.cpp kdockwidget_private.cpp
    kanimwidget.cpp krootpixmap.cpp kaboutkde.cpp kaboutapplication.cpp
    kpanelapplet.cpp kdcopactionproxy.cpp kcolorcombo.cpp kpushbutton.cpp
    kpanelextension.cpp kcompletionbox.cpp ksqueezedtextlabel.cpp
    kcmodule.cpp kcommand.cpp kwindowlistmenu.cpp kfontcombo.cpp
    ktip.cpp kdatewidget.cpp karrowbutton.cpp kmainwindowiface.cpp
    kmainwindowiface.skel kguiitem.cpp kstdguiitem.cpp
    kstringvalidator.cpp kactivelabel.cpp kwindowinfo.cpp
    ktextedit.cpp kwizard.cpp kpassivepopup.cpp ktoolbarhandler.cpp
    kdatetimewidget.cpp ktimewidget.cpp ktimezonewidget.cpp ksconfig.cpp
    kspelldlg.cpp kspell.cpp ksyntaxhighlighter.cpp ktabbar.cpp
    ktabwidget.cpp ksplashscreen.cpp kspellui.ui kconfigdialog.cpp
    kactionselector.cpp klanguagebutton.cpp klistviewsearchline.cpp
    kpixmapregionselectorwidget.cpp kpixmapregionselectordialog.cpp
    kwhatsthismanager.cpp kiconviewsearchline.cpp ktoolbarlabelaction.cpp
  VERSION 4.2.0
  LINK kdecore-shared ${FREETYPE_LIBRARIES} ${FONTCONFIG_LIBRARIES} ${XEXT_LIBRARIES}
  DEPENDENCIES dcopidl
  DESTINATION ${LIB_INSTALL_DIR}
)


##### libkspell #################################

configure_file( ${TEMPLATE_DUMMY_CPP} dummy.cpp COPYONLY )

kde_add_library( kspell SHARED
  SOURCES ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp
  LINK ${QT_LIBRARY}
  VERSION 4.2.0
  DESTINATION ${LIB_INSTALL_DIR}
)
