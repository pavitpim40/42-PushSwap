/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:32:07 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 13:04:26 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

Stack *create_stack(char *name)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
	stack->min = INT_MAX;
	stack->max = INT_MIN;
	return stack;
}

void free_stack(Stack *stack) 
{
	// printf("ADD of STACK FREE %p\n", stack);
	if(!stack)
		return;
    Node *current = stack->top;
    Node *next;
    while (current != NULL) {
        next = current->prev;
        free(current);
        current = next;
    }
	stack->size = 0;
    free(stack);
}

void print_stack(Stack* stack) 
{
    printf("Stack: \n");
	if(!stack)
		return;
    Node* node = stack->top;
    while (node != NULL) {
        printf("data = %d rank = %d \n", node->data,node->rank);
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
	// printf("PUSH %d\n",data);
	// printf("STACK->TOP %p\n",stack->top);
	
	// stack is not empty before
	if(stack->top != NULL)
		stack->top->next = node;
	stack->top = node;
	if(stack->size == 0)
		stack->bottom = node;
	stack->size++;
}

void push_with_index(Stack *stack, int data,int rank)
{
	Node* node = (Node *)malloc(sizeof(Node));
	if(node == NULL)
		return;
	
	node->data = data;
	node->rank = -1;
	node->next = NULL;
	printf("DEBUG\n");
	print_stack(stack);
	// printf("stack->top->rank %d\n",sta);
	printf("DEBUG\n");
	node->prev = stack->top; // if 1st element to push ?
		
	node->rank = rank;
	
	// printf("PUSH %d\n",data);
	// printf("STACK->TOP %p\n",stack->top);
	if(data > stack->max)
		stack->max = data;
	if(data < stack->min)
		stack->min = data;
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

