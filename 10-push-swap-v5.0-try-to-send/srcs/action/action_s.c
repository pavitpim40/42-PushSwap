/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:25:30 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 19:59:25 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// sa,sb,ss
void	s_swap_top(t_stack *stack, int mode)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->prev;
	third = second->prev;
	first->prev = third;
	if (third != NULL)
		third->next = first;
	first->next = second;
	second->prev = first;
	second->next = NULL;
	if (third == NULL)
		stack->bottom = first;
	stack->top = second;
	if (mode == 1)
		printf("s%s\n", stack->name);
}

void	s_swap_both(t_stack *a, t_stack *b, int mode)
{
	s_swap_top(a, mode);
	s_swap_top(b, mode);
}
