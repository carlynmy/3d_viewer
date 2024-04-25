PATH_BUILD=build

.PHONY: all clean rebuild matrix.a test gcov_report valgrind leaks

all: libmatrix.a

clean:
	rm -rf $(PATH_BUILD)

rebuild: clean all

libmatrix.a:
	cmake -B $(PATH_BUILD) -DCMAKE_BUILD_TYPE=Debug 
	cmake --build $(PATH_BUILD)

test:
	cmake -B $(PATH_BUILD) -DCMAKE_BUILD_TYPE=Debug 
	cmake --build $(PATH_BUILD) --target matrix_tests
	./$(PATH_BUILD)/matrix_tests

gcov_report:
	cmake -B $(PATH_BUILD) -DCMAKE_BUILD_TYPE=Debug -DCOVERAGE_FLAGS:STRING="-lgcov --coverage"
	gcovr --html-details -o $(PATH_REPORT)/index.html
	open $(PATH_REPORT)/index.html
