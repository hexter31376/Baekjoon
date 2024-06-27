#include <stdio.h>
#include <stdlib.h>

int compare_ints (const void* arg1, const void* arg2) {
    int number1 = *(const int*)arg1;
    int number2 = *(const int*)arg2;
    return (number1 > number2) - (number1 < number2); // 1이 크면 양수, 2가 크면 음수, 같으면 0
}

int main () {
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare_ints);

    for(int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}