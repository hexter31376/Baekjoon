#include <stdio.h>

int main(){
    int H, M, time;
    scanf("%d %d", &H, &M);
    getchar();
    scanf("%d",&time);

    H += (time / 60); //몫은 시간
    M += (time % 60); //나머지는 분

    if(M >= 60){
        H = H + M / 60; //몫은 추가되는 시간
        M = M % 60; // 나머지는 분
    }
    if(H >= 24){
            H = H % 24; // 나머지는 순환되는 24 아래의 수이다.
        }

    printf("%d %d", H, M);
    return 0;
}