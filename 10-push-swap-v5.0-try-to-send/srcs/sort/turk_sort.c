/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:43:22 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/15 12:30:54 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Main Problem : Move with Cheapest Instruction
// Sub-PB1 : calc. cost from stack A to Top
// Sub-PB2 : calc. cost to move to stack B (1)
// Sub-PB3 : calc. cost to rotate to right position in Stack B
// Sub-PB4 : find minimum cost
// Sub-PB5 : take that action

// LAYER 4
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
		// printf("INNER LOOP\n");
		// printf("src->max = %d\n", b->max);
		// printf("find_rank = %d\n", find_rank);
		// printf("f_top->rank = %d\n\n", f_top->rank);
		// กรณีที่จะหาตัว max

		if (find_rank == b->max && f_top->rank == b->max)
		{
			// c_top++;
			// printf("found from top-1\n");
			founded = 1;
			// printf("FN:find_pos_from_top:c_top = %d\n", c_top);
			break;
		}
		else if (find_rank == f_top->rank)
		{
			// c_top++;
			// printf("found from top-2\n");
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
	// printf("B->max = %d\n", b->max);
	// printf("find_rank = %d\n", find_rank);
	while (!founded && f_bot)
	{
		// printf("hi\n");
		if (find_rank == b->max && f_bot->rank == b->max)
		{
			// printf("found from bot\n");
			// printf("hi-1, find_rank%d\n", find_rank);
			c_bot--;
			founded = 2;
			break;
		}
		else if (f_bot->rank == find_rank)
		{
			// printf("hi-2, find_rank%d\n", find_rank);
			c_bot--;
			// printf("hi-2, pos=%d\n",c_bot);
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
		// int pos_top = find_pos_from_top(target_rank,b);
		// int pos_bot = find_pos_from_bot(target_rank,b);
		// printf("target rank = %d\n", target_rank);
		printf("POS = %d\n", pos);
		// if (pos_top != -1 && pos_bot)
		// 	return cal_lowest_move(pos_top,pos_bot);
		// if (pos != -1)
		if (pos != INT_MIN)
			return (pos);
		target_rank--;
	}
	return (-1);
}

int find_greater_than_pos_from_top(int rank, t_stack *b)
{
	int target_rank = rank + 1;

	while (target_rank <= b->max)
	{
		int pos = find_pos_from_top(target_rank, b);
		// int pos_top = find_pos_from_top(target_rank,b);
		// int pos_bot = find_pos_from_bot(target_rank,b);
		// printf("target rank = %d\n", target_rank);
		// printf("GT_TOP:POS = %d\n", pos);
		// if (pos_top != -1 && pos_bot)
		// 	return cal_lowest_move(pos_top,pos_bot);
		// if (pos != -1)
		if (pos != INT_MIN)
			return (pos);
		target_rank++;
	}
	return (-1);
}

int find_greater_than_pos_from_bot(int rank, t_stack *b)
{
	int target_rank = rank + 1;

	while (target_rank <= b->max)
	{
		int pos = find_pos_from_bot(target_rank, b);
		// int pos_top = find_pos_from_top(target_rank,b);
		// int pos_bot = find_pos_from_bot(target_rank,b);
		// printf("target rank = %d\n", target_rank);
		// printf("GT_BOT:POS = %d\n", pos);
		// if (pos_top != -1 && pos_bot)
		// 	return cal_lowest_move(pos_top,pos_bot);
		// if (pos != -1)
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
		// int pos_top = find_pos_from_top(target_rank,b);
		// int pos_bot = find_pos_from_bot(target_rank,b);
		// printf("top:target rank = %d\n", target_rank);
		// if (pos_top != -1 && pos_bot)
		// 	return cal_lowest_move(pos_top,pos_bot);
		// if (pos != -1)

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
		// int pos_top = find_pos_from_top(target_rank,b);
		// int pos_bot = find_pos_from_bot(target_rank,b);
		// printf("bot:target rank = %d and pos=%d\n", target_rank,pos);
		// if (pos_top != -1 && pos_bot)
		// 	return cal_lowest_move(pos_top,pos_bot);
		// if (pos != -1)
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

	// int cost_top = 0;
	// int cost_bot = 0;
	// printf("move rank %d\n", move_rank);
	// printf("dst->min %d\n", b->min);
	if (move_rank < b->min)
	{
		printf("cal_rotate_cost_from_top: top:As a new min %d\n", move_rank);
		if (find_greater == 1)
			cost = find_pos_from_top(b->min, b);
		else
			cost = find_pos_from_top(b->max, b);
		return (cost);
	}

	else if (move_rank > b->max)
	{
		// printf("top:As a new max %d\n", move_rank);
		// printf("FN:cal_rotate_cost: move as a NEW_MAX = %d\n", move_rank);
		cost = find_pos_from_top(b->max, b);
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

	// int cost_top = 0;
	// int cost_bot = 0;
	if (move_rank < b->min_rank)
	{
		if (find_greater == 1)
			cost = find_pos_from_bot(b->min, b);
		else
			cost = find_pos_from_bot(b->max, b);
		return (cost);
	}

	else if (move_rank > b->max)
	{

		// printf("bot:As a new max %d\n", move_rank);
		// printf("FN:cal_rotate_cost: move as a NEW_MAX = %d\n", move_rank);
		cost = find_pos_from_bot(b->max, b);
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

// เอา 4 ทิศหาว่าควร move ทางไหน
int calc_cheapest_case(int c_ta, int c_tb, int c_ba, int c_bb)
{
	int top_top;
	int bot_bot;
	int cross_one;
	int cross_two;

	// printf("data : %d\n", current->rank);
	// printf("========= INNER ============\n");
	// printf("cta : %d, ctb : %d\n", c_ta, c_tb);
	// printf("cba : %d, cbb : %d\n", c_ba, c_bb);

	top_top = c_ta;
	bot_bot = c_ba;
	if (c_ta < c_tb)
		top_top = c_tb;
	if (c_ba < c_bb)
		bot_bot = c_bb;
	cross_one = c_ta + c_bb;
	cross_two = c_tb + c_ba;
	// printf("case-1 : top_top : %d\n", top_top);
	// printf("case-2 : bot_bot : %d\n", bot_bot);
	// printf("case-3 : cross_one : %d\n", cross_one);
	// printf("case-4 : cross_two : %d\n", cross_two);
	if (top_top <= bot_bot && top_top <= cross_one && top_top <= cross_two)
		return (1);
	if (bot_bot <= top_top && bot_bot <= cross_one && bot_bot <= cross_two)
		return (2);
	if (cross_one <= top_top && cross_one <= bot_bot && cross_one <= cross_two)
		return (3);
	// if (cross_two < top_top && cross_two < bot_bot && cross_two < cross_one)
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

void smart_move(int *action_array, t_stack *src, t_stack *dst, int move_back)
{
	int action_case;
	int gap;
	int c_ta;
	int c_tb;
	int c_ba;
	int c_bb;

	action_case = action_array[2];
	c_ta = action_array[3];
	c_tb = action_array[4];
	c_ba = action_array[5];
	c_bb = action_array[6];
	// printf("case = %d\n", action_case);
	// printf("c_ta = %d\n", c_ta);
	// printf("c_tb = %d\n", c_tb);
	if (action_case == 1 && c_ta >= c_tb)
	{
		// min move A,B = ct_b and gap move only A
		// printf("SM:CASE-1\n");
		gap = c_ta - c_tb;
		while (c_tb && c_tb--)
		{
			printf("c_tb %d\n", c_tb);
			r_shift_up(src, dst, 1);
		}

		while (gap && gap--)
			r_shift_up(src, NULL, 1);
	}
	if (action_case == 1 && c_ta < c_tb)
	{
		// printf("SM:CASE-2\n");
		// print_stack(a);
		// print_stack(b);
		gap = c_tb - c_ta;
		// printf("c_ta=%d\n", c_ta);
		// printf("c_tb=%d\n", c_tb);
		// printf("gap=%d\n", gap);
		while (c_ta != 0 && c_ta--)
		{
			r_shift_up(src, dst, 1);
		}
		while (gap != 0 && gap--)
			r_shift_up(dst, NULL, 1);
	}
	if (action_case == 2 && c_ba >= c_bb)
	{
		gap = c_ba - c_bb;
		while (c_bb && c_bb--)
			rr_shift_down(src, dst, 1);
		while (gap && gap--)
			rr_shift_down(src, NULL, 1);
	}
	if (action_case == 2 && c_ba < c_bb)
	{
		gap = c_bb - c_ba;
		while (c_ba && c_ba--)
			rr_shift_down(src, dst, 1);
		while (gap && gap--)
			rr_shift_down(src, NULL, 1);
	}
	if (action_case == 3)
	{
		// printf("action case:3\n");
		// printf("action: c_ta = %d\n", c_ta);
		// printf("action: c_bb = %d\n", c_bb);
		// move back  c_ta คือ c_tb
		// move back c_bb คือ c_ba;
		while (c_ta--)
			r_shift_up(src, NULL, 1);
		while (c_bb--)
			rr_shift_down(src, NULL, 1);
	}
	if (action_case == 4)
	{
		while (c_ba--)
			r_shift_up(src, NULL, 1);
		while (c_tb--)
			rr_shift_down(src, NULL, 1);
	}
	if (move_back == 0)
		p_move_top(src, dst, 1);
	else
		p_move_top(dst, src, 1);
}

void smart_move_back(int *action_array, t_stack *src, t_stack *dst)
{
	int action_case;
	int gap;
	int c_ta;
	int c_tb;
	int c_ba;
	int c_bb;

	action_case = action_array[2];
	c_ta = action_array[3];
	c_tb = action_array[4];
	c_ba = action_array[5];
	c_bb = action_array[6];
	printf("case = %d\n", action_case);
	printf("c_ta = %d\n", c_ta);
	printf("c_tb = %d\n", c_tb);
	if (action_case == 1 && c_ta >= c_tb)
	{
		// min move A,B = ct_b and gap move only A
		printf("SM:CASE-1\n");
		gap = c_ta - c_tb;
		while (c_tb && c_tb--)
		{
			printf("c_tb %d\n", c_tb);
			r_shift_up(src, dst, 1);
		}

		while (gap && gap--)
			r_shift_up(src, NULL, 1);
	}
	if (action_case == 1 && c_ta < c_tb)
	{
		printf("SM:CASE-2\n");
		// print_stack(a);
		// print_stack(b);
		gap = c_tb - c_ta;
		printf("c_ta=%d\n", c_ta);
		printf("c_tb=%d\n", c_tb);
		printf("gap=%d\n", gap);
		while (c_ta != 0 && c_ta--)
		{
			r_shift_up(src, dst, 1);
		}
		while (gap != 0 && gap--)
			r_shift_up(dst, NULL, 1);
	}
	if (action_case == 2 && c_ba >= c_bb)
	{
		gap = c_ba - c_bb;
		while (c_bb && c_bb--)
			rr_shift_down(src, dst, 1);
		while (gap && gap--)
			rr_shift_down(src, NULL, 1);
	}
	if (action_case == 2 && c_ba < c_bb)
	{
		gap = c_bb - c_ba;
		while (c_ba && c_ba--)
			rr_shift_down(src, dst, 1);
		while (gap && gap--)
			rr_shift_down(src, NULL, 1);
	}
	if (action_case == 3)
	{
		// printf("action case:3");
		// printf("action: c_ta = %d\n", c_ta);
		// printf("action: c_bb = %d\n", c_ta);
		while (c_ta--)
			r_shift_up(src, NULL, 1);
		while (c_bb--)
			rr_shift_down(src, NULL, 1);
	}
	if (action_case == 4)
	{
		while (c_ba--)
			r_shift_up(src, NULL, 1);
		while (c_tb--)
			rr_shift_down(src, NULL, 1);
	}
	p_move_top(src, dst, 1);
}

void turk_sort(t_stack *a, t_stack *b)
{
	// #1 Move to B
	int size_a;
	t_node *current;
	// int cheapest_cost = INT_MAX;
	// int cheapest_idx = -1;
	int cheapest[7]; // [idex,case,c_ta,c_ba,c_tb,c_bb]
	size_a = a->size;
	// p_move_top(a, b, 1);
	printf("----------------TURK SORT-------------------\n");
	p_move_top_with_rank(a,b,a->top->rank,1);
	p_move_top_with_rank(a,b,a->top->rank,1);
	// p_move_top(a, b, 1);
	print_stack(b);

	// # push7
	// r_shift_up(b, NULL, 1);
	// p_move_top(a, b, 1);
	// # push 1
	// p_move_top(a, b, 1);
	// # push3
	// r_shift_up(a, NULL, 1);
	// rr_shift_down(b, NULL, 1);
	// p_move_top(a, b, 1);
	current = a->top;
	int index = 0;
	int abs_min_move = INT_MAX;
	int cheapest_case;
	int cheapest_move;

	// loop for cheapest on each round;
	int i = 1;
	// while (a->size > 3)
	while(i != 0)
	{

		index = 0;
		size_a = a->size;
		current = a->top;
		cheapest_case = INT_MAX;
		cheapest_move = INT_MAX;
		abs_min_move = INT_MAX;
		while (size_a && current)
		{

			printf("============ LOOP %d ==============\n", index + 1);
			printf("======current->rank====== %d\n", current->rank);
			printf("======current->data====== %d\n", current->data);

			printf("======b->min====== %d\n", b->min);
			printf("======b->min====== %d\n", b->top->rank);
			// printf("======current->data====== %d\n", current->data);
			int c_ta = index;
			int c_ba = index - a->size;
			int c_tb = cal_rotate_cost_from_top(current->rank, b, 0);
			int c_bb = cal_rotate_cost_from_bot(current->rank, b, 0);

			printf("c_ta=%d\n", c_ta);
			printf("c_ba=%d\n", c_ba);
			printf("c_tb=%d\n", c_tb);
			printf("c_bb=%d\n", c_bb);
			cheapest_case = calc_cheapest_case(c_ta, c_tb, c_ba * -1, c_bb * -1);
			cheapest_move = calc_cheapest_move(cheapest_case, c_ta, c_tb, c_ba * -1, c_bb * -1);

			if (cheapest_move < abs_min_move)
			{
				abs_min_move = cheapest_move;
				// printf("------------------> update new min\n");
				cheapest[0] = index;
				cheapest[1] = cheapest_move;
				cheapest[2] = cheapest_case;

				cheapest[3] = c_ta;
				cheapest[4] = c_tb;
				cheapest[5] = -1 * c_ba;
				cheapest[6] = -1 * c_bb;
			}
			current = current->prev;
			index++;
			size_a--;
		}

		printf("=========== SUMMARY ===========\n");
		printf("cheapest index = %d\n", cheapest[0]);
		printf("cheapest move = %d\n", cheapest[1]);
		printf("cheapest case = %d\n", cheapest[2]);

		printf("cheapest c_ta = %d\n", cheapest[3]);
		printf("cheapest c_tb = %d\n", cheapest[4]);
		printf("cheapest c_ba = %d\n", cheapest[5]);
		printf("cheapest c_bb = %d\n", cheapest[6]);
		// smart_move(cheapest, a, b, 0);
		// print_stack(a);
		// print_stack(b);
		i--;
	}
	// print_stack(a);
	// #1.5 Triple sort
	// if (!is_sorted(a))
	// 	triple_sort(a);

	// printf("============ MOVE_BACK  ==============\n");
	// print_stack(a);
	// printf("============ MOVE_BACK  ==============\n");
	// // #2 Move back to A
	// while (b->size)
	// {

	// 	index = 0;
	// 	size_a = b->size;
	// 	current = b->top;
	// 	cheapest_case = INT_MAX;
	// 	cheapest_move = INT_MAX;
	// 	abs_min_move = INT_MAX;
	// 	// int i = 1;
	// 	while (current)
	// 	{
	// 		// c_ta ==> c_tb
	// 		// c_ba ==> c_bb
	// 		// c_tb ==> c_ta
	// 		// c_bb ==> c_ba
	// 		// printf("============ LOOP %d ==============\n", index + 1);
	// 		// printf("data = %d\n", current->rank);
	// 		// int c_ta = index;
	// 		// int c_ba = index - a->size;
	// 		// int c_tb = cal_rotate_cost_from_top(current->rank, b);
	// 		// int c_bb = cal_rotate_cost_from_bot(current->rank, b);
	// 		int c_ta = cal_rotate_cost_from_top(current->rank, a, 1);
	// 		int c_ba = cal_rotate_cost_from_bot(current->rank, a, 1);
	// 		int c_tb = index;
	// 		int c_bb = index - b->size;

	// 		// printf("c_ta=%d\n", c_ta);
	// 		// printf("c_ba=%d\n", c_ba);
	// 		// printf("c_tb=%d\n", c_tb);
	// 		// printf("c_bb=%d\n", c_bb);

	// 		cheapest_case = calc_cheapest_case(c_tb, c_ta, c_bb * -1, c_ba * -1);
	// 		cheapest_move = calc_cheapest_move(cheapest_case, c_tb, c_ta, c_bb * -1, c_ba * -1);

	// 		// printf("cheapest case = %d\n", cheapest_case);
	// 		// printf("cheapest move = %d\n", cheapest_move);

	// 		if (cheapest_move < abs_min_move)
	// 		{
	// 			abs_min_move = cheapest_move;
	// 			// printf("------------------> update new min\n");
	// 			cheapest[0] = index;
	// 			cheapest[1] = cheapest_move;
	// 			cheapest[2] = cheapest_case;

	// 			cheapest[3] = c_tb;
	// 			cheapest[4] = c_ta;
	// 			cheapest[5] = -1 * c_bb;
	// 			cheapest[6] = -1 * c_ba;
	// 			// c_ta ==> c_tb
	// 			// c_ba ==> c_bb
	// 			// c_tb ==> c_ta
	// 			// c_bb ==> c_ba
	// 		}
	// 		current = current->prev;
	// 		index++;
	// 		size_a--;
	// 	}

	// 	// printf("=========== SUMMARY ===========\n");
	// 	// printf("cheapest index = %d\n", cheapest[0]);
	// 	// printf("cheapest move = %d\n", cheapest[1]);
	// 	// printf("cheapest case = %d\n", cheapest[2]);

	// 	// printf("cheapest c_ta = %d\n", cheapest[3]);
	// 	// printf("cheapest c_tb = %d\n", cheapest[4]);
	// 	// printf("cheapest c_ba = %d\n", cheapest[5]);
	// 	// printf("cheapest c_bb = %d\n", cheapest[6]);
	// 	smart_move(cheapest, a, b, 1);
	// 	// print_stack(a);
	// 	// print_stack(b);
	// }


	// int c_top = find_pos_from_top(a->min, a);
	// int c_bot = find_pos_from_bot(a->min, a);


	// if (c_top <= (-1 * c_bot))
	// {
	// 	// printf("1\n");
	// 	while (c_top && c_top--)
	// 		r_shift_up(a, NULL, 1);
	// }
	// else if (c_bot != 0 && (-1 * c_bot) < c_top)
	// {
	// 	// printf("2\n");
	// 	int count = -1 * c_bot;
	// 	while (count--)
	// 		rr_shift_down(a, NULL, 1);
	// }

	// printf("============ RESULT  ==============\n");
	// print_stack(a);
	// printf("============ RESULT  ==============\n");
}