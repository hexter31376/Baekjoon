#include <stdio.h>

int main(){
    int inputyear;
    scanf("%d", &inputyear);
    if(inputyear % 4 == 0 && !(inputyear % 100 == 0) || inputyear % 400 == 0){
        printf("1");
    } else{
        printf("0");
    }   
    return 0;
}