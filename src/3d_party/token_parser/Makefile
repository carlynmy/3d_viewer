
PATH_BUILD=build

all:
	cmake -B $(PATH_BUILD) -DCMAKE_BUILD_TYPE=Debug
	cd $(PATH_BUILD);make

clean:
	rm -rf $(PATH_BUILD)

rebuild: clean all

test:
