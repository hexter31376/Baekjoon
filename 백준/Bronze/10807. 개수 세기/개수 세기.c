#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int find;
    int count = 0;

    int* arr = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &find);

    for(int i = 0; i < N; i++){
        if(arr[i] == find){
            count++;
        }
    }
    printf("%d", count);
    
    free(arr);
    return 0;
}