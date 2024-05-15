#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, B, C;
    while(scanf("%d %d", &A, &B) != -1){
        C = A + B;
        printf("%d\n", C);
    }
    return 0;
}