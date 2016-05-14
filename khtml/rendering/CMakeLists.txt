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

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/triq
  ${CMAKE_SOURCE_DIR}/khtml
  ${CMAKE_SOURCE_DIR}/kdecore
  ${CMAKE_SOURCE_DIR}/kdeui
  ${CMAKE_SOURCE_DIR}/kio
  ${CMAKE_SOURCE_DIR}/kio/kio
  ${CMAKE_SOURCE_DIR}/kio/kfile
  ${CMAKE_SOURCE_DIR}/kutils
  ${QT_INCLUDE_DIR}
)


##### khtmlrender-static #########################

set( target khtmlrender )

set( ${target}_SRCS
  bidi.cpp break_lines.cpp render_block.cpp render_inline.cpp
  render_style.cpp render_object.cpp render_container.cpp render_box.cpp
  render_flow.cpp render_text.cpp render_arena.cpp render_layer.cpp
  render_image.cpp render_table.cpp table_layout.cpp
  render_replaced.cpp render_form.cpp render_list.cpp
  render_canvas.cpp render_frames.cpp render_br.cpp
  render_body.cpp font.cpp render_line.cpp render_generated.cpp
  enumerate.cpp counter_tree.cpp
)

kde_add_library( ${target} STATIC_PIC AUTOMOC
  SOURCES ${${target}_SRCS}
)
