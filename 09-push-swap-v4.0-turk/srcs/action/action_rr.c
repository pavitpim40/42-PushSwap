/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:27:40 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 14:17:53 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// rra,rrb,rrr
static void shift_down(Stack *stack)
{
	if (stack == NULL || stack->size < 2) 
        return;
    
    Node *top = stack->top;
    Node *bottom = stack->bottom;

	stack->bottom = bottom->next;
	top->next = bottom;
	bottom->prev = top;
	bottom->next->prev = NULL;
	bottom->next = NULL;

	stack->top = bottom;
	
}

void rr_shift_down(Stack *stack_one, Stack *stack_two, int mode)
{

	if(stack_one && stack_two == NULL)
	{
		shift_down(stack_one);
		if(mode == 1)
			printf("rr%s\n",stack_one->name);
	}
	else if(stack_one && stack_two)
	{
		shift_down(stack_one);
		shift_down(stack_two);
		if(mode == 1)
			printf("rrr\n");
	}
}


