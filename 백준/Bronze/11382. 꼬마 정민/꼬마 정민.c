#include <stdio.h>

int main(){
    long long int a, b, c, sum;

    scanf("%lld %lld %lld", &a, &b, &c);
    sum = a + b + c;

    printf("%lld", sum);

    return 0;
}