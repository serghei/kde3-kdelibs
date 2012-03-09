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
    jstest.desktop jstest.js script-indent-c-newline.js
    script-indent-c-char.js sort.js
  DESTINATION ${DATA_INSTALL_DIR}/katepart/scripts )

install( FILES
    script-indent-c-test.js script-indent-c1-test.lua
  DESTINATION ${DATA_INSTALL_DIR}/katepart/scripts/indent )
