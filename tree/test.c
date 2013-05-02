#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test();

int main(int argc, char const *argv[])
{
	int t = 10;
	printf("%d\n", t);
	test(&t);
	printf("%d\n", t);

	return 0;
}

void test(int * test) {
	*test = 11;
}