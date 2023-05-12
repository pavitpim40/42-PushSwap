/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:27:24 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 19:44:29 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// pa,pb v2
void	p_move_top(t_stack *stack_src, t_stack *stack_dst, int mode)
{
	int	data;

	if (stack_src->size == 0)
		return ;
	data = stack_src->top->data;
	push_with_rank(stack_dst, data, stack_src->top->rank);
	pop(stack_src);
	if (mode == 1)
		printf("p%s\n", stack_dst->name);
}

void	p_move_top_with_rank(t_stack *src, t_stack *dst, int rank, int mode)
{
	int	data;

	if (src->size == 0)
		return ;
	data = src->top->data;
	push_with_rank(dst, data, rank);
	pop(src);
	if (mode == 1)
		printf("p%s\n", dst->name);
}
