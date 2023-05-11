/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:32:07 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 02:49:45 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

Stack *create_stack(char *name)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if (stack == NULL)
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
	if (!stack)
		return;
	Node *current = stack->top;
	Node *next;
	while (current != NULL)
	{
		next = current->prev;
		free(current);
		current = next;
	}
	stack->size = 0;
	free(stack);
}

void print_stack(Stack *stack)
{
	printf("Stack: \n");
	if (!stack)
		return;
	Node *node = stack->top;
	while (node != NULL)
	{
		printf("data = %d rank = %d \n", node->data, node->rank);
		node = node->prev;
	}
	printf("\n");
}

void push(Stack *stack, int data)
{
	Node *node;

	node = (Node *)malloc(sizeof(Node));
	if (node == NULL)
		return;
	node->data = data;
	node->next = NULL;
	node->prev = stack->top;

	if (stack->top != NULL)
		stack->top->next = node;
	stack->top = node;
	if (stack->size == 0)
		stack->bottom = node;
	stack->size++;
}

void push_with_rank(Stack *dst, int data, int rank)
{
	Node *node;

	node = (Node *)malloc(sizeof(Node));
	if (node == NULL)
		return;
	node->data = data;
	node->next = NULL;
	node->prev = dst->top;
	node->rank = rank;

	if (data > dst->max)
		dst->max = data;
	if (data < dst->min)
		dst->min = data;
	if (dst->top != NULL)
		dst->top->next = node;
	dst->top = node;
	if (dst->size == 0)
		dst->bottom = node;
	dst->size++;
}

int find_next_min_rank(Stack *src)
{
	Node *current;
	int next_min_rank;

	current = src->top;
	next_min_rank = INT_MAX;
	while (current)
	{
		if (current->rank != -1 && current->rank < next_min_rank)
			next_min_rank = current->rank;
		current = current->prev;
	}
	return (next_min_rank);
}

int pop(Stack *stack)
{
	if (stack->size == 0)
		return (-1);
	int data = stack->top->data;
	Node *temp = stack->top;
	stack->top = stack->top->prev;
	if (stack->top != NULL)
	{
		stack->top->next = NULL;
		if (temp->rank == stack->min_rank)
			stack->min_rank = find_next_min_rank(stack);
	}
	stack->size--;
	free(temp);
	return data;
}

//