#include <stdio.h>

int main(){
    int H, M;

    scanf("%d %d", &H, &M);
    M -= 45;

    if(M < 0){
        if(H <= 0){
            H += 24;
        }
        H -= 1;
        M += 60;
        printf("%d %d",H, M);
    } else{
        printf("%d %d",H, M);
    }

    return 0;
}