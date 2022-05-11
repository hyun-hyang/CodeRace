
#include <stdio.h>
#include <string.h>
#define MAX 5

int round;
int A[MAX], B[MAX];
int numA, numB, idx;
char result;

int main() {
    scanf("%d", &round);
    for (round>0; round--;) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        scanf("%d", &numA);
        for(int i=1; i<=numA; i++) {
            scanf("%d", &idx);
            A[idx]++;
        }

        scanf("%d", &numB);
        for(int i=1; i<=numB; i++) {
            scanf("%d", &idx);
            B[idx]++;
        }

        result = 'D';
        for (int i=4; i>0; i--) {
            if (A[i]>B[i]) {
                result = 'A';
                break;
            }
            else if (A[i]<B[i]) {
                result = 'B';
                break;
            }
        }
        printf("%c\n", result);
    }
}