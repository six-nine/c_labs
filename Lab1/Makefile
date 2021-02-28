all: clean main tests run_tests

main: main.c
	mkdir -p bin/program
	gcc -std=c89 -o bin/program/main main.c

tests: tests.c main.c
	mkdir -p bin/tests
	gcc -std=c89 -o bin/tests/tests -Dmain=_main main.c tests.c

run:
	./bin/program/main

run_tests:
	./bin/tests/tests

clean: 
	rm -rf bin