#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int N;
    scanf("%lld", &N);
    long long int output;

    long long int* arr = (long long int*)malloc(sizeof(long long int) * N);

    for (long long int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    long long int max = arr[0];
    long long int min = arr[0];

    for (long long int i = 1; i < N; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    output = min * max;
    printf("%lld\n", output);

    free(arr); // 메모리 해제

    return 0;
}