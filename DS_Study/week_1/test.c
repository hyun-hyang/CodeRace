#include <stdio.h>

int main() {
    int arr[5] = {4,3,5,2,1};
    SelectionSort(arr, 5);

    for (int i=0; i<5; i++){
        printf("%d\n", arr[i]);
    }
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

    return 0;
}