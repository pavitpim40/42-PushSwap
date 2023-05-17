/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:27:32 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 20:01:46 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ra,rb,rr
static void	shift_up(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;

	if (stack == NULL || stack->size < 2)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	stack->top = top->prev;
	top->prev->next = NULL;
	bottom->prev = top;
	top->next = bottom;
	top->prev = NULL;
	stack->bottom = top;
}

void	r_shift_up(t_stack *stack_one, t_stack *stack_two, int mode)
{
	if (stack_one && stack_two == NULL)
	{
		shift_up(stack_one);
		if (mode == 1)
			printf("r%s\n", stack_one->name);
	}
	else if (stack_one && stack_two)
	{
		shift_up(stack_one);
		shift_up(stack_two);
		if (mode == 1)
			printf("rr\n");
	}
}
