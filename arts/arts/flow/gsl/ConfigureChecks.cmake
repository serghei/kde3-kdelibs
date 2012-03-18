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

include( CheckFunctionExists )
include( CheckTypeSize )
include( CMakePushCheckState )


check_type_size( pthread_mutex_t GSL_SIZEOF_PTH_MUTEX_T )
check_type_size( pthread_cond_t GSL_SIZEOF_PTH_COND_T )
check_type_size( intmax_t GSL_SIZEOF_STD_INTMAX_T )


# pthread_mutexattr_settype
cmake_push_check_state( )
set( CMAKE_REQUIRED_LIBRARIES "pthread" )
check_function_exists( pthread_mutexattr_settype GSL_HAVE_MUTEXATTR_SETTYPE )
kde_var_to_01( GSL_HAVE_MUTEXATTR_SETTYPE )
cmake_pop_check_state( )


# audiofile
kde_conditional_search_module( WITH_AUDIOFILE AUDIOFILE audiofile )


# mad
kde_conditional_search_module( WITH_MAD MAD mad )
kde_var_to_01( HAVE_MAD GSL_HAVE_LIBMAD )


# vorbis
# NOTE assume we have enough recent library
kde_conditional_search_module( WITH_VORBIS VORBIS vorbis )
kde_conditional_search_module( WITH_VORBIS VORBISFILE vorbisfile )
kde_var_to_01( HAVE_VORBIS GSL_HAVE_OGGVORBIS )


configure_file( gslconfig.h.cmake gslconfig.h @ONLY )
