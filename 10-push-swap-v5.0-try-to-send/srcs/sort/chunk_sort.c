/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 19:44:49 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	retrieve_chunk(t_stack *a, t_stack *b, int chunk_size, int count)
{
	int	min;
	int	max;

	min = (count - 1) * chunk_size + 1;
	max = (count) * chunk_size;
	while (chunk_size-- && a->size)
		move_first_found_optimize(a, b, min, max);
}

static int	calc_chunk_count(t_stack *a)
{
	if (a->size > 0 && a->size < 100)
		return (2);
	else if (a->size <= 100)
		return (5);
	else if (a->size <= 500)
		return (10);
	else
		return (5);
}

void	chunk_sort(t_stack *A, t_stack *B)
{
	int	chunk_size;
	int	loop_count;
	int	is_swap_down;

	chunk_size = A->size / calc_chunk_count(A);
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
			break ;
		}
	}
	while (B->size)
		move_num(B, A, B->size);
}

static int	is_out_range(int rank, int min, int max)
{
	if (rank < min || rank > max)
		return (1);
	else
		return (0);
}

void	move_first_found_optimize(t_stack *src, t_stack *dst, int min, int max)
{
	t_node	*top;
	t_node	*bot;
	int		c_top;
	int		c_bot;
	int		val;

	top = src->top;
	bot = src->bottom;
	c_top = 0;
	c_bot = 0;
	while (top && is_out_range(top->rank, min, max) && c_top++ <= src->size / 2)
				top = top->prev;
	while (bot && is_out_range(bot->rank, min, max) && c_bot++ <= src->size / 2)
		bot = bot->next;
	if (c_top - 1 <= c_bot)
		rotate_down(src, c_top);
	else
		rotate_up(src, c_bot);
	val = src->top->rank;
	p_move_top(src, dst, 1);
	if (val < (min + max) / 2)
		r_shift_up(dst, NULL, 1);
}
