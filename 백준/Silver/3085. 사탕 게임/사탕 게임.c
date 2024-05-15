/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3085                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: zwonyoung33@gmail.com <boj.kr/u/zwonyoung   +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3085                           #+#        #+#      #+#    */
/*   Solved: 2024/04/15 20:41:56 by zwonyoung33@gm###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

char** makeNxN(int N){ // 2차원 배열 생성
    char** board = (char**)malloc(sizeof(char*) * N);
    for(int i = 0; i < N; i++){
        board[i] = (char*)malloc(sizeof(char) * N);
    }
    return board;
}

void freeNxN(char** board, int N){ // 2차원 배열 해제
    for(int i = 0; i < N; i++){
        free(board[i]);
    }
    free(board);
}

void inputNxN(char** board, int N){ // 2차원 배열에 값 입력
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf(" %c", &board[i][j]);
        }
    }
}

void change_candy(char* candy1, char* candy2){ // 단순 사탕 교환, bomboni_eachcase에 종속
    char tempcandy;
    tempcandy = *candy1;
    *candy1 = *candy2;
    *candy2 = tempcandy;
}

int bomboni_maxlinescan(char** board, int N){ // 먹을수 있는 가장 긴 길이 반환, bomboni_eachcase에 종속
    int max = 0;
    
    for(int i = 0; i < N; i++){
        int counttemp = 1; // 현재 위치 포함

        for(int j = 1; j < N; j++){ // 범위 초과 방지
            if(board[i][j] == board[i][j-1]){
                counttemp++;
            } else{
                if(max < counttemp){
                    max = counttemp;
                }
                counttemp = 1; // 새로운 블록 시작이므로 초기화
            }
        }

        if(max < counttemp){
            max = counttemp;
        }
    }

    for(int i = 0; i < N; i++){
        int counttemp = 1; // 현재 위치 포함

        for(int j = 1; j < N; j++){ // 범위 초과 방지
            if(board[j][i] == board[j-1][i]){
                counttemp++;
            } else{
                if(max < counttemp){
                    max = counttemp;
                }
                counttemp = 1; // 새로운 블록 시작이므로 초기화
            }
        }

        if(max < counttemp){
            max = counttemp;
        }
    }
    
    return max; // 최대 길이 반환
}

int bomboni(char** board, int N){ // 각 케이스별로 시행
    int max = 0;

    for(int i = 0; i < N; i++){ // 행에서 바꾸기
        for(int j = 0; j < N - 1; j++){ // 범위 초과 방지
            change_candy(&board[i][j], &board[i][j+1]);
            int maxtemp = bomboni_maxlinescan(board, N);
            if(max < maxtemp){
                max = maxtemp;
            }
            change_candy(&board[i][j], &board[i][j+1]);
        }
    }

    for(int j = 0; j < N; j++){ // 열에서 바꾸기
        for(int i = 0; i < N - 1; i++){ // 범위 초과 방지
            change_candy(&board[i][j], &board[i+1][j]);
            int maxtemp = bomboni_maxlinescan(board, N);
            if(max < maxtemp){
                max = maxtemp;
            }
            change_candy(&board[i][j], &board[i+1][j]);
        }
    }

    return max; // 최대 길이 반환
}



int main(){
    int N;
    scanf("%d",&N);
    int max = 0;
    
    char** board = makeNxN(N);
    inputNxN(board, N);
    
    max = bomboni(board, N);

    printf("%d", max);
    
    freeNxN(board, N);
    return 0;
}
