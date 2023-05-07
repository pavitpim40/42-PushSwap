/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:32:07 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 15:36:38 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

Stack *create_stack(char *name)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
	return stack;
}

void free_stack(Stack *stack) 
{
    Node *current = stack->top;
    Node *next;
    while (current != NULL) {
        next = current->prev;
        free(current);
        current = next;
    }
    free(stack);
}

void print_stack(Stack* stack) 
{
    printf("Stack: ");
    Node* node = stack->top;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

// Basic Operation
void push(Stack *stack, int data)
{
	Node* node = (Node *)malloc(sizeof(Node));
	if(node == NULL)
		return;
	node->data = data;
	node->next = NULL;
	node->prev = stack->top; // if 1st element to push ?
	// printf("STACK->TOP %p\n",stack->top);
	// stack is not empty before
	if(stack->top != NULL)
		stack->top->next = node;
	stack->top = node;
	if(stack->size == 0)
		stack->bottom = node;
	stack->size++;
}

int	pop(Stack* stack)
{
	if(stack->size == 0)
		return (-1);
	
	int	data = stack->top->data; // ดึง data มาก่อน
	Node *temp = stack->top; // เก็บตัวชี้หัวไว้
	stack->top = stack->top->prev; // เขยิบไปชี้ตัวก่อนหน้า
	if(stack->top != NULL)
		stack->top->next = NULL; // ถ้ามีตัว top ให้ชี้ไปที่ null
	stack->size--;
	free(temp);
	return data;
}
