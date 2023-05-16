/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:36:01 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 17:19:29 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_next_min_rank(t_stack *src)
{
	t_node	*current;
	int		next_min_rank;

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

int	find_next_min(t_stack *src)
{
	t_node	*current;
	int		next_min;

	current = src->top;
	next_min = INT_MAX;
	while (current)
	{
		if (current->rank != -1 && current->data < next_min)
			next_min = current->data;
		current = current->prev;
	}
	return (next_min);
}

int	find_next_max(t_stack *src)
{
	t_node	*current;
	int		next_max;

	current = src->top;
	next_max = INT_MIN;
	while (current)
	{
		if (current->rank != -1 && current->data > next_max)
			next_max = current->data;
		current = current->prev;
	}
	return (next_max);
}

int	find_next_max_rank(t_stack *src)
{
	t_node	*current;
	int		next_max_rank;

	current = src->top;
	next_max_rank = INT_MIN;
	while (current)
	{
		if (current->rank != -1 && current->rank > next_max_rank)
			next_max_rank = current->rank;
		current = current->prev;
	}
	return (next_max_rank);
}

int	pop(t_stack *stack)
{
	int		data;
	t_node	*temp;

	if (stack->size == 0)
		return (-1);
	data = stack->top->data;
	temp = stack->top;
	stack->top = stack->top->prev;
	if (stack->top != NULL)
	{
		stack->top->next = NULL;
		if (temp->rank == stack->min_rank)
		{
			stack->min_rank = find_next_min_rank(stack);
			stack->min = find_next_min(stack);
		}
		if (temp->rank == stack->max_rank)
		{
			stack->max_rank = find_next_max_rank(stack);
			stack->max = find_next_max(stack);
		}
	}
	stack->size--;
	free(temp);
	return (data);
}

// void	print_stack(t_stack *stack)
// {
// 	t_node *node;

// 	printf("Stack: %s\n", stack->name);
// 	if (!stack)
// 		return ;
// 	node = stack->top;
// 	while (node != NULL)
// 	{
// 		printf("data = %d rank = %d \n", node->data, node->rank);
// 		node = node->prev;
// 	}
// 	printf("\n");
// }