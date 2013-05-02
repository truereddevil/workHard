#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_space_num(char *);
void expand_str(char *, int, int);

int main(int argc, char const *argv[])
{
	char s[100] = "This is a test!";
	int s_len = strlen(s), s_expend_len, space_num;

	space_num = find_space_num(s);
	printf("%d\n", space_num);

	expand_str(s, s_len, space_num);
	printf("%s\n", s);

	return 0;
}

int find_space_num(char * str) {
	int i = 0, space_num = 0;

	for (;*(str+i) != '\0'; i++) {
		if (*(str+i) == ' ') {
			space_num++;
		}
	}

	return space_num;
}

void expand_str(char * str, int length, int space_num) {
	int expand_len = length + 2*space_num;

	int front_cursor = length, rear_cursor = expand_len;

	for(; front_cursor != 0; front_cursor--) {
		if (*(str + front_cursor) != ' ') {
			*(str + rear_cursor) = *(str + front_cursor);
			rear_cursor--;
		} else {
			*(str + rear_cursor) = '0';
			*(str + rear_cursor - 1) = '2';
			*(str + rear_cursor - 2) = '%';
			rear_cursor -= 3;
		}
	}
}