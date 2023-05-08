/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:23:04 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/09 00:10:03 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void triple_sort(Stack *stack_a)
{
	int top;
	int mid;
	int bot;

	top = stack_a->top->data;
	mid = stack_a->top->prev->data;
	bot = stack_a->bottom->data;
	// printf("top = \n",top);
	if(top > mid && top > bot && mid < bot)
		r_shift_up(stack_a,NULL);
	else if (top > mid && top > bot && mid > bot)
	{
		s_swap_top(stack_a);
		rr_shift_down(stack_a, NULL);
	}
	else if(bot > mid && bot > top && mid < top)
		s_swap_top(stack_a);
	else if(mid > top && mid > bot && bot < top)
		rr_shift_down(stack_a,NULL);
	else if(mid > top && mid > bot && top < bot)
	{
		s_swap_top(stack_a);
		r_shift_up(stack_a, NULL);
	}
}