#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    int* output = (int*)malloc(sizeof(int) * N);
    int input1, input2;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &input1, &input2);
        output[i] = input1 + input2;
    }
    for(int i = 0; i < N; i++){
        printf("%d\n", output[i]);
    }
    free(output);
    return 0;
}