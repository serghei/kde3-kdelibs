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
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/dcop
  ${QT_INCLUDE_DIR}
)

set( test_PROGS
  kaboutdialogtest kblendtest kbuttonboxtest kcharselecttest
  kcolortest kcolordlgtest kcomboboxtest kcompletiontest
  kdatepicktest kdatewidgettest kdialogbasetest
  kdockwidgetdemo kdockwidgettest
  kdualcolortest keditlistboxtest kfontdialogtest
  kgradienttest khashtest kdesattest
  kledtest klineedittest klineeditdlgtest
  kmessageboxtest knuminputtest
  kpalettetest
  kpopuptest kprogresstest krulertest kseparatortest
  kstatusbartest ktabctltest
  kunbalancedgrdtest kwindowtest kwizardtest
  itemcontainertest kpanelmenutest kedittest
  kxmlguitest kaccelgentest ksystemtraytest klistviewtest
  ktextedittest kmainwindowtest kmainwindowrestoretest
  kactiontest kdatetimewidgettest ktimewidgettest
  kspelltest kinputdialogtest ktabwidgettest kwordwraptest
  kdocktest qxembedtest ksqueezedtextlabeltest
  kpixmapregionselectordialogtest kjanuswidgettest ktoolbarlabelactiontest
)

foreach( PROG ${test_PROGS} )
  kde_add_executable( ${PROG} AUTOMOC SOURCES "${PROG}.cpp" LINK kdeui-shared )
endforeach( PROG ${test_PROGS} )
