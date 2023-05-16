/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:43:22 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 16:32:25 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// START - ACTION ARRAY
int find_index(t_stack *src, int rank)
{
	t_node *current;
	int index;

	current = src->top;
	index = 0;
	while (current && current->rank != rank)
	{
		index++;
		current = current->prev;
	}
	return (index);
}

int *calc_action_array(t_stack *src, t_stack *dst, t_node *current, int cheapest[], int mode)
{

	int src_top = find_index(src, current->rank);
	int src_bot = src_top - src->size;
	int dst_top = cal_rotate_cost_from_top(current->rank, dst, mode);
	int dst_bot = cal_rotate_cost_from_bot(current->rank, dst, mode);
	int cheapest_case = calc_cheapest_case(src_top, dst_top, src_bot * -1, dst_bot * -1);
	int cheapest_move = calc_cheapest_move(cheapest_case, src_top, dst_top, src_bot * -1, dst_bot * -1);

	if (cheapest_move < cheapest[1])
	{
		cheapest[0] = src_top;
		cheapest[1] = cheapest_move;
		cheapest[2] = cheapest_case;
		cheapest[3] = src_top;
		cheapest[4] = dst_top;
		cheapest[5] = -1 * src_bot;
		cheapest[6] = -1 * dst_bot;
	}
	return (cheapest);
}
// END - ACTION ARRAY

void cheapest_move(t_stack *src, t_stack *dst, int mode)
{
	int index;
	t_node *current;
	int cheapest[7];

	index = 0;
	current = src->top;
	cheapest[1] = INT_MAX;
	while (current)
	{
		calc_action_array(src, dst, current, cheapest, mode);
		current = current->prev;
		index++;
	}
	if (mode == 0)
		smart_move(cheapest, src, dst, mode);
	else
		smart_move(cheapest, dst, src, mode);
}

void internal_sort(t_stack *a)
{
	int c_top = find_pos_from_top(a->min_rank, a);
	int c_bot = -1 * find_pos_from_bot(a->min_rank, a);

	if (c_top <= c_bot)
		while (c_top && c_top--)
			r_shift_up(a, NULL, 1);
	else if (c_bot && c_bot < c_top)
		while (c_bot--)
			rr_shift_down(a, NULL, 1);
}

void turk_sort(t_stack *a, t_stack *b)
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