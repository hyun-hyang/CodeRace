#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int i, j, num, min, idx=0, temp;
  int arr[1000] = {0};
  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    scanf("%d", &arr[i]);
  }
  
  // Selection Sort
  for (i=0; i<num; i++){
    min=9999; // 자릿수 4로 제한
    for (j=i; j<num; j++) {
      if (arr[j]<min){
        min = arr[j];
        idx = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[idx];
    arr[idx] = temp;
  }

  // 결과
  for (i=0; i<num; i++){
    printf("%d\n", arr[i]);
  }

  return 0;
}