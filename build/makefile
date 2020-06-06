CXX = clang++
LIBS = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lpthread
SDL_INCLUDE = -I/usr/include/SDL2
INC_INCLUDE = -I../src/inc -I../src/inc/engine -I../src/inc/piece
CXX_FLAGS = -Werror -pedantic-errors -O0 -Wno-c++98-compat-pedantic -Wno-padded -std=c++14 -g $(SDL_INCLUDE) $(INC_INCLUDE)
LINKER_FLAGS = $(LIBS)
OBJ_FILES = engine.o game.o game_renderer.o easy_sdl.o sprite.o
VPATH = ../src/main/engine:../src/main:../src/main/piece

all: Tetris cscope

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $<

Tetris: $(OBJ_FILES) main.o
	$(CXX) $(LINKER_FLAGS) -o Tetris $(OBJ_FILES) main.o

.PHONY: clean

clean:
	-rm *.o Tetris

.DELETE_ON_ERROR:

cscope:
	cd ~/Games/Tetris && find . -name "*.h" > cscope.files && \
	find . -name "*.cpp" >> cscope.files && cscope -b -q -k -R
