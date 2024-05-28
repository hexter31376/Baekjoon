#include <stdio.h> // 표준 입출력 헤더파일
#include <string.h>

int main () {
    char str[101];
    scanf("%s", str);
    printf("%d", strlen(str));
    return 0;
}