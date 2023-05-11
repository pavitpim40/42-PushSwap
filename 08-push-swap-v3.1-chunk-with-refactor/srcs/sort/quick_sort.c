/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:06:44 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/09 18:52:52 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// void quick_sort(Stack *stack_a,Stack *stack_b)
// {
// 	Node *current; // green
// 	Node *latest_less_or_equal; // orange
// 	Node *pivot_node;

// 	current = stack_a->top;
// 	latest_less_or_equal = NULL; // before top
// 	pivot_node = stack_a->bottom;

// 	while(current->index != pivot_node->index)
// 	{
// 		if(current->data > pivot_node->data) // case 1 : เจอเลขมากกว่า Pivot ไม่ต้องทำอะไร
// 		{
// 			current = current->prev;
// 			p_move_top(stack_a,stack_b);
// 		}
// 		else if(current->data <= pivot_node->data) // case 2,3 เจอเลขน้อยกว่าหรือเท่ากับ pivot
// 		{
// 			// ** latest_less_or_less ต้องขยับมารอ 1
// 			// if(latest_less_or_equal == NULL)
// 			// 	latest_less_or_equal = stack_a->top;
// 			// else
// 			// 	latest_less_or_equal = latest_less_or_equal->prev;

// 			latest_less_or_equal = stack_a->top;

// 			if(current != latest_less_or_equal) // case 2 : Swap
// 			{
// 			}
// 			else // case 3 : current เดินต่อ, ซ่อนส้มไว้ล่าง
// 			{
// 				printf("CASE3: Current %d\n",current->data);
// 				printf("CASE3: LLOE %d\n",latest_less_or_equal->data);
// 				current = current->prev;
// 				// printf("CASE3: Current %d\n",current->data);
// 				// printf("CASE3: LLOE %d\n",latest_less_or_equal->data);
// 				r_shift_up(stack_a,NULL); //ส้มจะชี้มาล่างสุดบรรทัดนี้ แต่เขียวจะตามมาด้วยน่ะ
// 			}
// 		}
// 	}
// 	print_stack(stack_b);
// }

// NEW STRATEGY_QUICK_SORT IN STACK
// MORE PUSH BOT IN CURRENT STACK
// LESS OR E PUSH OTHER STACK

// void quick_sort(Stack *src,Stack *dst, int size)
// {
// 	Node *current;
// 	Node *pivot_node;

// 	current = src->top;
// 	pivot_node = src->bottom;

// 	if(size == 2)
// 		return;

// 	while(current->index != pivot_node->index)
// 	{
// 		if(current->data > pivot_node->data)
// 		{
// 				printf("insert bot with data=%d\n",current->data);
// 				r_shift_up(src, NULL);
// 		}

// 		else
// 		{
// 			printf("throw to B  with data=%d\n",current->data);
// 			p_move_top(src, dst);
// 		}

// 		current = src->top;
// 	}
// 	print_stack(src);
// 	// p_move_top(src,dst);
// 	s_swap_top(src);
// 	r_shift_up(src, NULL);

// 	print_stack(src);
// 	// print_stack(dst);

// 	// quick_sort(dst,src,dst->size);
// 	// quick_sort(src,dst,src->size);

// 	while (src->size < size)
// 		p_move_top(dst,src);

// 	print_stack(src);

// }

// void quick_sort(Stack *stack_a, Stack *stack_b)
// {
// 	push(stack_a, stack_a->bottom->data); // assume pivot is already in stack_a
// 	while (stack_a->size > 1)
// 	{
// 		int pivot = pop(stack_a);
// 		while (stack_a->size > 0)
// 		{
// 			int value = pop(stack_a);
// 			if (value <= pivot)
// 			{
// 				push(stack_b, value);
// 			}
// 			else
// 			{
// 				push(stack_a, value);
// 			}
// 		}
// 		quick_sort(stack_b, stack_a);
// 		push(stack_a, pivot);
// 	}
// 	while (stack_b->size > 0)
// 	{
// 		push(stack_a, pop(stack_b));
// 	}
// }


// ## 1 PSEUDO_Q_SORT, Recursive ?

// void quick_sort(Stack *src, Stack *dst)
// {
// 	Node *current;
// 	Node *pivot;

// 	current = src->top;
// 	pivot = src->bottom; // may run into problem , when recursive

// 	while(current && current->index != pivot->index)
// 	{
// 		if(current->data < pivot->data)
// 			p_move_top(src,dst);
// 		else
// 			r_shift_up(src,NULL);
// 		current = current->prev;
// 	}
// 	print_stack(src);
// 	print_stack(dst);
// }

// ## 2 Q_SORT

void quicksort(Stack *stack_a, Stack *stack_b) {
    
	if (stack_a->size <= 1)
        return;
    
    int pivot = stack_a->top->data;
    int size = stack_a->size;
    
    while (size--) {
        int value = pop(stack_a);
        if (value <= pivot) {
            push(stack_b, value);
        } else {
            push(stack_a, value);
        }
    }
    
    // quicksort(stack_a, stack_b);
    // quicksort(stack_b, stack_a);
    
    // push(stack_a, pivot);
    // while (stack_b->size > 0) {
    //     push(stack_a, pop(stack_b));
    // }
}

