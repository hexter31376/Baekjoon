#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Cxy {
    int x;
    int y;
    int count;
} Cxy;
typedef struct Node {
    Cxy data;
    struct Node *next;
} Node;
typedef struct Queue {
    Node *front;
    Node *rear;
    int count;
} Queue;
void initQueue(Queue *queue) {
    queue->front = queue->rear = NULL;
    queue->count = 0;
}
bool isEmpty(Queue *queue) {
    return queue->count == 0;
}
void enqueue(Queue *queue, Cxy data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;//???
    }
    queue->rear = newNode;
    queue->count++;
}
Cxy dequeue(Queue *queue) {
    Cxy data;
    Node *ptr;
    if (isEmpty(queue)) {
        printf("Error : Queue is empty!\n");
        data.x = 0;
        data.y = 0;
        return data;
    }
    ptr = queue->front;
    data = ptr->data;
    queue->front = ptr->next;
    free(ptr);
    queue->count--;
    return data;
}
int doBFS(int l, Cxy start, Cxy end) {
    int mX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int mY[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    Queue queue;
    bool visited[l][l];
    initQueue(&queue);   
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            visited[i][j] = false;
        }
    }
    enqueue(&queue, start);
    visited[start.x][start.y] = true;
    while (!isEmpty(&queue)) {
        Cxy current = dequeue(&queue);
        if (current.x == end.x && current.y == end.y) {
            return current.count;
        }
        for (int i = 0; i < 8; i++) {
            int newX = current.x + mX[i];
            int newY = current.y + mY[i];
            if (newX >= 0 && newX < l && newY >= 0 && newY < l && !visited[newX][newY]) {
                Cxy next = {newX, newY, current.count + 1};
                enqueue(&queue, next);
                visited[newX][newY] = true;
            }
        } 
    }
}
int main() {
    int caseNum;
    scanf("%d", &caseNum);
    int* caseArr = (int*)malloc(sizeof(int) * caseNum);
    for (int i = 0; i < caseNum; i++) {
        int l;
        Cxy start, end;
        start.count = 0;
        end.count = 0;
        scanf("%d %d %d %d %d", &l, &start.x, &start.y, &end.x, &end.y);
        caseArr[i] = doBFS(l, start, end);
    }
    for(int i;i < caseNum;i++){
        printf("%d\n",caseArr[i]);
    }
    return 0;
}