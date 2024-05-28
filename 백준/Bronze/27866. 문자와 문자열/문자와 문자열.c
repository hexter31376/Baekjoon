#include <stdio.h> // 표준 입출력 헤더파일

int main () {
    int index;
    char str[1001];
    scanf("%s %d", str, &index);

    printf("%c", str[index - 1]);
    return 0;
}