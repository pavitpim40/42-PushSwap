/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:48:29 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 18:49:59 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate_down(Stack *A, int c_top)
{
	while (c_top--)
		r_shift_up(A, NULL);
}

// bot
void rotate_up(Stack *A, int c_bot)
{
	while (c_bot--)
		rr_shift_down(A, NULL);
	rr_shift_down(A, NULL);
}

void find_num_and_move(Stack *src, Stack *dst, int num)
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
	p_move_top(src, dst);
}

void find_num_in_range_and_move(Stack *src, Stack *dst, int start, int end)
{
	Node *top;
	Node *bot;
	int c_top;
	int c_bot;

	top = src->top;
	bot = src->bottom;
	c_top = 0;
	c_bot = 0;
	while ((top->rank < start || top->rank > end) && c_top++ <= src->size / 2)
		top = top->prev;
	while ((bot->rank < start || bot->rank > end) && c_bot++ <= src->size / 2)
		bot = bot->next;
	if (c_top - 1 <= c_bot)
		rotate_down(src, c_top);
	else
		rotate_up(src, c_bot);
	p_move_top(src, dst);
}

void move_num_in_range(Stack *src, Stack *dst, int num, int max)
{
	while (num <= max)
	{
		find_num_and_move(src, dst, num);
		num++;
	}
}