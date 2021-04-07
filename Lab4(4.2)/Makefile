all: clean main test valgrind_check linter_check

main:
	mkdir -p bin/program
	gcc -std=c89 -o bin/program/main main.c src/string/str.c src/hash_table/hash_table.c src/text/text.c

test:
	./bin/program/main
	diff answer.txt result.txt

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