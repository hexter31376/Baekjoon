#include <stdio.h>

int main(){
    int A, B, C, temp;
    scanf("%d %d %d", &A, &B, &C);

    temp = (A+B)%C;
    printf("%d\n", temp);

    temp = ((A%C) + (B%C))%C;
    printf("%d\n", temp);
    
    temp = (A*B)%C;
    printf("%d\n", temp);

    temp = ((A%C) * (B%C))%C;
    printf("%d\n", temp);
    return 0;
}