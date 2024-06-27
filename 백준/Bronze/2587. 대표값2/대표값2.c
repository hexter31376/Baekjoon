#include <stdio.h>
#include <stdlib.h>

int compare_ints (const void* arg1, const void* arg2) {
    int number1 = *(const int*)arg1;
    int number2 = *(const int*)arg2;
    return (number1 > number2) - (number1 < number2); // 1이 크면 양수, 2가 크면 음수, 같으면 0
}

int main () {
    int N = 5;
    int added = 0;

    int arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare_ints);

    for(int i = 0; i < N; i++) {
        added += arr[i];
    }
    added /= 5;
    printf("%d %d\n", added, arr[2]);
    return 0;
}