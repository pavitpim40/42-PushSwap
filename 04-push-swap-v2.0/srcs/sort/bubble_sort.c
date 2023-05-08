/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:06:40 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 11:58:20 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// void bubble_sort(Stack *stack_a, Stack *stack_b)
// {
// 	Node *outer;
// 	Node *inner;
// 	int count;
// 	int swap;

// 	outer = stack_a->top;
// 	inner = outer->prev;
// 	count = stack_a->size;
// 	swap = 0;
// 	while(count--)
// 	{

// 		printf("count %d\n",count);
// 		while(inner != NULL)
// 		{
// 			if(outer->data > inner->data)
// 			{
// 				printf("SWAP\n");
// 				s_swap_top(stack_a);
// 				p_move_top(stack_a,stack_b);
// 				swap++;
// 				print_stack(stack_a);
// 				print_stack(stack_b);
// 			}
// 			if(inner->prev)
// 				inner = inner->prev;
// 			else
// 				break;
// 		}
// 		while(swap--)
// 			p_move_top(stack_b,stack_a);
// 		outer = stack_a->top;
// 	}

// }

// Correct Version
// void bubble_sort(Stack *stack_a, Stack *stack_b)
// {
// 	Node *element_1 = stack_a->top;
// 	Node *element_2 = stack_a->top->prev;
// 	int count;
// 	// int swap;
// 	int size = stack_a->size;
// 	count =0;
// 	int count_inner = 0;
// 	printf("stack %d\n", stack_b->size);

// 	while (count < size - 1)
// 	{
// 			element_1 = stack_a->top;
// 			element_2 = stack_a->top->prev;

// 			printf("outer===================== %d\n", count);
// 			count_inner = 0;
// 			while (count_inner< size-count-1)
// 			{
// 			print_stack(stack_a);
// 			printf("inner %d\n", count_inner);
// 			printf("DATA INNER EL1 = %d  EL2 = %d\n", element_1->data,element_2->data);
// 				if(element_1->data > element_2->data)
// 				{
// 					printf("SWAP %d %d\n", element_1->data,element_2->data);

// 					// element_2 = element_2->prev; // for next loop
// 					s_swap_top(stack_a);
// 					p_move_top(stack_a,stack_b);
// 					element_1 = stack_a->top;
// 					element_2 = element_1->prev;
// 					;
// 				}
// 			// element_1 = element_1->prev;
// 			// printf("EL2 %d\n",element_2->data);
// 			count_inner++;
// 			print_stack(stack_a);
// 			}
// 			while (stack_a->size < size)
// 				p_move_top(stack_b,stack_a);
// 			// print_stack(stack_a);
// 			count++;

// 	}

// }

static void do_bubble(Stack *stack_a, Stack *stack_b)
{
	s_swap_top(stack_a);
	p_move_top(stack_a, stack_b);
}

void bubble_sort(Stack *stack_a, Stack *stack_b)
{
	Node *element_1;
	Node *element_2;
	int count_inner;
	int count;
	int size;

	size = stack_a->size;
	count = 0;
	while (count++ < size - 1)
	{
		element_1 = stack_a->top;
		element_2 = element_1->prev;
		count_inner = 0;
		while (count_inner++ < size - count)
		{
			if (element_1->data > element_2->data)
			{
				do_bubble(stack_a, stack_b);
				element_1 = stack_a->top;
				element_2 = element_1->prev;
			}
		}
		while (stack_a->size < size)
			p_move_top(stack_b, stack_a);
	}
}
