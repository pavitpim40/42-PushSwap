/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:32:07 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 20:44:58 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create_stack(char *name)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	new_stack->size = 0;
	new_stack->name = name;
	new_stack->min = INT_MAX;
	new_stack->max = INT_MIN;
	return (new_stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		next = current->prev;
		free(current);
		current = next;
	}
	stack->size = 0;
	free(stack);
}

void	push(t_stack *stack, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return ;
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

void	push_with_rank(t_stack *dst, int data, int rank)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->data = data;
	node->next = NULL;
	node->prev = dst->top;
	node->rank = rank;
	if (data > dst->max)
	{
		dst->max = data;
		dst->max_rank = rank;
	}
	if (data < dst->min)
	{
		dst->min = data;
		dst->min_rank = rank;
	}
	if (dst->top != NULL)
		dst->top->next = node;
	dst->top = node;
	if (dst->size == 0)
		dst->bottom = node;
	dst->size++;
}
