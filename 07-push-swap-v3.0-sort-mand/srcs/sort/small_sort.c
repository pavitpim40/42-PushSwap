/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:10:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 18:02:20 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap_sort(Stack *A)
{
	if (A->size != 2)
		return;
	if (A->top->rank > A->top->prev->rank)
		s_swap_top(A);
}

void triple_sort(Stack *A)
{
	int top;
	int mid;
	int bot;

	top = A->top->rank;
	mid = A->top->prev->rank;
	bot = A->bottom->rank;
	if (top > mid && top > bot && mid < bot)
		r_shift_up(A, NULL);
	else if (top > mid && top > bot && mid > bot)
	{
		s_swap_top(A);
		rr_shift_down(A, NULL);
	}
	else if (bot > mid && bot > top && mid < top)
		s_swap_top(A);
	else if (mid > top && mid > bot && bot < top)
		rr_shift_down(A, NULL);
	else if (mid > top && mid > bot && top < bot)
	{
		s_swap_top(A);
		r_shift_up(A, NULL);
	}
}


// GEN FN
void move_num_in_range(Stack *src, Stack *dst, int num, int max)
{
	Node *top;
	Node *bot;
	int c_top;
	int c_bot;

	while (num <= max)
	{
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
		num++;
	}
}

void forth_sort(Stack *A, Stack *B)
{
	move_num_in_range(A, B, 1, 1);
	triple_sort(A);
	p_move_top(B, A);
}


void five_sort(Stack *A, Stack *B)
{
	move_num_in_range(A, B, 1, 2);
	triple_sort(A);
	swap_sort(B);
	r_shift_up(B, NULL);
	p_move_top(B, A);
	p_move_top(B, A);
}
