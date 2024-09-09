# include <stdio.h>
# include <string.h>

int main (void) {
    // 소문자 97~122

    // 문자열 입력받고 문자열 길이 저장
    char inputString[101];
    scanf("%100s", inputString);
    int inputStringLen = strlen(inputString);

    // 알파벳 배열 선언 및 -1 초기화
    int alphabet[26];
    for (int i =0; i < 26; i++) {
        alphabet[i] = -1;
    }

    // 입력 배열 순회 및 최초 알파벳 위치 alphabet 배열에 집어넣기
    for (int i = 0; i < inputStringLen; i++) {
        if (alphabet[inputString[i] - 97] == -1) {
            alphabet[inputString[i] - 97] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", alphabet[i]);
    }
    
    return 0;
}