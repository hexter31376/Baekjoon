#include <stdio.h>
#include <string.h>

typedef struct Subdata {
    char name[51]; // 과목 이름
    double credit; // 학점 (double로 변경)
    char grade[3]; // 등급
} Subdata;

int main() {
    Subdata subdata[20];
    double creditMulgrade = 0.0; // 학점 * 등급 (double로 변경)
    double creditadd = 0.0; // 총 학점 (double로 변경)

    // 과목 정보 입력
    for (int i = 0; i < 20; i++) {
        double grade = 0.0; // 과목 등급
        scanf("%s %lf %s", subdata[i].name, &subdata[i].credit, subdata[i].grade); // 학점 입력 형식을 %lf로 변경
        getchar();

        // 등급 문자열을 숫자 값으로 변환
        if (strcmp(subdata[i].grade, "A+") == 0) {
            grade = 4.5;
        } else if (strcmp(subdata[i].grade, "A0") == 0) {
            grade = 4.0;
        } else if (strcmp(subdata[i].grade, "B+") == 0) {
            grade = 3.5;
        } else if (strcmp(subdata[i].grade, "B0") == 0) {
            grade = 3.0;
        } else if (strcmp(subdata[i].grade, "C+") == 0) {
            grade = 2.5;
        } else if (strcmp(subdata[i].grade, "C0") == 0) {
            grade = 2.0;
        } else if (strcmp(subdata[i].grade, "D+") == 0) {
            grade = 1.5;
        } else if (strcmp(subdata[i].grade, "D0") == 0) {
            grade = 1.0;
        } else if (strcmp(subdata[i].grade, "F") == 0) {
            grade = 0.0;
        } else if (strcmp(subdata[i].grade, "P") == 0) {
            subdata[i].credit = 0.0; // Pass는 학점을 0으로 설정 (double로 변경)
        }
        
        // 총합 계산
        creditMulgrade += (grade * subdata[i].credit);
        creditadd += subdata[i].credit;
    }
    
    // GPA 계산 및 출력
    double output = creditMulgrade / creditadd;
    printf("%lf", output); 
    return 0;
}