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
        printf("-1\n");
        return 0;
    }
    else {
        printf("%d\n", stack->top->data);
        Node* delnode = stack->top;
        stack->top = stack->top->link;
        free(delnode);
        stack->count--;
        return 1;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int input, inputdata;

    Stack* stack;
    stack_create(&stack);

    for (int i = 0; i < N; i++) {
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            scanf("%d", &inputdata);
            push_stack(stack, inputdata);
            break;
        case 2:
            pop_stack(stack);
            break;
        case 3:
            printf("%d\n", stack->count);
            break;
        case 4:
            printf("%d\n", !stack->top ? 1 : 0);
            break;
        case 5:
            printf("%d\n", !stack->top ? -1 : stack->top->data);
            break;
        default:
            break;
        }
    }

    free(stack); // 메모리 해제
    return 0;
}