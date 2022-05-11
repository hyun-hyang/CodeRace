#include <stdio.h>
#include <string.h>

#define MAX_LEGNTH 100

int main() {
	char str[MAX_LEGNTH];
	int result = 1;
	
	scanf("%s", str);

	for (int i = 0; i < strlen(str) / 2; i++) {
		if (str[i] != str[strlen(str) - 1 - i])
			result = 0;
	}

	if (result)
		printf("1");
	else
		printf("0");

	return 0;
}