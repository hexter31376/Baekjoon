#include <stdio.h>
#include <stdlib.h>

int main(){
    int max = 0;
    int maxy;
    int maxx;
    int** array = (int**)malloc(sizeof(int*) * 9);
    for(int i = 0; i < 9; i++){
        array[i] = (int*)malloc(sizeof(int) * 9);
        for(int j = 0; j < 9; j++){
            scanf("%d", &array[i][j]);
            if(max <= array[i][j]){
                max = array[i][j];
                maxy = i + 1;
                maxx = j + 1;
            }
        }
    }
    printf("%d\n%d %d", max, maxy, maxx);
    return 0;
}