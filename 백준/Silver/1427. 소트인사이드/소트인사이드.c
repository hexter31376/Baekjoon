#include <stdio.h>
#include <string.h>

void selection_sort (char input[]) {
    int len = strlen(input);

    for (int i = len - 1; i > 0; i--) { // len - 1 부터 시작
        int min = 0; // 최댓값의 인덱스 초기화

        for(int j = 1; j <= i; j++) { // 현재 부분 배열에서 최댓값 찾기
            if(input[j] < input[min]) {
                min = j;
            }
        }
        // 최댓값을 현재 정렬되지 않은 부분의 끝으로 이동
        char temp = input[min];
        input[min] = input[i];
        input[i] = temp;
    }
}

int main () {
    char input[10];
    scanf("%s", input);
    int output;

    selection_sort(input);

    printf("%s", input);
    return 0;
}