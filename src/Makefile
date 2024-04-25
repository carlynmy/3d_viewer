CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -g
PATH_BUILD=build

.PHONY: all clean install uninstall test dvi dist 
all: install

install:
	git submodule init
	git submodule update
	cmake -B $(PATH_BUILD) -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(PATH_BUILD) --target 3d_viewer

run:
	$(PATH_BUILD)/3d_viewer

uninstall:
	rm -rf $(PATH_BUILD)

clean:
	rm -rf arhive.tar
	rm -rf doxy/documentation
	cmake --build $(PATH_BUILD) --target clean
	# rm -rf $(PATH_REPORT)/* $(PATH_TESTS)/report.info

rebuild: clean all

test:
	git submodule init
	git submodule update
	cmake -B $(PATH_BUILD) -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(PATH_BUILD) --target 3d_viewer_test
	$(PATH_BUILD)/3d_viewer_test

valgrind:
	git submodule init
	git submodule update
	cmake -B $(PATH_BUILD) -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(PATH_BUILD) --target 3d_viewer_test
	valgrind $(PATH_BUILD)/3d_viewer_test


dvi:
	doxygen doxy/doxyfile
	open doxy/documentation/html/index.html

dist:
	tar -cvf arhive.tar .
