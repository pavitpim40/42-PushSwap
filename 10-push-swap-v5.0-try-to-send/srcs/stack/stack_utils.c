/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:36:01 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 20:45:05 by ppimchan         ###   ########.fr       */
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
			stack->min_rank = find_next_min_rank(stack);
	}
	stack->size--;
	free(temp);
	return (data);
}
