#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d", facto(n));
}

int facto(int n) {
    if (n==0) return 1;
    else {
        return n*facto(n-1);
    }
}