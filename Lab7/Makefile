all: main

main:
	echo "7th lab"

coverage:
	rm -rf *.gcda
	rm -rf *.gcov
	g++ -std=c++11 -ftest-coverage -fprofile-arcs -O0 -o test tests.cpp employer.cpp applicant.cpp
	./test
	gcov -abcfu applicant.cpp employer.cpp
#	git add .
#	git commit -m "Lab7 Tests added"
#	git push origin master