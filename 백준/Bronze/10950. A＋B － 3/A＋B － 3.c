#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    int input1, input2;
    int* inputArr = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &input1, &input2);
        inputArr[i] = input1 + input2;
    }
    for(int i = 0; i < N; i++){
        printf("%d\n", inputArr[i]);
    }
    return 0;
}