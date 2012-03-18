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

include( ConfigureChecks.cmake )

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}/..
  ${CMAKE_CURRENT_BINARY_DIR}/../../mcop
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  ${CMAKE_CURRENT_SOURCE_DIR}/../../mcop
  ${CMAKE_BINARY_DIR}
  ${GLIB2_INCLUDE_DIRS}
)


##### headers ###################################

install( FILES
    gslcommon.h gsldatacache.h gsldatahandle.h
    gsldefs.h gslloader.h gslmath.h gslfilter.h
    gsldatautils.h gsldatahandle-vorbis.h gslconvert.h
    gslfft.h gslieee754.h gslsignal.h gslmagic.h
    gslengine.h gslwaveosc.h gslwavechunk.h
    gsldatahandle-mad.h gslosctable.h gsloscillator.h
    ${CMAKE_CURRENT_BINARY_DIR}/gslconfig.h
  DESTINATION ${INCLUDE_INSTALL_DIR}/arts/gsl )


##### gsl (static) ##############################

kde_add_library( gsl STATIC_PIC
  SOURCES
    gsldatacache.c gsldatahandle.c gslwavechunk.c
    gsldatahandle-vorbis.c gslmath.c gslfilter.c
    gslcommon.c gsldatautils.c gslmagic.c gslloader-wav.c
    gslloader-gslwave.c gslloader-mad.c gslloader-oggvorbis.c
    gslconvert.c gslfft.c gslsignal.c gslloader.c
    gslwaveosc.c gslengine.c gsloputil.c gslopmaster.c
    gslopschedule.c gsldatahandle-mad.c gslosctable.c
    gsloscillator.c gslfilehash.c gslartsthreads.cc
  DEPENDENCIES mcop-shared
)
