/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:53:32 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/09 01:14:07 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"



void five_sort(Stack *stack_a,Stack *stack_b)
{
	p_move_top(stack_a,stack_b);
	p_move_top(stack_a,stack_b);
	triple_sort(stack_a);
	swap_sort(stack_b);
	p_move_top(stack_b,stack_a);
	p_move_top(stack_b,stack_a);
}




void small_sort(Stack *stack_a,Stack *stack_b)
{
	if(stack_a->size == 2)
		swap_sort(stack_a);
	else if(stack_a->size == 3)
		triple_sort(stack_a);
	else if(stack_a->size == 5)
		five_sort(stack_a,stack_b);
}