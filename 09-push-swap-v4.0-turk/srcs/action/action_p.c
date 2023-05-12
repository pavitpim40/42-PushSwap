/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:27:24 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 14:54:53 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// pa,pb v2
void p_move_top(Stack *stack_src,Stack *stack_dst,int mode)
{
		if(stack_src->size == 0)
			return;
		int data = stack_src->top->data;
		// printf("INTERNAL P\n");
		push_with_rank(stack_dst,data,stack_src->top->rank);
		// printf("From Stack:%s->%s\n",stack_src->name,stack_dst->name);
		// printf("From Stack:%s\n",stack_src->name);
		// print_stack(stack_src);
		// print_stack(stack_dst);
		pop(stack_src);
		
		if(mode == 1)
			printf("p%s\n",stack_dst->name);
}

void p_move_top_with_rank(Stack *stack_src,Stack *stack_dst,int rank, int mode)
{
		if(stack_src->size == 0)
			return;
		int data = stack_src->top->data;
			
		push_with_rank(stack_dst,data,rank);
		pop(stack_src);
		if(mode == 1)
			printf("p%s\n",stack_dst->name);
}