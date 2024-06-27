#include <stdio.h>
#include <stdlib.h>

int compare_ints (const void* arg1, const void* arg2) {
    int number1 = *(const int*)arg1;
    int number2 = *(const int*)arg2;
    return (number1 < number2) - (number1 > number2); // 내림차순 반전
}

int main () {
    int N, K; // 응시자의 수, 커트라인
    scanf("%d %d", &N, &K);

    int arr[N]; // 응시자 수 만큼의 배열 생성
    for(int i = 0; i < N; i++) { // 원소 입력받기
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare_ints); // 정렬
    printf("%d", arr[K - 1]);
    return 0;
}