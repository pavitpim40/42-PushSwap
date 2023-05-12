/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:47:16 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 05:04:07 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// RARE COMMAND TO USE
// SS
// RR
// RRR

// int find_pos_by_rank(Stack *src, int target_rank)
// {
// 	Node *top;
// 	Node *bot;
// 	int c_top;
// 	int c_bot;

// 	top = src->top;
// 	bot = src->bottom;
// 	c_top = 0;
// 	c_bot = 0;
// 	while (top->rank != target_rank && c_top++ <= src->size / 2)
// 		top = top->prev;
// 	while (bot->rank != target_rank && c_bot++ <= src->size / 2)
// 		bot = bot->next;
// 	if (c_top - 1 <= c_bot)
// 	return c_top;
// 		// rotate_down(src, c_top);
// 	else
// 	return c_bot;
// 		// rotate_up(src, c_top);
// }

int find_pos_by_rank(Stack *src, int target_rank)
{
	Node *top;
	Node *bot;
	int c_top;
	int c_bot;

	top = src->top;
	bot = src->bottom;
	c_top = 0;
	c_bot = 0;
	while (top->rank != target_rank && c_top++ <= src->size / 2)
		top = top->prev;
	while (bot->rank != target_rank && c_bot++ <= src->size / 2)
		bot = bot->next;
	if (c_top - 1 <= c_bot)
		return c_top;
	// rotate_down(src, c_top);
	else
		return c_bot;
	// rotate_up(src, c_top);
}
// return จำนวน action ที่ต้องทำ

int find_pos_from_top(Stack *src, int target_rank)
{
	Node *top;
	// Node *bot;
	int c_top;
	// int c_bot;

	top = src->top;
	// bot = src->bottom;
	c_top = 0;
	// c_bot = 0;
	if (target_rank < src->bottom->rank && target_rank > src->top->rank)
		return (0);
	while (top && top->prev && target_rank > top->rank && target_rank < top->prev->rank)
	{
		top = top->prev;
		c_top++;
	}

	return c_top;
}

int find_pos_from_bot(Stack *src, int target_rank)
{
	// Node *top;
	Node *bot;
	// int c_top;
	int c_bot;

	// top = src->top;
	bot = src->bottom;
	// c_top = 0;
	c_bot = 0;
	if (target_rank < bot->rank && target_rank > src->top->rank)
		return (0);
	while (bot && bot->next && target_rank > bot->rank && target_rank < bot->next->rank)
	{
		bot = bot->next;
		c_bot++;
	}
	return c_bot;
}

void turk_sort(Stack *A, Stack *B)
{

	p_move_top(A, B);
	p_move_top(A, B);

	// ดูว่า 3 ตัวบนกับ 3 ตัวล่างอันไหน push ไปแล้วถูกสุด เก็บไว้ใน cost แต่ละตัว
	// Node *top_1 = A->top;
	// Node *top_2 = top_1->prev;

	Node *node = A->top;
	while (A->size && node)
	{
		printf("HI\n");
		// ดูตัวบนสุดก่อน -> อยากไล่ดูสัก 4 ตัว
		int default_cost_to_push = 1;
		int cost_send_side = 0; // 1, 2 , 3 
		int total_cost = 0;
		// case 1 : ตัวที่ส่งไปมี rank น้อยสุด หรือ มากสุด
		if (node->rank < B->min || node->rank > B->max)
		{
			// cost_to_move_max_to_top

			int cost_accept_side_from_top = find_pos_by_rank(B, B->max);
			int cost_accept_side_from_bot = find_pos_by_rank(B, B->max);
		
			if (cost_accept_side_from_top <= cost_accept_side_from_bot)
				total_cost = default_cost_to_push+ cost_send_side + cost_accept_side_from_top;
			else
				total_cost = default_cost_to_push + cost_send_side + cost_accept_side_from_bot;
					printf("Total cost  Edge CASE %d\n", total_cost);
		}
		// case 1.2 : ตัวที่ส่งไปเป็นเลขใดๆ -> หมุนจนเจอตำแหน่งระหว่างกลาง เช่น  rank = 3 ให้หมุนไปเจอ rank 2, rank5 (กรณียังไม่มี 4)
		else
		{
			int cost_accept_side_from_top = find_pos_from_top(B, node->rank);
			int cost_accept_side_from_bot = find_pos_from_bot(B, node->rank);
			if (cost_accept_side_from_top <= cost_accept_side_from_bot)
				total_cost = default_cost_to_push+ cost_send_side + cost_accept_side_from_top;
			else
				total_cost = default_cost_to_push+ cost_send_side + cost_accept_side_from_bot;
				printf("Total cost not Edge CASE %d\n", total_cost);
		}
		

		node = node->prev;
	}
}