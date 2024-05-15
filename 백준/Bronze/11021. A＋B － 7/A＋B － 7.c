#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    int A, B;
    
    int* arr = (int*)malloc(sizeof(int) * T);
    for(int i = 0; i < T; i++){
        scanf("%d %d", &A, &B);
        arr[i] = A + B;
    }
    for(int i = 0; i < T; i++){
        printf("Case #%d: %d\n", i + 1, arr[i]);
    }
    return 0;
}