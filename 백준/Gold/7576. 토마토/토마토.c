#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Datatype Coordinate

typedef struct Coordinate {
    int x, y;
} Coordinate;

typedef struct Node { // 노드의 정의
    Datatype data; // 데이터
    struct Node* link; // 다음 노드
} Node;

typedef struct { // 큐의 정의
    Node* front; // 출구
    Node* rear; // 입구
    int count; // 큐의 개수
} Queue;

void init_queue(Queue* queue) {
    queue->front = queue->rear = NULL;
    queue->count = 0;
}

bool is_queue_empty(Queue* queue) {
    return queue->count == 0;
}

Node* create_node(Datatype data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        return NULL;
    }
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void push_queue(Queue* queue, Datatype data) {
    Node* newnode = create_node(data);
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    if (is_queue_empty(queue)) {
        queue->front = newnode;
    } else {
        queue->rear->link = newnode;
    }
    queue->rear = newnode;
    queue->count++;
}

Datatype pop_queue(Queue* queue) {
    Node* popNode;
    Datatype popData;
    if (is_queue_empty(queue)) {
        printf("queue underflow\n");
        exit(1); // 프로그램 종료
    } else {
        popNode = queue->front;
        popData = popNode->data;
        queue->front = popNode->link;
        free(popNode);
        queue->count--;
        return popData;
    }
}

int tomato_dfs(int** array, int M, int N) {
    Queue queue;
    init_queue(&queue);

    // dfs 점화식: 순차적으로 순회하면서 값이 1이면 큐에 집어넣는다.
    Coordinate start; // 시작 레벨의 1값을 큐에 집어넣을 start

    for (int i = 0; i < N; i++) { // M * N 배열 순차적 순회
        for (int j = 0; j < M; j++) {
            if (array[i][j] == 1) {
                start.x = j; // 현재의 가로 좌표 삽입
                start.y = i; // 현재의 세로 좌표 삽입
                push_queue(&queue, start);
            }
        }
    }

    // 현재 위치에서의 이동 방향 정의
    int moveX[4] = {1, 0, -1, 0};
    int moveY[4] = {0, -1, 0, 1};

    // dfs 반복식: 큐가 빌 때까지 큐를 제거하면서 갈 수 있는 위치(0인 곳)를 전부 현재 위치 + 1한 값을 넣어주고 그 위치 큐에 넣기
    while (!is_queue_empty(&queue)) {
        Coordinate nowXY = pop_queue(&queue); // 현재 위치의 좌표를 pop한 결과로 확인
        Coordinate canXY;
        for (int i = 0; i < 4; i++) { // 4방향 탐색
            canXY.x = nowXY.x + moveX[i]; // 이동한 방향 임시 저장
            canXY.y = nowXY.y + moveY[i]; // 이동한 방향 임시 저장
            // 배열 범위를 벗어나지 않도록 체크
            if (canXY.x >= 0 && canXY.x < M && canXY.y >= 0 && canXY.y < N && array[canXY.y][canXY.x] == 0) {
                array[canXY.y][canXY.x] = array[nowXY.y][nowXY.x] + 1; // 현재 좌표의 값에 +1을 한 값을 0인 위치에 저장
                push_queue(&queue, canXY);
            }
        }
    }

    int max = -1;
    // 가장 높은 숫자 탐색 후 반환: 0이 있으면 모든 토마토가 다 익을 순 없으니 거짓, 0이 없으면 가장 큰 수가 해답
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (array[i][j] == 0) {
                return -1;
            } else if (max < array[i][j]) {
                max = array[i][j];
            }
        }
    }
    return max - 1; // 첫날을 포함했으므로 1을 뺀다.
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N); // 가로 길이와 세로 길이 입력받기

    // N * M 정수 배열 생성
    int** array = (int**)malloc(sizeof(int*) * N); // N열
    for (int i = 0; i < N; i++) {
        array[i] = (int*)malloc(sizeof(int) * M); // M행
        for (int j = 0; j < M; j++) { // 사용자에게 배열 요소 입력받기
            scanf("%d", &array[i][j]);
        }
    }

    int day; // 원하는 답

    // 토마토 dfs 함수 호출
    day = tomato_dfs(array, M, N);

    printf("%d\n", day);

    // 동적 할당 해제
    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}
