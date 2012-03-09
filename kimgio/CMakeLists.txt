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

set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${USE_EXCEPTIONS} )

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore
  ${QT_INCLUDE_DIR}
)


##### kimg_eps ##################################

set( target kimg_eps )

kde_add_kpart( ${target}
  SOURCES eps.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimg_xview ################################

set( target kimg_xview )

kde_add_kpart( ${target}
  SOURCES xview.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimg_tiff #################################

if( TIFF_FOUND )
  set( target kimg_tiff )
  kde_add_kpart( ${target}
    SOURCES tiffr.cpp
    LINK kdecore-shared ${TIFF_LIBRARIES}
    DESTINATION ${PLUGIN_INSTALL_DIR}
  )
  install( FILES tiff.kimgio DESTINATION ${SERVICES_INSTALL_DIR} )
endif( TIFF_FOUND )


##### kimg_ico ##################################

set( target kimg_ico )

kde_add_kpart( ${target}
  SOURCES ico.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimg_jp2 ##################################

if( JASPER_FOUND )
  set( target kimg_jp2 )
  kde_add_kpart( ${target}
    SOURCES jp2.cpp
    LINK kdecore-shared ${JASPER_LIBRARIES}
    DESTINATION ${PLUGIN_INSTALL_DIR}
  )
  install( FILES jp2.kimgio DESTINATION ${SERVICES_INSTALL_DIR} )
endif( JASPER_FOUND )


##### kimg_pcx ##################################

set( target kimg_pcx )
kde_add_kpart( ${target}
  SOURCES pcx.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimg_tga ##################################

set( target kimg_tga )
kde_add_kpart( ${target}
  SOURCES tga.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimg_rgb ##################################

set( target kimg_rgb )
kde_add_kpart( ${target}
  SOURCES rgb.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimg_xcf ##################################

set( target kimg_xcf )
kde_add_kpart( ${target}
  SOURCES xcf.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimg_dds ##################################

set( target kimg_dds )
kde_add_kpart( ${target}
  SOURCES dds.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### kimg_exr ##################################

if( OPENEXR_FOUND )
  set( target kimg_exr )
  kde_add_kpart( ${target}
    SOURCES exr.cpp
    LINK kdecore-shared ${OPENEXR_LIBRARIES}
    DESTINATION ${PLUGIN_INSTALL_DIR}
  )
  # FIXME COMPILE_FLAGS must be written a little better
  set_target_properties( ${target}-module PROPERTIES COMPILE_FLAGS -I${OPENEXR_INCLUDE_DIRS} )
  install( FILES exr.kimgio DESTINATION ${SERVICES_INSTALL_DIR} )
endif( OPENEXR_FOUND )


##### kimg_psd ##################################

set( target kimg_psd )
kde_add_kpart( ${target}
  SOURCES psd.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)

##### kimg_hdr ##################################

set( target kimg_hdr )
kde_add_kpart( ${target}
  SOURCES hdr.cpp
  LINK kdecore-shared
  DESTINATION ${PLUGIN_INSTALL_DIR}
)


##### other data ################################

install( FILES
    png.kimgio xpm.kimgio bmp.kimgio pbm.kimgio pgm.kimgio
    ppm.kimgio xbm.kimgio jpeg.kimgio xv.kimgio eps.kimgio
    ico.kimgio gif.kimgio pcx.kimgio tga.kimgio rgb.kimgio
    xcf.kimgio dds.kimgio mng.kimgio psd.kimgio hdr.kimgio
  DESTINATION ${SERVICES_INSTALL_DIR} )
