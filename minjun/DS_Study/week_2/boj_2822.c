#include <stdio.h>
 
struct quiz {
    int n;
    int score;
};
 
int main() {
    struct quiz p[8];
    struct quiz tmp;
    int i, j, max, min, sum = 0;
    
    for (i = 0; i < 8; i++) {
        p[i].n = i + 1;
        scanf("%d", &p[i].score);
    }
    
    for (i = 0; i < 5; i++) {
        max = i;
        for (j = i+1; j < 8; j++) {
            if (p[max].score < p[j].score) max = j;
        }
        if (i != max) {
            tmp = p[i];
            p[i] = p[max];
            p[max] = tmp;
        }
    }
    
    for (i = 0; i < 5; i++) {
        min = i;
        for (j = i + 1; j < 5; j++) {
            if (p[min].n > p[j].n) min = j;
        }
        if (i != min) {
            tmp = p[i];
            p[i] = p[min];
            p[min] = tmp;
        }
        
        sum += p[i].score;
    }
    printf("%d\n", sum );
    for (i = 0; i < 5; i++)
        printf("%d ", p[i].n);
    printf("\n");
    return 0;
}
