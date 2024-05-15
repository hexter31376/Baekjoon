/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8393                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: zwonyoung33@gmail.com <boj.kr/u/zwonyoung   +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8393                           #+#        #+#      #+#    */
/*   Solved: 2024/04/25 00:20:17 by zwonyoung33@gm###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int M;
    scanf("%d %d", &N, &M);
    int temp;

    int** nm1 = (int**)malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++){
        nm1[i] = (int*)malloc(sizeof(int) * M);
        for(int j = 0; j < M; j++){
            scanf("%d", &nm1[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &temp);
            nm1[i][j] += temp;
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", nm1[i][j]);
        }
        printf("\n");
    }
    return 0;
}