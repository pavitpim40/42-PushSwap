/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:46:58 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 21:57:40 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int is_sorted(Stack *stack)
{

	if (!stack)
		return (0);
	Node *current = stack->top;
	Node *next = current->prev;
	while (current != NULL && next !=NULL)
	{
		if (current->data < next->data)
		{
			current = current->prev;
			next = next->prev;
		}
		else 
			return (0);
	}
	return (1);
}