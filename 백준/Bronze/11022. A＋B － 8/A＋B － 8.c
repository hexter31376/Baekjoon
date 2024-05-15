#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    
    int** arr = (int**)malloc(sizeof(int*) * T);
    for(int i = 0; i < T; i++){
        arr[i] = (int*)malloc(sizeof(int) * 3);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        arr[i][2] = arr[i][0] + arr[i][1];
    }

    for(int i = 0; i < T; i++){
        printf("Case #%d: %d + %d = %d\n", i + 1, arr[i][0], arr[i][1], arr[i][2]);
        free(arr[i]);
    }
    free(arr);
    return 0;
}