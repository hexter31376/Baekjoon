#include <stdio.h>

int main(){
    int N, M; // 바구니의 개수, 순서 바꾸는 횟수
    scanf("%d %d", &N, &M);
    int arr[N];

    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }

    for(int i = 0; i < M; i++){
        int start, end, temp;
        scanf("%d %d", &start, &end);
        start--; // 인덱스화
        end--; // 인덱스화
        while(start < end){
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}