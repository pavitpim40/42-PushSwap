/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 18:51:35 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void move_chunk_in_range(Stack *A, Stack *B, int loop_count, int chunk_size, int swap_down)
{
	int start = (loop_count - 1) * chunk_size + 1;
	int end = (loop_count)*chunk_size;
	Node *f_top;
	Node *f_bot;
	int c_top;
	int c_bot;
	// move_num_in_range(A,B,start,end);
	while (chunk_size--)
	{
		find_num_in_range_and_move(A,B,start,end);
		if (swap_down == 1)
			r_shift_up(B, NULL);
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

	while (chunk_count)
	{
		move_chunk_in_range(A, B, loop_count, chunk_size, 0);
		if (is_swap_down == 0)
			is_swap_down = 1;
		else
			is_swap_down = 0;

		loop_count++;
		chunk_count--;
		if (A->size == 4)
			forth_sort(A, B);
	}
	while (B->size)
		find_num_and_move(B,A,B->size);
}
