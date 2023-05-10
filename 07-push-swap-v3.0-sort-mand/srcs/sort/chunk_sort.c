/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 12:03:36 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static int find_max(Stack *B)
// {
// 	Node *current;
// 	int max;
// 	printf("a\n");
// 	current = B->top;
// 	max = B->size;
// 	while (current)
// 	{

// 		if (current->rank == -1 && current->data < max)
// 			max = current->data;
// 		current = current->prev;
// 	}
// 	return (max);
// }

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

// int out_of_bound(int rank,int loop_count, int chunk_size)
// {
// 	int start = (loop_count - 1) * chunk_size + 1;
// 	int end = (loop_count)*chunk_size;
// 	if(rank < start || rank > end)
// 		return (1);
// 	else
// 		return (0);
// }

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

void chunk_sort(Stack *A, Stack *B)
{
	int chunk_count;
	chunk_count=0;
	if(A->size <= 100)
		chunk_count = 5;
	else if(A->size <= 500)
		chunk_count = 11;

	int chunk_size = A->size / chunk_count;
	int loop_count = 1;
	int is_swap_down = 0;
	while (chunk_count)
	{
		push_each_chunk(A, B, loop_count, chunk_size, is_swap_down);
		// print_stack(B);
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
	if(B->size <= 100)
		chunk_count = 5;
	else if(B->size <= 500)
		chunk_count = 11;
	Node *f_top = B->top;
	Node *f_bot = B->bottom;
	chunk_size = B->size / chunk_count;

	// #1 ทำจนกว่าจะครบทุก chunk

	// printf("Chunk_size %d\n", chunk_size);
	while (chunk_count)
	{
		// max = B->size;
		// ในแต่ละ chunk ให้หาเลขจนครบ
		while (chunk_size)
		{
			c_top = 0;
			c_bot = 0;
			f_top = B->top;
			f_bot = B->bottom;
			max = B->size;
			printf("====================ROUND:%d==================\n", 6 - chunk_size);
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
				rotate_down(B,c_top);
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

			chunk_size--;
		}
		// printf("Chunk_COUNT %d\n", chunk_count);
		chunk_size = 5;
		chunk_count--;
	}
}
