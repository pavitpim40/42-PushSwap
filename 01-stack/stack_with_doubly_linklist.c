# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


typedef struct Stack {
    Node* top;
    int size;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}



void push(Stack* stack, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = stack->top;
    if (stack->top != NULL) {
        stack->top->prev = new_node;
    }
    stack->top = new_node;
    stack->size++;
}

void pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }
    free(temp);
    stack->size--;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    Stack* stack_A = create_stack();
    push(stack_A, 10);
    push(stack_A, 20);
    push(stack_A, 30);
    printf("%d\n", peek(stack_A));
    pop(stack_A);
    printf("%d\n", peek(stack_A));
    pop(stack_A);
    printf("%d\n", peek(stack_A));
    pop(stack_A);
    printf("%d\n", peek(stack_A));
    pop(stack_A);
    return 0;
}