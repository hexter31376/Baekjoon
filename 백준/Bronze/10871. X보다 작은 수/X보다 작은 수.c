#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    int count = 0;

    int* arr = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < N; i++){
        if(arr[i] < X){
            printf("%d ", arr[i]);
        }
    }

    free(arr);
    return 0;
}