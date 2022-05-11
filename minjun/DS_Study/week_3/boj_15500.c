#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 150

int st1[MAX_SIZE] = {0}, st2[MAX_SIZE] = {0};
int idx1=0, idx2=0;
int n;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &st1[i]);
    }

    idx1 = n-1;

    while (idx1>0 || idx2>0){
        if (idx1>0 && idx2==0) {
            while (st1[0]!=0) {
                int circle = st1[idx1];
                if (circle==n) {
                    st1[idx1]=0;
                    printf("1 3\n");
                    idx1--;
                    n--;
                }
                else {
                    st2[idx2] = circle;
                    st1[idx1] = 0;
                    printf("1 2\n");
                    idx1--;
                    idx2++;
                }
            }
        }
        else {
            idx2--;
            while (st2[0]!=0) {
                int circle = st2[idx2];
                if (circle ==n) {
                    st2[idx2] = 0;
                    printf("2 3\n");
                    idx2--;
                    n--;
                }
                else {
                    st2[idx1] = circle;
                    st1[idx2] = 0;
                    printf("2 1\n");
                    idx2--;
                    idx1++;
                }
            }
        }
    }
    
}