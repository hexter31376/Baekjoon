#include <stdio.h>

int main(){
    int N, M; // N개의 바구니가 있고 M번 던지려고 한다
    scanf("%d %d", &N, &M);

    int arr[N]; // N개의 바구니 정적 할당
    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }

    int ch1, ch2, temp;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &ch1, &ch2);
        temp = arr[ch1 - 1];
        arr[ch1 - 1] = arr[ch2 - 1];
        arr[ch2 - 1] = temp;
    }

    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}