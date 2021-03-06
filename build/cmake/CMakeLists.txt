cmake_minimum_required(VERSION 3.10)

project(Tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
  Tetris
  ../../src/main/main.cpp
  ../../src/main/game.cpp
  ../../src/main/tetris_component_factory.cpp
  ../../src/main/tetris_board.cpp
  ../../src/main/tetris_visitor.cpp
  ../../src/main/engine/engine.cpp
  ../../src/main/engine/game_renderer.cpp
  ../../src/main/engine/easy_sdl.cpp
  ../../src/main/engine/sprite.cpp
  ../../src/main/engine/point.cpp
  ../../src/main/engine/panel.cpp
  ../../src/main/engine/input/input_event.cpp
  ../../src/main/engine/input/input_handler.cpp
  ../../src/main/engine/text/glyph.cpp
  ../../src/main/engine/text/text_box.cpp
  ../../src/main/engine/text/glyph_alphabet.cpp
  ../../src/main/piece/tetris_piece.cpp
  ../../src/main/piece/jay_piece.cpp
  ../../src/main/piece/zee_piece.cpp
  ../../src/main/piece/ess_piece.cpp
  ../../src/main/piece/ell_piece.cpp
  ../../src/main/piece/bar_piece.cpp
  ../../src/main/piece/block_piece.cpp
  ../../src/main/piece/tee_piece.cpp
  ../../src/main/piece/block.cpp
  ../../src/main/piece/state/waiting_state.cpp
  ../../src/main/piece/state/falling_state.cpp
  ../../src/main/piece/state/tetris_piece_state.cpp
  ../../src/main/piece/state/shifting_state.cpp
  )

add_executable(
  tests
  
  ../../src/main/game.cpp
  ../../src/main/tetris_component_factory.cpp
  ../../src/main/tetris_board.cpp
  ../../src/main/tetris_visitor.cpp
  ../../src/main/engine/engine.cpp
  ../../src/main/engine/game_renderer.cpp
  ../../src/main/engine/easy_sdl.cpp
  ../../src/main/engine/sprite.cpp
  ../../src/main/engine/point.cpp
  ../../src/main/engine/panel.cpp
  ../../src/main/engine/input/input_event.cpp
  ../../src/main/engine/input/input_handler.cpp
  ../../src/main/engine/text/glyph.cpp
  ../../src/main/engine/text/text_box.cpp
  ../../src/main/engine/text/glyph_alphabet.cpp
  ../../src/main/piece/tetris_piece.cpp
  ../../src/main/piece/jay_piece.cpp
  ../../src/main/piece/zee_piece.cpp
  ../../src/main/piece/ess_piece.cpp
  ../../src/main/piece/ell_piece.cpp
  ../../src/main/piece/bar_piece.cpp
  ../../src/main/piece/block_piece.cpp
  ../../src/main/piece/tee_piece.cpp
  ../../src/main/piece/block.cpp
  ../../src/main/piece/state/waiting_state.cpp
  ../../src/main/piece/state/falling_state.cpp
  ../../src/main/piece/state/tetris_piece_state.cpp
  ../../src/main/piece/state/shifting_state.cpp

  ../../test/main/test_driver.cpp
  ../../test/main/concrete_piece_test.cpp
  ../../test/main/falling_state_test.cpp
  ../../test/main/shifting_state_test.cpp
  ../../test/main/tetris_board_test.cpp
  ../../test/main/tetris_component_factory_test.cpp
  ../../test/main/tetris_piece_test.cpp
  ../../test/main/waiting_state_test.cpp
  ../../test/main/engine/input_event_test.cpp
  )

include_directories(
  ../../src/inc
  ../../src/inc/engine
  ../../src/inc/engine/input
  ../../src/inc/engine/text
  ../../src/inc/piece
  ../../src/inc/piece/state

  ../../test/trompeloeil/include
  ../../test/inc
  ../../test/inc/mocks
  )

list(
  APPEND
  CMAKE_MODULE_PATH
  ./sdl2-cmake-modules )

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_image_INCLUDE_DIRS})

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_ttf_INCLUDE_DIRS})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(
  Tetris
  SDL2::Main
  SDL2::Image
  SDL2::TTF
  Threads::Threads)

target_link_libraries(
  tests
  SDL2::Main
  SDL2::Image
  SDL2::TTF
  Threads::Threads)
