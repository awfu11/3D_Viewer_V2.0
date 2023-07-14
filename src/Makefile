CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

MODEL_FILES = 3d_viewer/3d_viewer.c
VIEWER_FILES = 3d_viewer/*.cpp 3d_viewer/*.h
TEST_FILES = unit_tests/*.c

ifeq ($(shell uname), Linux)
	LIB_CHECK=-lcheck -lm -lpthread -lrt -lsubunit
else
# LIB_CHECK=-lcheck -lm
	LIB_CHECK=-lm $(shell pkg-config --cflags --libs check)
endif

all: install

install:
	@mkdir build/
	@cd build/ && qmake ../3d_viewer/3d_viewer_v1.pro && make
	@open build/3d_viewer_v1.app
# @./build/3d_viewer_v1.app/Contents/MacOS/3d_viewer_v1

uninstall:
	rm -rf build/
	rm -rf settings.ini

clean:
	rm -rf build/
	rm -rf test *.gcda *.gcno
	rm -rf report/
	rm -rf *.gcno *.gcda *.info gcov_report
	rm -rf ../*.tar
	rm -rf settings.ini
	rm -rf ../3D_Viewer_V1.tar

dist:
	tar -cf ../3D_Viewer_V1.tar 3d_viewer models Makefile doc.md

tests:
	@$(CC) $(CFLAGS) --coverage $(MODEL_FILES) $(TEST_FILES) -o test $(LIB_CHECK)
	@./test
	@rm -rf *.gcda *.gcno

gcov_report:
	@$(CC) $(CFLAGS) --coverage $(MODEL_FILES) $(TEST_FILES) -o gcov_report $(LIB_CHECK)
	@./gcov_report
	@lcov -o gcov_report.info -c -d .
	@genhtml -o report gcov_report.info
	@open ./report/index.html
	@rm -rf *.gcno *.gcda *.info gcov_report

clang:
	clang-format -n -style=google $(VIEWER_FILES) $(MODEL_FILES) $(TEST_FILES)
	clang-format -i -style=google $(VIEWER_FILES) $(MODEL_FILES) $(TEST_FILES)
