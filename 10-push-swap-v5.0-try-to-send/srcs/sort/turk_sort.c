/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:43:22 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 10:33:19 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// LAYER 4
int cal_lowest_move(int c_top, int c_bot)
{
	if (c_top <= c_bot * -1)
	{
		return (c_top);
	}
	else
	{
		return (c_bot);
	}
}

// #LAYER #3 when NewMin , newMax

int find_pos_from_top(int find_rank, t_stack *b)
{
	t_node *f_top;
	int c_top;
	int founded;

	c_top = 0;
	f_top = b->top;
	founded = 0;

	while (!founded && f_top)
	{
		if (find_rank == b->max && f_top->rank == b->max)
		{

			founded = 1;
			break;
		}
		else if (find_rank == f_top->rank)
		{
			founded = 1;
			break;
		}

		c_top++;
		f_top = f_top->prev;
	}
	if (founded == 1)
		return (c_top);
	return (INT_MIN);
}

int find_pos_from_bot(int find_rank, t_stack *b)
{
	t_node *f_bot;
	int c_bot;
	int founded;

	c_bot = 0;
	f_bot = b->bottom;
	founded = 0;
	while (!founded && f_bot)
	{
		// printf("hi\n");
		if (find_rank == b->max && f_bot->rank == b->max)
		{
			c_bot--;
			founded = 2;
			break;
		}
		else if (f_bot->rank == find_rank)
		{
			c_bot--;
			founded = 2;
			break;
		}
		c_bot--;
		f_bot = f_bot->next;
	}
	if (founded)
		return (c_bot);
	return (INT_MIN);
}

int find_pos(int find_rank, t_stack *b)
{
	int cost_top;
	int cost_bot;
	cost_top = find_pos_from_top(find_rank, b);
	cost_bot = find_pos_from_top(find_rank, b);
	return cal_lowest_move(cost_top, cost_bot);
}

// LAYER 3B: when general
// หาตำแหน่งที่น้อยกว่า 1 และหาต่อถ้าไม่เจอ (น้อยกว่า 2,3,4)
int find_less_than_pos(int rank, t_stack *b)
{
	int target_rank = rank - 1;

	while (target_rank > 0)
	{
		int pos = find_pos(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank--;
	}
	return (-1);
}

int find_greater_than_pos_from_top(int rank, t_stack *b)
{
	int target_rank = rank + 1;

	while (target_rank <= b->max_rank)
	{
		int pos = find_pos_from_top(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank++;
	}
	return (-1);
}

int find_greater_than_pos_from_bot(int rank, t_stack *b)
{
	int target_rank = rank + 1;

	while (target_rank <= b->max_rank)
	{
		int pos = find_pos_from_bot(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank++;
	}
	return (-1);
}

int find_less_than_pos_from_top(int rank, t_stack *b)
{
	int target_rank = rank - 1;

	while (target_rank > 0)
	{
		int pos = find_pos_from_top(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank--;
	}
	return (-1);
}

int find_less_than_pos_from_bot(int rank, t_stack *b)
{
	int target_rank = rank - 1;

	while (target_rank > 0)
	{
		int pos = find_pos_from_bot(target_rank, b);
		if (pos != INT_MIN)
			return (pos);
		target_rank--;
	}
	return (-1);
}

// LAYER # 2
// calc_rotate_from_top
int cal_rotate_cost_from_top(int move_rank, t_stack *b, int find_greater)
{
	// mode 1 = find less than
	// mode 1 = find greater than
	int cost;
	if (move_rank < b->min_rank)
	{
		// printf("cal_rotate_cost_from_top: top:As a new min %d\n", move_rank);
		if (find_greater == 1)
			cost = find_pos_from_top(b->min_rank, b);
		else
			cost = find_pos_from_top(b->max_rank, b);
		return (cost);
	}

	else if (move_rank > b->max_rank)
	{
		if (find_greater == 1)
			cost = find_pos_from_top(b->min_rank, b);
		else
			cost = find_pos_from_top(b->max_rank, b);
		return (cost);
	}

	else
	{
		// printf("FN:cal_rotate_cost: find rank = %d\n", move_rank);
		if (find_greater == 1)
			cost = find_greater_than_pos_from_top(move_rank, b);
		else
			cost = find_less_than_pos_from_top(move_rank, b);
		// int another = find_more_than_pos_from_top(move_rank, b);
		// printf("COST = %d\n",cost);
		// if(cost > another)
		// 	return (another);
		return (cost);
	}
}

int cal_rotate_cost_from_bot(int move_rank, t_stack *b, int find_greater)
{
	// mode 1 = find less than
	// mode 1 = find greater than
	int cost;
	if (move_rank < b->min_rank)
	{
		if (find_greater == 1)
			cost = find_pos_from_bot(b->min_rank, b);
		else
			cost = find_pos_from_bot(b->max_rank, b);
		return (cost);
	}

	else if (move_rank > b->max_rank)
	{

		if (find_greater == 1)
			cost = find_pos_from_bot(b->min_rank, b);
		else
			cost = find_pos_from_bot(b->max_rank, b);
		return (cost);
	}

	else
	{
		if (find_greater == 1)
			cost = find_greater_than_pos_from_bot(move_rank, b);
		else
			cost = find_less_than_pos_from_bot(move_rank, b);

		return (cost);
	}
}
// calc_rotate_from_bot

int cal_rotate_cost(int move_rank, t_stack *b)
{
	int cost;

	// int cost_top = 0;
	// int cost_bot = 0;
	if (move_rank < b->min)
	{
		cost = find_pos(b->max, b);
		return (cost);
	}

	else if (move_rank > b->max)
	{

		cost = find_pos(b->max, b);
		return (cost);
	}

	else
	{

		cost = find_less_than_pos(move_rank, b);
		return (cost);
	}
}

// เอา 4 ทิศหาว่าควร move ทางไหน
int calc_cheapest_case(int c_ta, int c_tb, int c_ba, int c_bb)
{
	int top_top;
	int bot_bot;
	int cross_one;
	int cross_two;

	top_top = c_ta;
	bot_bot = c_ba;
	if (c_ta < c_tb)
		top_top = c_tb;
	if (c_ba < c_bb)
		bot_bot = c_bb;
	cross_one = c_ta + c_bb;
	cross_two = c_tb + c_ba;
	if (top_top <= bot_bot && top_top <= cross_one && top_top <= cross_two)
		return (1);
	if (bot_bot <= top_top && bot_bot <= cross_one && bot_bot <= cross_two)
		return (2);
	if (cross_one <= top_top && cross_one <= bot_bot && cross_one <= cross_two)
		return (3);
	return (4);
}
// เอาเคสทั้่ง 4 มาหา min move;
int calc_cheapest_move(int move_case, int c_ta, int c_tb, int c_ba, int c_bb)
{
	if (move_case == 1 && c_ta >= c_tb)
		return (c_ta);
	else if (move_case == 1 && c_ta < c_tb)
		return (c_tb);
	if (move_case == 2 && c_ba >= c_bb)
		return (c_ba);
	else if (move_case == 2 && c_ba < c_bb)
		return (c_bb);

	if (move_case == 3)
		return c_ta + c_bb;
	return c_tb + c_ba;
}

void smart_move_tt(int *action_array, t_stack *src, t_stack *dst, int mode)
{
	int src_top;
	int dst_top;
	int common_count;
	int gap_count;

	src_top = action_array[3];
	dst_top = action_array[4];
	if (src_top >= dst_top)
	{
		gap_count = src_top - dst_top;
		common_count = dst_top;
	}
	else
	{
		gap_count = dst_top - src_top;
		common_count = src_top;
	}
	while (common_count && common_count--)
		r_shift_up(src, dst, 1);
	while (gap_count && gap_count--)
	{
		if (src_top >= dst_top || mode == 1)
			r_shift_up(src, NULL, 1);
		else
			r_shift_up(dst, NULL, 1);
	}
}

void smart_move_bb(int *action_array, t_stack *src, t_stack *dst, int mode)
{
	int src_bot;
	int dst_bot;
	int common_count;
	int gap_count;

	src_bot = action_array[5];
	dst_bot = action_array[6];

	if (src_bot >= dst_bot)
	{
		gap_count = src_bot - dst_bot;
		common_count = dst_bot;
	}
	else
	{
		gap_count = dst_bot - src_bot;
		common_count = src_bot;
	}
	while (common_count && common_count--)
		rr_shift_down(src, dst, 1);
	if (src_bot >= dst_bot)
	{
		if (mode == 0)
			while (gap_count && gap_count--)
				rr_shift_down(src, NULL, 1);
		else
			while (gap_count && gap_count--)
				rr_shift_down(dst, NULL, 1);
	}
	if (src_bot < dst_bot)
	{
		if (mode == 0)
			while (gap_count && gap_count--)
				rr_shift_down(dst, NULL, 1);
		else
			while (gap_count && gap_count--)
				rr_shift_down(src, NULL, 1);
	}
}

void smart_move_crossone(int *action_array, t_stack *src, t_stack *dst, int move_back)
{
	int src_top;
	int dst_bot;

	src_top = action_array[3];
	dst_bot = action_array[6];

	if (move_back == 0)
	{
		while (src_top--)
			r_shift_up(src, NULL, 1);
		while (dst_bot--)
			rr_shift_down(dst, NULL, 1);
	}
	else if (move_back == 1)
	{
		while (src_top--)
			r_shift_up(dst, NULL, 1);
		while (dst_bot--)
			rr_shift_down(src, NULL, 1);
	}
}

void smart_move_crosstwo(int *action_array, t_stack *src, t_stack *dst, int move_back)
{
	int src_top;
	int dst_top;
	int src_bot;
	int dst_bot;

	src_top = action_array[3];
	dst_top = action_array[4];
	src_bot = action_array[5];
	dst_bot = action_array[6];
	if (move_back == 0)
	{
		while (src_bot--)
			rr_shift_down(src, NULL, 1);
		while (dst_top--)
			r_shift_up(dst, NULL, 1);
	}
	else if (move_back == 1)
	{
		while (src_top--)
			rr_shift_down(dst, NULL, 1);
		while (dst_bot--)
			r_shift_up(src, NULL, 1);
	}
}
void smart_move(int *action_array, t_stack *src, t_stack *dst, int move_back)
{
	int action_case;

	action_case = action_array[2];
	
	if (action_case == 1)
		smart_move_tt(action_array, src, dst, move_back);
	if (action_case == 2)
		smart_move_bb(action_array, src, dst, move_back);
	if (action_case == 3)
		smart_move_crossone(action_array, src, dst, move_back);

	if (action_case == 4)
		smart_move_crosstwo(action_array, src,dst,move_back);

	if (move_back == 0)
		p_move_top(src, dst, 1);
	else if (move_back == 1)
		p_move_top(dst, src, 1);
}

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