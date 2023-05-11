/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 18:03:33 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void chunk_sort(Stack *A, Stack *B)
{
	int chunk_count;
	chunk_count = 0;
	if (A->size <= 100)
		chunk_count = 5;
	else if (A->size <= 500)
		chunk_count = 11;

	int chunk_size = A->size / chunk_count;
	int size = A->size / chunk_count;
	int loop_count = 1;
	int is_swap_down = 0;

	while (chunk_count)
	{
		int start = (loop_count - 1) * chunk_size + 1;
		int end = (loop_count)*chunk_size;
		move_num_in_range(A, B, start, end);
		size = chunk_size;
		while (size--)
			if (is_swap_down == 1)
				r_shift_up(B, NULL);
		loop_count++;
		if (is_swap_down == 0)
			is_swap_down = 1;
		else
			is_swap_down = 0;
		chunk_count--;
	}

	// printf("MAX  = %d\n", find_max(B));
	// push max back;
	int max = B->size;
	int c_top = 0;
	int c_bot = 0;
	if (B->size <= 100)
		chunk_count = 5;
	else if (B->size <= 500)
		chunk_count = 11;
	Node *f_top = B->top;
	Node *f_bot = B->bottom;
	chunk_size = B->size / chunk_count;

	// #1 ทำจนกว่าจะครบทุก chunk

	// printf("Chunk_size %d\n", chunk_size);
	while (B->size)
	{
		// {
		c_top = 0;
		c_bot = 0;
		f_top = B->top;
		f_bot = B->bottom;
		max = B->size;
		// printf("====================ROUND:%d==================\n", 6 - chunk_size);
		// printf("F_TOP_RANK = %d\n", f_top->rank);
		// printf("MAX = %d\n", max);
		while (f_top->rank != max && c_top <= B->size / 2)
		{
			c_top++;
			f_top = f_top->prev;
		}
		while (f_bot->rank != max && c_bot <= B->size / 2)
		{
			c_bot++;
			f_bot = f_bot->next;
		}
		// printf("C_TOP = %d\n", c_top);
		// printf("C_BOT = %d\n", c_bot);
		// printf("Chunk_size %d\n", chunk_size);
		if (c_top - 1 <= c_bot)
		{
			rotate_down(B, c_top);
			// printf("TOP:PUSH EL = %d with index %d\n", B->top->data, B->top->rank);
			p_move_top(B, A);
		}
		else
		{
			// push from bot;
			rotate_up(B, c_bot);
			// printf("BOT:PUSH EL = %d with index %d\n", B->top->data, B->top->rank);
			p_move_top(B, A);
		}
	}
}
