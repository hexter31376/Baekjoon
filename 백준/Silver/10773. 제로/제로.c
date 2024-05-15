#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* link;
    int data;
} Node;

typedef struct Stack {
    Node* top;
    int count;
} Stack;

int stack_create(Stack** stack) {
    *stack = (Stack*)malloc(sizeof(Stack));
    if (!*stack) {
        return 0;
    }
    else {
        (*stack)->top = NULL;
        (*stack)->count = 0;
        return 1;
    }
}

int push_stack(Stack* stack, int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        return 0;
    }
    else {
        newnode->data = data;
        newnode->link = stack->top;
        stack->top = newnode;
        stack->count++;
        return 1;
    }
}

int pop_stack(Stack* stack) {
    if (!stack->top) {
        return 0;
    }else if(stack->count == 1){
        int datasave = stack->top->data;
        free(stack->top);
        stack->top = NULL;
        stack->count--;
        return datasave;
    } else {
        int datasave = stack->top->data;
        Node* delnode = stack->top;
        stack->top = stack->top->link;
        free(delnode);
        stack->count--;
        return datasave;
    }
}

int main() {
    int K;
    scanf("%d", &K);
    int input;
    int sum = 0;

    Stack* stack;
    stack_create(&stack);

    for (int i = 0; i < K; i++){
        scanf("%d", &input);
        if(input == 0){
            pop_stack(stack);
        } else {
            push_stack(stack, input);
        };
    }
    for(int boolpop = 1;boolpop;){
        boolpop = pop_stack(stack);
        sum += boolpop;
    }
    printf("%d", sum);

    free(stack); // 메모리 해제
    return 0;
}