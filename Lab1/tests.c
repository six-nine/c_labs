#include <assert.h>
#include <stdio.h>
#include "main.h"

void test() {
	assert(is_perfect(6) == 1);
	assert(is_perfect(1) == 0);
	assert(is_perfect(8128) == 1);
	assert(is_perfect(496) == 1);
	assert(is_perfect(105) == 0);
	assert(is_perfect(106) == 0);
	assert(is_perfect(1000000) == 0);
	assert(is_perfect(-5) == 0);
	assert(is_perfect(199999) == 0);
	printf("All tests are passed.\n");
}
#undef main

int main() {
	test();
	return 0;
}