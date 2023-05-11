/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 02:16:45 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void retrieve_chunk(Stack *A, Stack *B,  int chunk_size,int loop_count)
{
	int min = (loop_count - 1) * chunk_size + 1;
	int max = (loop_count) * chunk_size;

	while (chunk_size-- &&  A->size)
	{
	
			move_first_found_optimize(A, B, min, max);
		// if (swap_down == 1)
		// 	r_shift_up(B, NULL);
	}
}
 
static int calc_chunk_count(Stack *A)
{
	if (A->size > 0 && A->size <100)
		return (2);
	else if (A->size <= 100)
		return (5) ;
	else if (A->size <= 500)
		return (10);
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
		retrieve_chunk(A, B, chunk_size, loop_count);
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
	// print_stack(A);
	while (B->size)
		move_num(B, A, B->size);
}
