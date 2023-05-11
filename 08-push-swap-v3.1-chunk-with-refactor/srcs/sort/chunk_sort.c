/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 19:34:34 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void move_chunk_in_range(Stack *A, Stack *B,  int chunk_size,int loop_count, int swap_down)
{
	int min = (loop_count - 1) * chunk_size + 1;
	int max = (loop_count) * chunk_size;

	while (chunk_size--)
	{
		move_first_found_in_range(A, B, min, max);
		if (swap_down == 1)
			r_shift_up(B, NULL);
	}
}

static int calc_chunk_count(Stack *A)
{
	if (A->size <= 100)
		return (5) ;
	else if (A->size <= 500)
		return (11);
	else
		return 5;
}

void chunk_sort(Stack *A, Stack *B)
{
	int chunk_size;
	int loop_count;
	int is_swap_down;

	chunk_size = A->size / calc_chunk_count(A);;
	loop_count = 1;
	is_swap_down = 0;
	while (A->size)
	{
		move_chunk_in_range(A, B, chunk_size, loop_count, 0);
		if (is_swap_down == 0)
			is_swap_down = 1;
		else
			is_swap_down = 0;
		loop_count++;
		if (A->size == 4)
		{
			forth_sort(A, B);
			break;
		}
	}
	while (B->size)
		move_num(B, A, B->size);
}