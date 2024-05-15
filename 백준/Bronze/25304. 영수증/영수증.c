#include <stdio.h>

int main(){
    int bill;
    int N;
    scanf("%d %d", &bill, &N);
    int total = 0;
    int temprice;
    int tempnum;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &temprice, &tempnum);
        total += temprice * tempnum;
    }
    if(total == bill){
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}