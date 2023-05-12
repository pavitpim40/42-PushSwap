/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:48:29 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 14:21:34 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate_down(Stack *A, int c_top)
{
	while (c_top--)
		r_shift_up(A, NULL,1);
}

// bot
void rotate_up(Stack *A, int c_bot)
{
	while (c_bot--)
		rr_shift_down(A, NULL,1);
	rr_shift_down(A, NULL,1);
}

// เอาแค่เลขตัวเดียว
void move_num(Stack *src, Stack *dst, int num)
{
	Node *top;
	Node *bot;
	int c_top;
	int c_bot;

	top = src->top;
	bot = src->bottom;
	c_top = 0;
	c_bot = 0;
	while (top->rank != num && c_top++ <= src->size / 2)
		top = top->prev;
	while (bot->rank != num && c_bot++ <= src->size / 2)
		bot = bot->next;
	if (c_top - 1 <= c_bot)
		rotate_down(src, c_top);
	else
		rotate_up(src, c_bot);
	p_move_top(src, dst,1);
}

// เอาหลายเลข แต่ไล่เรียงตัวแบบเรียงลำกับ
void move_num_in_range(Stack *src, Stack *dst, int start, int end)
{
	while (start <= end)
	{
		move_num(src, dst, start);
		start++;
	}
}

// เอาเลขไหนก็ได้ในช่วงนั้น move ไปก่อน
void move_first_found(Stack *src, Stack *dst, int min, int max)
{
	Node *top;
	Node *bot;
	int c_top;
	int c_bot;

	top = src->top;
	bot = src->bottom;
	c_top = 0;
	c_bot = 0;
	while ((top->rank < min || top->rank > max) && c_top++ <= src->size / 2)
		top = top->prev;
	while ((bot->rank < min || bot->rank > max) && c_bot++ <= src->size / 2)
		bot = bot->next;
	if (c_top - 1 <= c_bot)
		rotate_down(src, c_top);
	else
		rotate_up(src, c_bot);
	p_move_top(src, dst,1);
}

void move_first_found_optimize(Stack *src, Stack *dst, int min, int max)
{
	Node *top;
	Node *bot;
	int c_top;
	int c_bot;
	int val;

	top = src->top;
	bot = src->bottom;
	c_top = 0;
	c_bot = 0;

;
	while (top != NULL && (top->rank < min || top->rank > max) && c_top++ <= src->size / 2)
				top = top->prev;
	
	while (bot && (bot->rank < min || bot->rank > max) && c_bot++ <= src->size / 2)
		bot = bot->next;
		
	if (c_top - 1 <= c_bot)
		rotate_down(src, c_top);
	else
		rotate_up(src, c_bot);
	// Optimize
	val = src->top->rank;
	// find_cheapest_rotate(dst, src->top->rank);
	p_move_top(src, dst,1);
	if (val < (min + max) / 2)
		r_shift_up(dst, NULL,1);
}
