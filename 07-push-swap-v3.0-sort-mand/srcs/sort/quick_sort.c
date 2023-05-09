/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:06:44 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/09 10:34:58 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void quick_sort(Stack *stack_a,Stack *stack_b)
{
	Node *current; // green
	Node *latest_less_or_equal; // orange
	Node *pivot_node;
	
	current = stack_a->top;
	latest_less_or_equal = NULL; // before top
	pivot_node = stack_a->bottom;

	while(current->index != pivot_node->index)
	{
		if(current->data > pivot_node->data) // case 1 : เจอเลขมากกว่า Pivot ไม่ต้องทำอะไร
			current = current->prev;
		else if(current->data <= pivot_node->data) // case 2,3 เจอเลขน้อยกว่าหรือเท่ากับ pivot
		{
			// ** latest_less_or_less ต้องขยับมารอ 1 
			// if(latest_less_or_equal == NULL)
			// 	latest_less_or_equal = stack_a->top;
			// else
			// 	latest_less_or_equal = latest_less_or_equal->prev;
			
			latest_less_or_equal = stack_a->top;
			
			if(current != latest_less_or_equal) // case 2 : Swap
			{
				p_move_top(stack_a,stack_b);
			}
			else // case 3 : current เดินต่อ, ซ่อนส้มไว้ล่าง
			{
				printf("CASE3: Current %d\n",current->data);
				printf("CASE3: LLOE %d\n",latest_less_or_equal->data);
				current = current->prev;
				printf("CASE3: Current %d\n",current->data);
				printf("CASE3: LLOE %d\n",latest_less_or_equal->data);
				r_shift_up(stack_a,NULL); //ส้มจะชี้มาล่างสุดบรรทัดนี้ แต่เขียวจะตามมาด้วยน่ะ
			}
		}
	}
	print_stack(stack_b);
}