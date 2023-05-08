/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:53:32 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/09 00:55:14 by ppimchan         ###   ########.fr       */
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