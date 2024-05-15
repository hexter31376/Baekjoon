#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++){
        for(int j = N - i; j < N; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}