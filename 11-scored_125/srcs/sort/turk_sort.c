/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:43:22 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 17:09:57 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// START - ACTION ARRAY
int	find_index(t_stack *src, int rank)
{
	t_node	*current;
	int		index;

	current = src->top;
	index = 0;
	while (current && current->rank != rank)
	{
		index++;
		current = current->prev;
	}
	return (index);
}

int	*calc_action_array(t_stack *src, t_stack *dst, int cheapest[], int mode)
{
	int	cur[7];
	int	cheapest_case;
	int	cheapest_move;

	cur[3] = find_index(src, cheapest[7]);
	cur[4] = cal_rotate_cost_from_top(cheapest[7], dst, mode);
	cur[5] = (cur[3] - src->size) * -1;
	cur[6] = cal_rotate_cost_from_bot(cheapest[7], dst, mode) * -1;
	cheapest_case = calc_cheapest_case(cur[3], cur[4], cur[5], cur[6]);
	cheapest_move = calc_cheapest_move(cheapest_case, cur);
	if (cheapest_move < cheapest[1])
	{
		cheapest[0] = cur[3];
		cheapest[1] = cheapest_move;
		cheapest[2] = cheapest_case;
		cheapest[3] = cur[3];
		cheapest[4] = cur[4];
		cheapest[5] = cur[5];
		cheapest[6] = cur[6];
	}
	return (cheapest);
}

void	cheapest_move(t_stack *src, t_stack *dst, int mode)
{
	int		index;
	t_node	*current;
	int		cheapest[8];

	index = 0;
	current = src->top;
	cheapest[1] = INT_MAX;
	while (current)
	{
		cheapest[7] = current->rank;
		calc_action_array(src, dst, cheapest, mode);
		current = current->prev;
		index++;
	}
	if (mode == 0)
		smart_move(cheapest, src, dst, mode);
	else
		smart_move(cheapest, dst, src, mode);
}

void	internal_sort(t_stack *a)
{
	int	c_top;
	int	c_bot;

	c_top = find_pos_from_top(a->min_rank, a);
	c_bot = -1 * find_pos_from_bot(a->min_rank, a);
	if (c_top <= c_bot)
		while (c_top && c_top--)
			r_shift_up(a, NULL, 1);
	else if (c_bot && c_bot < c_top)
		while (c_bot--)
			rr_shift_down(a, NULL, 1);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	p_move_top_with_rank(a, b, a->top->rank, 1);
	p_move_top_with_rank(a, b, a->top->rank, 1);
	while (a->size > 3)
		cheapest_move(a, b, 0);
	if (!is_sorted(a))
		triple_sort(a);
	while (b->size)
		cheapest_move(b, a, 1);
	internal_sort(a);
}
