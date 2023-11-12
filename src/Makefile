CXX = g++
CXXFLAGS = -O2 -Wall -Werror -Wextra -std=c++17

LDFLAGS = $(shell pkg-config --cflags --libs gtest)

SRC_MODEL = Model/*.cpp
SRC_TEST = unit_tests/*.cpp


OS := $(shell uname -s)
ifeq ($(OS), Darwin)
	OPEN = open build/viewer.app
else
	OPEN = ./build/viewer
endif

all: install

install:
	@mkdir build/ && cd build/ && qmake ../viewer.pro && make
	$(OPEN)

uninstall:
	rm -rf build/
	rm -rf settings.ini

open:
	$(OPEN)

clean:
	rm -rf build/
	rm -rf test *.gcda *.gcno
	rm -rf ../*.tar
	rm -rf settings.ini

dist:
	tar -cf ../3D_Viewer_V2.tar View/ Controller/ images/ materials/ Model/ models/ main.cpp viewer.pro Makefile

clang:
	clang-format -n -style=google Model/*.h $(SRC_MODEL)  Controller/*.h View/*.h View/*.cpp main.cpp
	clang-format -i -style=google Model/*.h $(SRC_MODEL) Controller/*.h View/*.h View/*.cpp main.cpp

.PHONY: all install uninstall open clean dist dvi tests leaks clang
