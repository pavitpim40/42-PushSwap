/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:25:30 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 02:26:32 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// sa,sb,ss
void s_swap_top(Stack *stack)
{
	if(stack->size < 2)
		return;
	
	Node* first = stack->top;
	Node* second = first->prev;
	Node* third = second->prev;

	first->prev = third;
	if(third != NULL)
		third->next = first;
	first->next = second;
	second->prev = first;
	second->next = NULL;
	if(third == NULL)
		stack->bottom = first;
	stack->top = second;
	printf("s%s\n",stack->name);
}
