#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Fx {
    int C[100];
    int K[100];
};

int main() {
    int n, sum=0;
    scanf("%d",&n);

    struct Fx fx;
    for (int i=0; i<n; i++) {
        scanf("%d", &fx.C[i]);
        scanf("%d", &fx.K[i]);
    }
    for (int i=0; i<n; i++) {
        sum += fx.C[i]*fx.K[i];
    }
    printf("%d", sum);
}