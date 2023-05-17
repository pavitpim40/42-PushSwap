/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:51:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 17:10:13 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_pos_from_top(int find_rank, t_stack *b)
{
	t_node	*f_top;
	int		c_top;
	int		founded;

	c_top = 0;
	f_top = b->top;
	founded = 0;
	while (!founded && f_top)
	{
		c_top++;
		if (find_rank == b->max && f_top->rank == b->max)
			founded = 1;
		else if (find_rank == f_top->rank)
			founded = 1;
		f_top = f_top->prev;
	}
	if (founded == 1)
		return (c_top - 1);
	return (INT_MIN);
}

int	find_pos_from_bot(int find_rank, t_stack *b)
{
	t_node	*f_bot;
	int		c_bot;
	int		founded;

	c_bot = 0;
	f_bot = b->bottom;
	founded = 0;
	while (!founded && f_bot)
	{
		c_bot--;
		if (find_rank == b->max && f_bot->rank == b->max)
			founded = 1;
		else if (f_bot->rank == find_rank)
			founded = 1;
		f_bot = f_bot->next;
	}
	if (founded)
		return (c_bot);
	return (INT_MIN);
}
