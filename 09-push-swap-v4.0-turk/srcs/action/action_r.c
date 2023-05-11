/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:27:32 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 02:28:55 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ra,rb,rr
static void shift_up(Stack *stack) 
{
    if (stack == NULL || stack->size < 2) 
        return;
    
    Node *top = stack->top;
    Node *bottom = stack->bottom;

	stack->top = top->prev;
    top->prev->next = NULL;
    
	bottom->prev = top;
	top->next = bottom;
	top->prev = NULL;
  
    stack->bottom = top;
	
}

void r_shift_up(Stack *stack_one, Stack *stack_two)
{

	if(stack_one && stack_two == NULL)
	{
		shift_up(stack_one);
		printf("r%s\n",stack_one->name);
	}
	else if(stack_one && stack_two)
	{
		shift_up(stack_one);
		shift_up(stack_two);
		printf("rr\n");
	}
}
