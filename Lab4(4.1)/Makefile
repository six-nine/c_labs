all: clean build_main test valgrind_check linter_check

build_main:
	mkdir -p bin/program
	gcc -std=c89 -o bin/program/main main.c src/string/str.c src/text/text.c 

run:
	./bin/program/main

test:
	./bin/program/main < "tests/test1.txt" > "out1.txt"
	./bin/program/main < "tests/test2.txt" > "out2.txt"
	./bin/program/main < "tests/test3.txt" > "out3.txt"
	diff -u out1.txt tests/ans1.txt
	diff -u out2.txt tests/ans2.txt
	diff -u out3.txt tests/ans3.txt

valgrind_check:
	valgrind --leak-check=full -s ./bin/program/main < "tests/test1.txt"

linter_check:
	cpplint *.c

clean: 
	rm -rf bin/