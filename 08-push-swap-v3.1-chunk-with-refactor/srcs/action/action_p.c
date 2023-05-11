/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:27:24 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 17:19:26 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// pa,pb v2
void p_move_top(Stack *stack_src,Stack *stack_dst)
{
		if(stack_src->size == 0)
			return;
		int data = stack_src->top->data;
			
		push_with_rank(stack_dst,data,stack_src->top->rank);
		pop(stack_src);
		printf("p%s\n",stack_dst->name);
}