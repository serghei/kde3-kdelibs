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

add_subdirectory( hicolor )
add_subdirectory( crystalsvg )
add_subdirectory( emoticons )


# ksvgtopng is compiled only if we have libart support
if( WITH_LIBART )

include_directories(
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdefx
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdecore/svgicons
  ${QT_INCLUDE_DIR}
  ${LIBART_INCLUDE_DIRS}
)


##### other data ################################

kde_install_symlink( crystalsvg ${ICON_INSTALL_DIR}/default.kde )


##### ksvgtopng #################################

set( target ksvgtopng )

set( ${target}_SRCS
  ksvgtopng.cpp
)

kde_add_executable( ${target}
  SOURCES ${${target}_SRCS}
  LINK kdesvgicons-static kdecore-shared
  DESTINATION ${BIN_INSTALL_DIR}
)

endif( WITH_LIBART )
