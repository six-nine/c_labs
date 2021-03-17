all: clean main tests run_tests valgrind_check linter_check

main:
	mkdir -p bin/program
	gcc -std=c89 -o bin/program/main main.c

tests:
	mkdir -p bin/tests
	gcc -std=c89 -o bin/tests/tests -Dmain=_main main.c tests.c

run:
	./bin/program/main

run_tests:
	./bin/tests/tests

valgrind_check:
	mkdir -p bin/temp
	echo "2\n 3\n 4\n 5\n 0\n 7\n" > bin/temp/input.txt
	valgrind ./bin/program/main < bin/temp/input.txt

linter_check:
	cpplint *.c

clean: 
	rm -rf bin/