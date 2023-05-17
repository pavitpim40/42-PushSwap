/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:10:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 19:44:29 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_sort(t_stack *A)
{
	if (A->size != 2)
		return ;
	if (A->top->rank > A->top->prev->rank)
		s_swap_top(A, 1);
}

void	triple_sort(t_stack *A)
{
	int	top;
	int	mid;
	int	bot;

	top = A->top->rank;
	mid = A->top->prev->rank;
	bot = A->bottom->rank;
	if (top > mid && top > bot && mid < bot)
		r_shift_up(A, NULL, 1);
	else if (top > mid && top > bot && mid > bot)
	{
		s_swap_top(A, 1);
		rr_shift_down(A, NULL, 1);
	}
	else if (bot > mid && bot > top && mid < top)
		s_swap_top(A, 1);
	else if (mid > top && mid > bot && bot < top)
		rr_shift_down(A, NULL, 1);
	else if (mid > top && mid > bot && top < bot)
	{
		s_swap_top(A, 1);
		r_shift_up(A, NULL, 1);
	}
}

void	forth_sort(t_stack *A, t_stack *B)
{
	move_num_in_range(A, B, A->min_rank, A->min_rank);
	triple_sort(A);
	p_move_top(B, A, 1);
}

void	five_sort(t_stack *A, t_stack *B)
{
	move_num_in_range(A, B, A->min_rank, A->min_rank + 1);
	triple_sort(A);
	swap_sort(B);
	r_shift_up(B, NULL, 1);
	p_move_top(B, A, 1);
	p_move_top(B, A, 1);
}
