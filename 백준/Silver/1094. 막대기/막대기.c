#include <stdio.h>

int main () {
    int X, stick = 64, flag_short = 64, cnt = 1; // 각각 입력값, 자른 막대 중 가장 짧은 길이, 막대수
    
    scanf("%d", &X);
    if (X > 64) {
        printf("erorr!");
        return 0;
    }

    while (stick != X) { // 스틱의 길이가 입력값 X 와 같지 않다면 계속
        flag_short /= 2; // 현재 가진 가장 짧은 막대 쪼개서 새 짧은 막대 생성
        stick -= flag_short; // 스틱의 길이에 가장 짧은 막대 길이 빼서 집어넣기
        if (stick < X) { // 이때 막대의 길이가 입력값 X보다 작다면
            stick += flag_short; // 취소하고
            cnt++;// 쪼개는 횟수 추가
        }
    }

    printf ("%d", cnt);
    return 0;
}