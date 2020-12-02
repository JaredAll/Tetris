CXX = clang++
LIBS = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lpthread
SDL_INCLUDE = -I/usr/include/SDL2
OEIL_INCLUDE = -I../test/trompeloeil/include
INC_INCLUDE = -I../src/inc -I../src/inc/engine -I../src/inc/piece -I../src/inc/piece/config \
-I../src/inc/engine/input -I../src/inc/piece/state -I../test/inc -I../test/inc/mocks
CXX_FLAGS = -Werror -pedantic-errors -O0 -Wno-c++98-compat-pedantic -Wno-padded -std=c++17 -g $(SDL_INCLUDE) $(INC_INCLUDE) $(OEIL_INCLUDE)
LINKER_FLAGS = $(LIBS)
OBJ_FILES = engine.o game.o game_renderer.o easy_sdl.o sprite.o tetris_component_factory.o \
tetris_piece.o point.o jay_piece.o zee_piece.o ess_piece.o ell_piece.o bar_piece.o \
block_piece.o tee_piece.o block.o tetris_board.o input_event.o input_handler.o waiting_state.o \
falling_state.o tetris_piece_state.o shifting_state.o tetris_visitor.o
TEST_OBJ_FILES = test_driver.o tetris_piece_test.o concrete_piece_test.o input_event_test.o \
falling_state_test.o shifting_state_test.o waiting_state_test.o tetris_board_test.o \
tetris_component_factory_test.o
VPATH = ../src/main/engine:../src/main:../src/main/piece:../src/main/engine/input\
:../src/main/piece/state:../test/main:../test/main/engine

all: Tetris tests cscope

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $<

Tetris: $(OBJ_FILES) main.o
	$(CXX) $(LINKER_FLAGS) -o Tetris $(OBJ_FILES) main.o

tests: $(TEST_OBJ_FILES) $(OBJ_FILES)
	$(CXX) $(LINKER_FLAGS) -o tests $(TEST_OBJ_FILES) $(OBJ_FILES)

.PHONY: clean

clean:
	-rm *.o Tetris

.DELETE_ON_ERROR:

cscope:
	cd ~/Games/Tetris && find . -name "*.h" > cscope.files && \
	find . -name "*.cpp" >> cscope.files && cscope -b -q -k -R
