/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:54:32 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 17:06:46 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	cal_rotate_cost_from_top(int move_rank, t_stack *b, int find_greater)
{
	int	cost;

	if (move_rank < b->min_rank || move_rank > b->max_rank)
	{
		if (find_greater == 1)
			cost = find_pos_from_top(b->min_rank, b);
		else
			cost = find_pos_from_top(b->max_rank, b);
	}
	else
	{
		if (find_greater == 1)
			cost = find_greater_than_pos_from_top(move_rank, b);
		else
			cost = find_less_than_pos_from_top(move_rank, b);
	}
	return (cost);
}

int	cal_rotate_cost_from_bot(int move_rank, t_stack *b, int find_greater)
{
	int cost;
	if (move_rank < b->min_rank || move_rank > b->max_rank)
	{
		if (find_greater == 1)
			cost = find_pos_from_bot(b->min_rank, b);
		else
			cost = find_pos_from_bot(b->max_rank, b);
	}
	else
	{
		if (find_greater == 1)
			cost = find_greater_than_pos_from_bot(move_rank, b);
		else
			cost = find_less_than_pos_from_bot(move_rank, b);
	}
	return (cost);
}

// เอา 4 ทิศหาว่าควร move ทางไหน
int	calc_cheapest_case(int c_ta, int c_tb, int c_ba, int c_bb)
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
int	calc_cheapest_move(int move_case, int	*action_array)
{
	int	c_ta;
	int	c_tb;
	int	c_ba;
	int	c_bb;

	c_ta = action_array[3];
	c_tb = action_array[4];
	c_ba = action_array[5];
	c_bb = action_array[6];
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