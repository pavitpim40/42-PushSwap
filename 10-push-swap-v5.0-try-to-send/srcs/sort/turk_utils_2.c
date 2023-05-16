/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:53:17 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 17:10:23 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_greater_than_pos_from_top(int rank, t_stack *b)
{
	int	target_rank;
	int	pos;

	target_rank = rank + 1;
	while (target_rank <= b->max_rank)
	{
		pos = find_pos_from_top(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank++;
	}
	return (-1);
}

int	find_greater_than_pos_from_bot(int rank, t_stack *b)
{
	int	target_rank;
	int	pos;

	target_rank = rank + 1;
	while (target_rank <= b->max_rank)
	{
		pos = find_pos_from_bot(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank++;
	}
	return (-1);
}

int	find_less_than_pos_from_top(int rank, t_stack *b)
{
	int	target_rank;
	int	pos;

	target_rank = rank - 1;
	while (target_rank > 0)
	{
		pos = find_pos_from_top(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank--;
	}
	return (-1);
}

int	find_less_than_pos_from_bot(int rank, t_stack *b)
{
	int	target_rank;
	int	pos;

	target_rank = rank - 1;
	while (target_rank > 0)
	{
		pos = find_pos_from_bot(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank--;
	}
	return (-1);
}
