CXX = clang++
SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf
SDL_INCLUDE = -I/usr/include/SDL2
INC_INCLUDE = -I../src/inc
CXX_FLAGS = -Werror -pedantic-errors -O0 -Wno-c++98-compat-pedantic -Wno-padded -std=c++14 -g $(SDL_INCLUDE) $(INC_INCLUDE)
LINKER_FLAGS = $(SDL_LIB)
OBJ_FILES = engine.o
VPATH = ../src/main/engine:../src/main

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
