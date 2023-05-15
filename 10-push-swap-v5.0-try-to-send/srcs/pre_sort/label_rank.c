/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:13:56 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/15 17:21:28 by ppimchan         ###   ########.fr       */
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
	// printf("============LABEL RANK===========\n");
	rank = 1;
	min = INT_MAX;
	current = A->top;
	// printf("A->size=%d\n",A->size);
	// printf("A->min_rank=%d\n",A->min_rank);
	while (rank <= A->size)
	{
		min = find_min(A);
		current = A->top;
		while (current)
		{
			if (current->data == min)
			{
				current->rank = rank;
				// printf("hi\n");
				// add to try correct
				// if(rank < A->min_rank)
				// 	A->min_rank = rank;
				// add to try correct
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
