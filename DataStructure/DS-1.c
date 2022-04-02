#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DEGREE 8 

// 지수오름순으로 저장해야함.
// 지수범위 0~8 <A,B,D에 모두 적용>
// D의 항의 수가 9개 미만,
// 즉 최대 지수가 8이 되도록 고려해서 A,B를 입력

typedef struct {
	int coef;
} Polynomial;

int exp[MAX_DEGREE + 1] = {0,1,2,3,4,5,6,7,8};

void SplitAndSave(char Ax[], char *AxArr[]);

int main() {
	// 구조체 A, B, D 생성
	Polynomial A[MAX_DEGREE + 1] = { 0, };
	Polynomial B[MAX_DEGREE + 1] = { 0, };
	Polynomial D[MAX_DEGREE + 1] = { 0, };
	
	
	// 입력 예제
	//A = 2x5 +7x2 -4x0;
	//B = 6x3 +2xl +9x0;
	//D = 12x8 +4x6 +60x5 -10x3 +63x2 –8x1 -36x0

	// A, B 식 입력
	char Ax[20], Bx[20];
	fgets(Ax, sizeof(Ax), stdin);
	fgets(Bx, sizeof(Bx), stdin);
	
	// A, B 식을 Array로 받을 변수들 
	// x를 기준으로 지수와 계수를 분리해서 저장
	char *AxArr[6] = {NULL,};
	char *BxArr[6] = {NULL,};
	
	// 기존 Ax, Bx를 AxArr, BxArr로 변환하는 함수
	SplitAndSave(Ax, AxArr);
	SplitAndSave(Bx, BxArr);

	// 변환한 각각의 식을 지수 오름순으로 각 구조체에 저장
	int expA = 0, expB = 0;
	for (int i = 5; i >= 0; i--) {
		if (i % 2 == 1) {
			expA = atoi(AxArr[i]);
			expB = atoi(BxArr[i]);
		}
		else {
			A[expA].coef = atoi(AxArr[i]);
			B[expB].coef = atoi(BxArr[i]);
		}
	}

	// A와 B를 지정된 표현방법(구조체 지수오름순)으로 저장한 모습을 출력
	//(+)부호 생략
	printf("A: ");
	for (int i = 0; i < 9; i++) {
		printf("%dx%d ", A[i].coef, exp[i]);
	}
	printf("\n");
	printf("B: ");
	for (int i = 0; i < 9; i++) {
		printf("%dx%d ", B[i].coef, exp[i]);
	}
	printf("\n");

	// D 계산
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (A[i].coef != 0 && B[j].coef != 0) {
				int mulCoef = A[i].coef * B[i].coef;
				int mulExp = exp[i] + exp[j];

				if (D[mulExp].coef == 0)
					D[mulExp].coef = mulCoef;
				else 
					D[mulExp].coef += mulCoef;
			}
		}
	}
	printf("D: ");
	for (int i = 0; i < 9; i++) {
		printf("%dx%d ", D[i].coef, exp[i]);
	}
}

// x를 기준으로 지수와 계수를 저장해주는 함수
void SplitAndSave(char x[], char *xArr[]) {
	int idx = 0;
	char* ptr = strtok(x, " x");
	while (ptr != NULL) {
		xArr[idx] = ptr;
		idx++;
		ptr = strtok(NULL, " x");
	}
	/*for (int i = 0; i < 6; i++) {
		printf("%s\n", xArr[i]);
	}*/
}
