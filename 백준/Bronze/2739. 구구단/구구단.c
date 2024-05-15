#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= 9; i++){
        int value = N * i;
        printf("%d * %d = %d\n", N, i, value);
    }

    return 0;
}