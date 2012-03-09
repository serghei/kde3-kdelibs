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

##### headers ###################################

install( FILES
    kspeech.h kspeechsink.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

install( FILES dcoptexttospeech.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )
