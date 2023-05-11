/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 18:09:40 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push_each_chunk(Stack *A, Stack *B, int loop_count, int chunk_size, int swap_down)
{
	int start = (loop_count - 1) * chunk_size + 1;
	int end = (loop_count)*chunk_size;
	Node *f_top;
	Node *f_bot;
	int c_top;
	int c_bot;

	while (chunk_size--)
	{
		f_top = A->top;
		f_bot = A->bottom;
		c_top = 0;
		c_bot = 0;
		while ((f_top->rank < start || f_top->rank > end) && c_top++ <= A->size / 2)
			f_top = f_top->prev;
		while ((f_bot->rank < start || f_bot->rank > end) && c_bot++ <= A->size / 2)
			f_bot = f_bot->next;
		if (c_top - 1 <= c_bot)
			rotate_down(A, c_top);
		else
			rotate_up(A, c_bot);
		p_move_top(A, B);
		if (swap_down == 1)
			r_shift_up(B, NULL);
	}
}

void push_back(Stack *A, Stack *B)
{

	int c_top = 0;
	int c_bot = 0;
	Node *f_top = B->top;
	Node *f_bot = B->bottom;

	while (B->size)
	{
		c_top = 0;
		c_bot = 0;
		f_top = B->top;
		f_bot = B->bottom;
		while (f_top->rank != B->size && c_top++ <= B->size / 2)
			f_top = f_top->prev;
		while (f_bot->rank != B->size && c_bot++ <= B->size / 2)
			f_bot = f_bot->next;
		if (c_top - 1 <= c_bot)
			rotate_down(B, c_top);
		else
			rotate_up(B, c_bot);
		p_move_top(B, A);
	}
}


void chunk_sort(Stack *A, Stack *B)
{
	int chunk_count;
	chunk_count = 0;
	if (A->size <= 100)
		chunk_count = 5;
	else if (A->size <= 500)
		chunk_count = 11;

	int chunk_size = A->size / chunk_count;
	int loop_count = 1;
	int is_swap_down = 0;
	// int size = chunk_size;
	while (chunk_count)
	{
		push_each_chunk(A, B, loop_count, chunk_size, is_swap_down);
		if (is_swap_down == 0)
			is_swap_down = 1;
		else
			is_swap_down = 0;
		loop_count++;
		chunk_count--;
	}

	push_back(A, B);
}
