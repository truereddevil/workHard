#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*String1.c: implements the datastructure of string in P73*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSTRLEN 255
typedef int Status;
typedef	unsigned char SString[MAXSTRLEN + 1];

Status StrAssign(SString T, char *s);
Status PrintString(SString T);
Status Concat(SString T, SString S1, SString S2);
Status StringCopy(SString T, char *s, int length);
Status Index(SString S, SString T, int pos);

int main(int argc, char const *argv[])
{
	int pos;
	char * test1 = "test";
	char * test2 = "SStest";
	SString t, s1, s2;
	unsigned char testArr[10];

	// printf("%d\n", strlen(test1));

	StrAssign(s1, test1);
	StrAssign(s2, test2);
	pos = Index(s2, s1, 1);
	printf("%d\n", pos);

	return 0;
}

Status StrAssign(SString T, char *s) {
	int length = strlen(s);
	if (length > MAXSTRLEN) {
		StringCopy(T, s, MAXSTRLEN);
	} else {
		StringCopy(T, s, length);
	}
}

Status Concat(SString T, SString S1, SString S2) {

}

Status PrintString(SString T) {
	int i;

	printf("%d---", T[0]);

	for (i = 1; i <= T[0]; i++) {
		printf("%c", T[i]);		
	}

	printf("\n");
}

Status StringCopy(SString T, char *s, int length) {
	int i;

	T[0] = length;

	for (i = 1; i <= length; i++) {
		T[i] = s[i-1];
	}
}

int Index(SString S, SString T, int pos) {
	PrintString(S);
	PrintString(T);

	int i = pos, j = 1;

	while (i <= S[0] && j <= T[0]) {
		printf("i--%d, j--%d\n", i, j);
		printf("S[i]--%c, T[j]--%c\n", S[i], T[j]);
		if (S[i] == T[j]) { 
			++i; ++j;
		}
		else {
			// printf("%d\n", i);
			i = i - j + 2; j = 1;
		}
	}

	if (j > T[0])	return i - T[0];
	else	return 0;
}

int Index_KMP(SString S, SString T, int pos) {
	PrintString(S);
	PrintString(T);

	int i = pos, j = 1;

	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) { 
			++i; ++j;
		}
		else {
			// printf("%d\n", i);
			j = next[j];
		}
	}

	if (j > T[0])	return i - T[0];
	else	return 0;
}