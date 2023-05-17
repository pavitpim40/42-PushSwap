/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:27:40 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 20:03:42 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// rra,rrb,rrr
static void	shift_down(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;

	if (stack == NULL || stack->size < 2)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	stack->bottom = bottom->next;
	top->next = bottom;
	bottom->prev = top;
	bottom->next->prev = NULL;
	bottom->next = NULL;
	stack->top = bottom;
}

void	rr_shift_down(t_stack *stack_one, t_stack *stack_two, int mode)
{
	if (stack_one && stack_two == NULL)
	{
		shift_down(stack_one);
		if (mode == 1)
			printf("rr%s\n", stack_one->name);
	}
	else if (stack_one && stack_two)
	{
		shift_down(stack_one);
		shift_down(stack_two);
		if (mode == 1)
			printf("rrr\n");
	}
}
