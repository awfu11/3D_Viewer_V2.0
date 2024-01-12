CXX = g++
CXXFLAGS = -O2 -Wall -Werror -Wextra -std=c++17

LDFLAGS = $(shell pkg-config --cflags --libs gtest)


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
	rm -rf ../*.tar
	rm -rf settings.ini

dist:
	tar -cf ../3D_Viewer_V2.tar View/ Controller/ images/ materials/ Model/ models/ main.cpp viewer.pro Makefile

.PHONY: all install uninstall open clean dist
