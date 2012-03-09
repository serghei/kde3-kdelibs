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
    kimiface.h
  DESTINATION ${INCLUDE_INSTALL_DIR} )


##### other data ################################

install( FILES kcm_instantmessenger.desktop DESTINATION ${DATA_INSTALL_DIR}/kcm_componentchooser )
install( FILES dcopinstantmessenger.desktop DESTINATION ${SERVICETYPES_INSTALL_DIR} )
