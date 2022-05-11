#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, K;
int Pi[100000];
int sumPi[100000];

int main() {
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i=0; i<N; i++) {
        scanf("%d", &Pi[i]);
    }

    for (int i=0; i<N; i++) {

        if (i<N-K){
            sumPi[i]=0;
            for (int j=0; j<K; j++) {
                sumPi[i] = sumPi[i] + Pi[j];
            }
        }
        else {
            int left = i-(N-K);
            sumPi[i]=0;
            for (int j=N-K+1; j<N; j++){
                sumPi[i] = sumPi[i] + Pi[j];
            }
            for (int j=0; j<left; j++){
                sumPi[i] = sumPi[i] + Pi[j];
            }
        }
        
    }
    int max = sumPi[0];
    for (int i=0; i<N; i++) {
        if(max<sumPi[i]) max=sumPi[i];
    }
    printf("%d", max);
}