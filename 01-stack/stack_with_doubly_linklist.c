#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct {
    Node* top;
    Node* bottom;
    int size;
} Stack;

void push(Stack* stack, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = stack->top;
    if (stack->top != NULL) {
        stack->top->next = node;
    }
    stack->top = node;
    if (stack->size == 0) {
        stack->bottom = node;
    }
    stack->size++;
}

int pop(Stack* stack) {
    if (stack->size == 0) {
        printf("Error: Stack is empty.\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->prev;
    if (stack->top != NULL) {
        stack->top->next = NULL;
    }
    stack->size--;
    free(temp);
    return data;
}

void print_stack(Stack* stack) {
    printf("Stack: ");
    Node* node = stack->top;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

void swap_first_two(Stack* stack) {
    if (stack->size < 2) {
        printf("Error: Stack has less than two elements.\n");
        return;
    }
    Node* first = stack->top;
    Node* second = first->prev;
    Node* temp = second->prev;
    first->prev = temp;
    if (temp != NULL) {
        temp->next = first;
    }
    second->prev = first;
    second->next = first->next;
    first->next = second;
    if (second->next != NULL) {
        second->next->prev = second;
    }
    if (stack->bottom == first) {
        stack->bottom = second;
    } else if (stack->bottom == second) {
        stack->bottom = first;
    }
}


int main() {
    Stack stack = {NULL, NULL, 0};

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    print_stack(&stack);

    swap_first_two(&stack);
    print_stack(&stack);

}