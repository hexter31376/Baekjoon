#include <stdio.h>
#include <stdlib.h>

int numlen(int inputNum){ // 입력받은 숫자 자리수를 반환
    int len = 0;
    while(!(inputNum == 0)){
        inputNum = inputNum / 10;
        len++;
    }
    return len;
}

void numreturn(int inputNum1, int inputNum2, int* intArr){ // 입력받은 정수의 각 자리수별 곱을 하고 배열에 순서대로 집어넣음

    
    int len = numlen(inputNum2);
    *(intArr + len) = inputNum1 * inputNum2;

    int* arrPtr; // 배열을 지정할 포인터 변수 선언

    for(arrPtr = intArr; arrPtr < intArr + len; arrPtr++){
        *arrPtr = inputNum1 * (inputNum2 % 10);
        inputNum2 = inputNum2 / 10;
    }
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    int bLen = numlen(b); // b의 자리수 반환
    int* mulArr = (int*)malloc(sizeof(int) * (bLen + 1)); // b의 자리수만큼의 동적 정수 배열 생성
    numreturn(a, b, mulArr); //문제 조건 알고리즘 실행

    for(int i = 0; i < bLen + 1; i++){
        printf("%d\n",mulArr[i]);
    }

    free(mulArr);
    return 0;
}

