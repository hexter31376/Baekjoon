#include <stdio.h>

int main(){
    int input[9];
    int max = 0;
    int maxIndex;
    for(int i = 0; i < 9; i++){
        scanf("%d", &input[i]);
        if(input[i] > max){
            max = input[i];
            maxIndex = i + 1;
        }
    }
    
    printf("%d\n%d", max, maxIndex);
    return 0;
}