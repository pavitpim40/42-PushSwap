/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:44:47 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 15:48:18 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// pa,pb v2
void p_move_top(Stack *stack_src,Stack *stack_dst)
{
		if(stack_src->size == 0)
			return;
		int data = stack_src->top->data;
		push(stack_dst,data);
		pop(stack_src);
		printf("p%s\n",stack_dst->name);
}
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

void rr_shift_down(Stack *stack_one, Stack *stack_two)
{

	if(stack_one && stack_two == NULL)
	{
		shift_down(stack_one);
		printf("rr%s\n",stack_one->name);
	}
	else if(stack_one && stack_two)
	{
		shift_down(stack_one);
		shift_down(stack_two);
		printf("rrr\n");
	}
}


