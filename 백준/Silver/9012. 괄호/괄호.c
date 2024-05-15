#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define Datatype char

typedef struct Node {
    struct Node* link;
    Datatype data;
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

int push_stack(Stack* stack, Datatype data) {
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

Datatype pop_stack(Stack* stack) {
    if (!stack->top) {
        return '\0';
    } else {
        Datatype datasave = stack->top->data;
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
    char arr[51];

    Stack* stack;
    stack_create(&stack);
    
    for(int i = 0; i < K; i++) {
        bool yesOrNo = true;

        scanf("%s", arr);
        int len = strlen(arr);
        for(int j = 0; j < len; j++) {
            if(arr[j] == '(') {
                push_stack(stack, arr[j]);
            } else if (arr[j] == ')') {
                Datatype compTemp = pop_stack(stack);
                if(compTemp != '(') {
                    yesOrNo = false;
                    break;
                }
            }
        }

        if(yesOrNo && stack->count == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
            while(stack->top != NULL) {
                pop_stack(stack);
            }
        }
    }
    free(stack);
    return 0;
}