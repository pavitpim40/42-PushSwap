/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:13:56 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 01:14:48 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int find_min(Stack *A)
{
	Node *current;
	int min;

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
void label_rank(Stack *A)
{
	int rank;
	int min;
	Node *current;

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
				break;
			}
			current = current->prev;
		}
	}
}
