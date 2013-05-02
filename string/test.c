#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 255
typedef	unsigned char SString[MAXSTRLEN + 1];

int test(SString );

int main(int argc, char const *argv[])
{
	char * test1 = "strign1";
	char * test2 = "String2";
	SString t;

	t[0] = 'a'; t[1] = 'b'; t[2] = '\0';
	printf("%s\n", t);
	printf("%s\n", test1);

	test(&t);
	printf("%s\n", t);

	return 0;
}

int test(SString *S) {
	(*S)[1] = 'd';
}