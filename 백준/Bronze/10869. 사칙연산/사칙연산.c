# include <stdio.h>

int main(){

    int A, B;
    int plus, minus, multiply, divide, remain;

    scanf("%d %d", &A, &B);

    plus = A + B;
    minus = A - B;
    multiply = A * B;
    divide = A / B;
    remain = A % B;

    printf("%d\n%d\n%d\n%d\n%d", plus, minus, multiply, divide, remain);
    return 0;
}