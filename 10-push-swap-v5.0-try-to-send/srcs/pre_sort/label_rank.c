/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:13:56 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/15 18:18:39 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min(t_stack *A)
{
	t_node	*current;
	int		min;

	current = A->top;
	min = INT_MAX;
	while (current)
	{
		if (current->rank == -1 && current->data < min)
			min = current->data;
		current = current->prev;
	}
	return (min);
}

void	label_rank(t_stack *A)
{
	int		rank;
	int		min;
	t_node	*current;

	rank = 1;
	min = INT_MAX;
	current = A->top;
	while (rank <= A->size)
	{
		min = find_min(A);
		current = A->top;
		while (current)
		{
			if (current->data == min)
			{
				current->rank = rank;
				rank++;
				min = INT_MAX;
				break ;
			}
			current = current->prev;
		}
	}
	A->min_rank = 1;
	A->max_rank = A->size;
}
