#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void StarRecursive(int i, int j, int N);

int main(void)
{
	int N, i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			StarRecursive(i, j, N);
		}
		printf("\n");
	}
	return 0;
}

void StarRecursive(int i, int j, int N) {
	if ((i / N) % 3 == 1 && (j / N) % 3 == 1) printf(" ");
	else{
		if (N / 3 == 0) printf("*");
		else StarRecursive(i, j, N / 3);
	}
}