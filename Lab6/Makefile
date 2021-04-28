all: clean main tests run_tests valgrind_check linter_check

main:
	mkdir -p bin/program
	g++ -o bin/program/main main.cpp -std=c++17

tests:
	mkdir -p bin/tests
	g++ -o bin/tests/tests tests.cpp -std=c++17

run:
	./bin/program/main

run_tests:
	./bin/tests/tests

valgrind_check:
	valgrind ./bin/tests/tests

linter_check:
	cpplint *.cpp

clean:
	rm -rf bin/