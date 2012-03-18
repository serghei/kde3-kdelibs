#################################################
#
#  (C) 2012 Serghei Amelian
#  serghei (DOT) amelian (AT) gmail.com
#
#  Improvements and feedback are welcome
#
#  This file is released under GPL >= 2
#
#################################################

install( FILES
    Synth_ADD.mcopclass Synth_FREQUENCY.mcopclass
    Synth_MUL.mcopclass Synth_MULTI_ADD.mcopclass
    Synth_PLAY.mcopclass Synth_RECORD.mcopclass
    Synth_PLAY_WAV.mcopclass Synth_WAVE_SIN.mcopclass
    Synth_BUS_DOWNLINK.mcopclass Synth_BUS_UPLINK.mcopclass
    Synth_AMAN_PLAY.mcopclass Synth_AMAN_RECORD.mcopclass
    DataHandlePlay.mcopclass WaveDataHandle.mcopclass
  DESTINATION ${LIB_INSTALL_DIR}/mcop/Arts )
