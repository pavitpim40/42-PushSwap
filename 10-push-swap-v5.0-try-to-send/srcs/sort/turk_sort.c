/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:43:22 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/14 18:32:09 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Main Problem : Move with Cheapest Instruction
// Sub-PB1 : calc. cost from stack A to Top
// Sub-PB2 : calc. cost to move to stack B (1)
// Sub-PB3 : calc. cost to rotate to right position in Stack B
// Sub-PB4 : find minimum cost
// Sub-PB5 : take that action

// lowest_pos

int cal_lowest_move(int c_top, int c_bot)
{
	// printf("c_top = %d\n", c_top);
	// printf("c_bot = %d\n", c_bot);
	if (c_top <= c_bot * -1)
	{
		printf("1\n");
		return (c_top);
	}
	else
	{
		printf("2\n");
		return (c_bot);
	}
}
// เจอตำแหน่งที่ต้องการคือจบ
// int find_pos(int find_rank, t_stack *b)
// {
// 	t_node *f_top;
// 	t_node *f_bot;
// 	int c_top;
// 	int c_bot;
// 	int		founded;

// 	c_top = 0;
// 	c_bot = 0;
// 	f_top = b->top;
// 	f_bot = b->bottom;
// 	founded = 0;
// 	printf("B->max = %d\n", b->max);
// 	printf("find_rank = %d\n", find_rank);
// 	while (!founded && (f_top || f_bot))
// 	{
// 		// กรณีที่จะหาตัว max
// 		if (find_rank == b->max && f_top->rank == b->max)
// 		{
// 			// c_top++;
// 			printf("found from top\n");
// 			founded = 1;
// 			break;
// 		}
// 		else if (find_rank == b->max && f_bot->rank == b->max)
// 		{
// 			printf("found from bot\n");
// 			c_bot--;
// 			founded = 2;
// 			break;
// 		}

// 		else if (find_rank == f_top->rank)
// 		{
// 			// c_top++;
// 			founded = 1;
// 			break;
// 		}
// 		else if (f_bot->rank == find_rank)
// 		{
// 			c_bot--;
// 			founded = 2;
// 			break;

// 		}

// 		c_top++;
// 		c_bot--;
// 		f_top = f_top->prev;
// 		f_bot = f_bot->next;
// 	}
// 	if(founded == 1)
// 		return (c_top);
// 	else if(founded == 2)
// 		return (c_bot);
// 	return (-1);
// }

int find_pos_from_top(int find_rank, t_stack *b)
{
	t_node *f_top;
	int c_top;
	int founded;

	c_top = 0;
	f_top = b->top;
	founded = 0;
	// printf("B->max = %d\n", b->max);
	// printf("find_rank = %d\n", find_rank);
	while (!founded && f_top)
	{
		// กรณีที่จะหาตัว max
		if (find_rank == b->max && f_top->rank == b->max)
		{
			// c_top++;
			// printf("found from top\n");
			founded = 1;
			break;
		}
		else if (find_rank == f_top->rank)
		{
			// c_top++;
			founded = 1;
			break;
		}

		c_top++;
		f_top = f_top->prev;
	}
	if (founded == 1)
		return (c_top);
	return (-1);
}

int find_pos_from_bot(int find_rank, t_stack *b)
{
	t_node *f_bot;
	int c_bot;
	int founded;

	c_bot = 0;
	f_bot = b->bottom;
	founded = 0;
	// printf("B->max = %d\n", b->max);
	// printf("find_rank = %d\n", find_rank);
	while (!founded && f_bot)
	{
		if (find_rank == b->max && f_bot->rank == b->max)
		{
			// printf("found from bot\n");
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
	return (-1);
}

int find_pos(int find_rank, t_stack *b)
{
	int cost_top;
	int cost_bot;
	cost_top = find_pos_from_top(find_rank, b);
	cost_bot = find_pos_from_top(find_rank, b);
	return cal_lowest_move(cost_top, cost_bot);
}

// หาตำแหน่งที่น้อยกว่า 1 และหาต่อถ้าไม่เจอ (น้อยกว่า 2,3,4)
int find_less_than_pos(int rank, t_stack *b)
{
	int target_rank = rank - 1;

	while (target_rank > 0)
	{
		int pos = find_pos(target_rank, b);
		// int pos_top = find_pos_from_top(target_rank,b);
		// int pos_bot = find_pos_from_bot(target_rank,b);
		// printf("target rank = %d\n", target_rank);
		// if (pos_top != -1 && pos_bot)
		// 	return cal_lowest_move(pos_top,pos_bot);
		if (pos != -1)
			return (pos);
		target_rank--;
	}
	return (-1);
}

int find_less_than_pos_from_top(int rank, t_stack *b)
{
	int target_rank = rank - 1;

	while (target_rank > 0)
	{
		int pos = find_pos_from_top(target_rank, b);
		// int pos_top = find_pos_from_top(target_rank,b);
		// int pos_bot = find_pos_from_bot(target_rank,b);
		printf("top:target rank = %d\n", target_rank);
		// if (pos_top != -1 && pos_bot)
		// 	return cal_lowest_move(pos_top,pos_bot);
		if (pos != -1)
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
		// int pos_top = find_pos_from_top(target_rank,b);
		// int pos_bot = find_pos_from_bot(target_rank,b);
		printf("bot:target rank = %d\n", target_rank);
		// if (pos_top != -1 && pos_bot)
		// 	return cal_lowest_move(pos_top,pos_bot);
		if (pos != -1)
			return (pos);
		target_rank--;
	}
	return (-1);
}

// calc_rotate_from_top
int cal_rotate_cost_from_top(int move_rank, t_stack *b)
{
	int cost;

	// int cost_top = 0;
	// int cost_bot = 0;
	if (move_rank < b->min)
	{
		printf("top:As a new min %d\n", move_rank);
		cost = find_pos_from_top(b->max, b);
		return (cost);
	}

	else if (move_rank > b->max)
	{
		printf("top:As a new max %d\n", move_rank);
		// printf("FN:cal_rotate_cost: move as a NEW_MAX = %d\n", move_rank);
		cost = find_pos_from_top(b->max, b);
		return (cost);
	}

	else
	{
		// printf("FN:cal_rotate_cost: find rank = %d\n", move_rank);
		cost = find_less_than_pos_from_top(move_rank, b);
		return (cost);
	}
}

int cal_rotate_cost_from_bot(int move_rank, t_stack *b)
{
	int cost;

	// int cost_top = 0;
	// int cost_bot = 0;
	if (move_rank < b->min)
	{
		printf("bot:As a new min %d\n", move_rank);
		cost = find_pos_from_bot(b->max, b);
		return (cost);
	}

	else if (move_rank > b->max)
	{

		printf("bot:As a new max %d\n", move_rank);
		// printf("FN:cal_rotate_cost: move as a NEW_MAX = %d\n", move_rank);
		cost = find_pos_from_bot(b->max, b);
		return (cost);
	}

	else
	{
		// printf("FN:cal_rotate_cost: find rank = %d\n", move_rank);
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
		// printf("FN:cal_rotate_cost: move as a NEW_MAX = %d\n", move_rank);
		cost = find_pos(b->max, b);
		return (cost);
	}

	else
	{
		// printf("FN:cal_rotate_cost: find rank = %d\n", move_rank);
		cost = find_less_than_pos(move_rank, b);
		return (cost);
	}
}

void turk_sort(t_stack *a, t_stack *b)
{
	// #1 Move to B
	int size_a;
	t_node *current;
	int cheapest_cost = INT_MAX;
	int cheapest_idx = -1;

	size_a = a->size;
	p_move_top(a, b, 1);
	p_move_top(a, b, 1);
	// push7
	// r_shift_up(b, NULL, 1);
	// p_move_top(a, b, 1);
	// push 1
	// p_move_top(a, b, 1);
	// push3
	// r_shift_up(a, NULL, 1);
	// rr_shift_down(b, NULL, 1);
	// p_move_top(a, b, 1);
	current = a->top;
	int index = 0;
	int action_a = 0;
	int action_b = 0;
	int which_side = 0;
	while (a->size > 3 && current)
	{
		// ## 1.1 start from top node

		// int index = 0;
		printf("============ LOOP %d ==============\n", index + 1);
		// int rotate_cost = cal_rotate_cost(current->rank, b);

		int c_ta = index;
		int c_ba = index - a->size;
		int c_tb = cal_rotate_cost_from_top(current->rank, b);
		int c_bb = cal_rotate_cost_from_bot(current->rank, b);

		printf("data : %d\n", current->rank);
		printf("cta : %d, ctb : %d\n", c_ta, c_tb);
		printf("cba : %d, cbb : %d\n", c_ba, c_bb);

		if (c_ta >= c_tb)
			printf("net from top %d\n", c_ta);
		else if (c_ta < c_tb)
			printf("net from top %d\n", c_tb);

		if (c_ba <= c_bb)
			printf("net from bot %d\n", c_ba*-1);
		else if (c_ba > c_bb)
			printf("net from bot %d\n", c_bb *-1);
		// Update Cheapest;
		// from top;
		if (c_tb < 0)
			c_tb *= -1;
		if (c_ta >= c_tb && c_ta < cheapest_cost)
		{
			cheapest_cost = c_ta;
			cheapest_idx = index;
			action_a = c_ta;
			action_b = c_tb;
			which_side = 1;
			printf("INNER:CASE-1: cheapest index = %d, cost =%d\n", cheapest_idx, cheapest_cost);
			printf("which side=%d\n", which_side);
			// printf("=================================\n");
		}
		else if (c_ta < c_tb && c_tb < cheapest_cost)
		{
			cheapest_cost = c_tb;
			cheapest_idx = index;
			action_a = c_ta;
			action_b = c_tb;
			which_side = 1;
			printf("INNER:CASE-2: cheapest index = %d, cost =%d\n", cheapest_idx, cheapest_cost);
			printf("which side=%d\n", which_side);
			// printf("=================================\n");
		}
		// from bot
		c_ba = -1 * c_ba;
		c_bb = -1 * c_bb;
		if (c_ba >= c_bb && c_ba < cheapest_cost)
		{
			cheapest_cost = c_ba;
			cheapest_idx = index;
			which_side = 2;
			printf("INNER:CASE-3: cheapest index = %d, cost =%d\n", cheapest_idx, cheapest_cost);
			printf("which side=%d\n", which_side);
			// printf("=================================\n");
		}
		else if (c_ba < c_bb && c_bb < cheapest_cost)
		{
			cheapest_cost = c_bb;
			cheapest_idx = index;
			action_a = c_ba;
			action_b = c_bb;
			which_side = 2;
			printf("INNER:CASE-4: cheapest index = %d, cost =%d\n", cheapest_idx, cheapest_cost);
			printf("which side=%d\n", which_side);
			// printf("=================================\n");
		}
		printf("=================================\n");

		// update to next node
		current = current->prev;
		index++;
		size_a--;
	}

	printf("cheapest index = %d, cost =%d\n", cheapest_idx, cheapest_cost);
	printf("cta=%d\n", action_a);
	printf("ctb=%d\n", action_b);
	// #1.5 Triple sort
	// #2 Move back to A
}