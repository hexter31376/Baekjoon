#include <stdio.h>

int main(){
    int N, M; // N개의 바구니가 있고 M번 던지려고 한다
    scanf("%d %d", &N, &M);

    int arr[N]; // N개의 바구니 정적 할당
    for(int i = 0; i < N; i++){
        arr[i] = 0;
    }

    int i, j, k; // 범위 i, j와 넣을 공의 번호 k
    for(int in = 0; in < M; in++){
        scanf("%d %d %d", &i, &j, &k);
        for(;i - 1 < j; i++){
            arr[i - 1] = k;
        }

    }

    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}