#include <stdio.h>
#include <stdlib.h>

int compare_ints (const void* arg1, const void* arg2) {
    int number1 = *(const int*)arg1;
    int number2 = *(const int*)arg2;
    return (number1 > number2) - (number1 < number2); // 오름차순 정렬
}

int main () {
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++) { // 원소 입력받기
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare_ints); // 정렬
    for(int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
