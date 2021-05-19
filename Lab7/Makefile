all: main

main:
	echo "7th lab"

coverage:
	g++ -ftest-coverage -fprofile-arcs -O0 -o test tests.cpp employer.cpp applicant.cpp
	./test
	gcov -abcfu applicant.cpp employer.cpp
	git add .
	git commit -m "Lab7 Tests added"
	git push origin master