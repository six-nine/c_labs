all: clean main tests run_tests valgrind_check linter_check

main:
	mkdir -p bin/program
	gcc -std=c89 -o bin/program/main main.c matrix_memory.c

tests:
	mkdir -p bin/tests
	gcc -std=c89 -o bin/tests/tests -Dmain=_main main.c tests.c matrix_memory.c

run:
	./bin/program/main

run_tests:
	./bin/tests/tests

valgrind_check:
	valgrind ./bin/tests/tests 

linter_check:
	cpplint *.c

clean: 
	rm -rf bin/