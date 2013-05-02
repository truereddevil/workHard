#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	// char s[10] = "trest";
	// char * test = NULL;

	// if (!test) {
	// 	printf("get in\n");
	// }

	// printf("%d\n", strlen(s));
	// return 0;

	int i = 11;
	int const *p = &i; 
	// p++; 
	(*p)++;
	printf("%d", *p);
}