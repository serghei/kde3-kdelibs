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
    qtplatinum.themerc qtcde.themerc qtmotif.themerc
    qtwindows.themerc qtsgi.themerc qtmotifplus.themerc
    highcolor.themerc default.themerc b3.themerc
    light-v2.themerc light-v3.themerc keramik.themerc
  DESTINATION ${DATA_INSTALL_DIR}/kstyle/themes )

install( FILES
    kthemestylerc
  DESTINATION ${CONFIG_INSTALL_DIR} )
