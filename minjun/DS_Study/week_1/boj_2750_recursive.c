#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i, j, num;
    int arr[1000] = {0};
    scanf("%d", &num);
    

    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    SelectionSort(arr, num);

    for (i=0; i<num; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}

int SelectionSort(int a[], int n) {
    int m_idx=0, j, temp;

    if (n == 1) {
        return 0;
    }
    
    for (j=0; j<n; j++) {
        if (a[m_idx] > a[j]) m_idx = j;
    }

    temp = a[0];
    a[0] = a[m_idx];
    a[m_idx] = temp;

    SelectionSort(a+1,n-1);
}