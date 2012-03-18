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

add_subdirectory( gsl )
add_subdirectory( gslpp )
add_subdirectory( mcopclass )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/../mcop
  ${CMAKE_CURRENT_SOURCE_DIR}/../mcop
  ${CMAKE_BINARY_DIR}
  ${GLIB2_INCLUDE_DIRS}
)


##### headers ###################################

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/artsflow.h audiosubsys.h cache.h
    cachedwav.h convert.h pipebuffer.h stdsynthmodule.h synthschedule.h
    fft.h artsflow.idl audioio.h resample.h cpuinfo.h bufferqueue.h
    gslschedule.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/arts )


##### other data ################################

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/artsflow.mcoptype
    ${CMAKE_CURRENT_BINARY_DIR}/artsflow.mcopclass
  DESTINATION ${LIB_INSTALL_DIR}/mcop )


##### artsflow_idl (shared) #####################

kde_add_library( artsflow_idl SHARED
  SOURCES artsflow.idl
  VERSION 1.0.0
  LINK mcop-shared
  DESTINATION ${LIB_INSTALL_DIR}
)


##### artsflow (shared) #########################

kde_add_library( artsflow SHARED
  SOURCES
    synth_play_impl.cc gslschedule.cc audiosubsys.cc pipebuffer.cc
    convert.cc synth_wave_sin_impl.cc synth_frequency_impl.cc
    synth_multi_add_impl.cc synth_add_impl.cc synth_mul_impl.cc
    synth_play_wav_impl.cc stdsynthmodule.cc cache.cc asyncschedule.cc
    bytestreamtoaudio_impl.cc stereovolumecontrol_impl.cc
    stereoeffectstack_impl.cc fft.c stereofftscope_impl.cc
    virtualports.cc bus.cc audiomanager_impl.cc synth_record_impl.cc
    resample.cc audioio.cc audioiooss.cc audioioalsa.cc audioioalsa9.cc
    audioionull.cc audioiolibaudioio.cc audioioesd.cc audioiojack.cc
    audioiosun.cc audioioaix.cc audioionas.cc cpuinfo.cc
    audioioossthreaded.cc audiotobytestream_impl.cc audioiosgi.cc
    audioiocsl.cc audioiomas.cc datahandle_impl.cc
  VERSION 1.0.0
  LINK
    gsl-static gslpp-static artsflow_idl-shared
    ${AUDIOFILE_LIBRARIES} ${MAD_LIBRARIES} ${VORBISFILE_LIBRARIES}
    ${ASOUND_LIBRARY} ${GLIB2_LIBRARIES} ${GTHREAD2_LIBRARIES}
  DESTINATION ${LIB_INSTALL_DIR}
)
