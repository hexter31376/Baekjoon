#include <stdio.h> // 표준 입출력 헤더파일

int main () {
    int N;
    scanf("%d", &N);

    char arr[N + 1];
    for(int i = 0; i < N; i++) {
        scanf("%s", arr);
    }

    int total = 0;

    for(int i = 0; i < N; i++) {
        total += (arr[i] - '0');
    }

    printf("%d", total);
    return 0;
}