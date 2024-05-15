#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checker(char str[], int len){
    int Alphabet[26]; // 알파벳을 인덱스 넘버로 지정할 정수 배열 선언
    for(int i = 0; i < 26; i++){ // 알파벳 인덱스 배열 초기화
        Alphabet[i] = 0; // 0으로 초기화
    }

    for(int i = 0; i < len; i++){
        if(Alphabet[str[i] - 'a'] == 0){ // 알파벳이 한번도 안나왔다면
            Alphabet[str[i] - 'a'] = 1; // 알파벳을 방문했음을 표시
        } else if(str[i-1] - 'a' != str[i] - 'a'){ // 앞 문자와 다르다면
                return 0; // 그룹 체커가 아님
        } else { // 앞 문자와 같으면
            continue; // 계속하기
        }
    }

    return 1; // 여기까지 오면 그룹 체커가 맞음
}

int main(){
    int N;
    scanf("%d", &N);
    int output = 0;

    for(int i = 0; i < N; i++){
        char str[101];
        scanf("%s", str);
        int len = strlen(str);
        output += checker(str, len);
    }
    printf("%d", output);
    return 0;
}