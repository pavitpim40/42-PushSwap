/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:10:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 14:34:42 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap_sort(Stack *stack_a)
{
	if (stack_a->size != 2)
		return;
	if (stack_a->top->rank > stack_a->top->prev->rank)
		s_swap_top(stack_a);
}

void triple_sort(Stack *stack_a)
{
	int top;
	int mid;
	int bot;

	top = stack_a->top->rank;
	mid = stack_a->top->prev->rank;
	bot = stack_a->bottom->rank;
	// printf("top = \n",top);
	if (top > mid && top > bot && mid < bot)
		r_shift_up(stack_a, NULL);
	else if (top > mid && top > bot && mid > bot)
	{
		s_swap_top(stack_a);
		rr_shift_down(stack_a, NULL);
	}
	else if (bot > mid && bot > top && mid < top)
		s_swap_top(stack_a);
	else if (mid > top && mid > bot && bot < top)
		rr_shift_down(stack_a, NULL);
	else if (mid > top && mid > bot && top < bot)
	{
		s_swap_top(stack_a);
		r_shift_up(stack_a, NULL);
	}
}

void forth_sort(Stack *A, Stack *B)
{
	int top;
	int bot;
	// Node *bot
	top = A->top->rank;
	bot = A->bottom->rank;

	if (top == 1 || top == 4)
	{
		printf("CASE1-2\n");
		p_move_top(A, B);
		print_stack(A);
		triple_sort(A);
		print_stack(A);
		p_move_top(B, A);
		print_stack(A);
		if (top == 4)
			r_shift_up(A, NULL);
		printf("END---------------------------CASE1-2\n");
		print_stack(A);
	}
	else if (bot == 1 || bot == 4)
	{
		printf("CASE3-4\n");

		printf("ACTION-1\n");
		rr_shift_down(A, NULL);
		print_stack(A);

		printf("ACTION-2\n");
		p_move_top(A, B);
		print_stack(A);

		printf("ACTION-3\n");
		triple_sort(A);
		print_stack(A);
		p_move_top(B,A);
		print_stack(A);
		if (bot == 4)
			rr_shift_down(A, NULL);
		printf("END---------------------------CASE3-4\n");
		print_stack(A);
	}
	else {
		int c_top = 0;
		Node *curr = A->top;
		printf("CASE-ELSE\n");
		while(curr->rank != 1)
		{

			c_top++;
			curr = curr->prev;
		}
		printf("c_top=%d\n",c_top);
		while (c_top--)
		{
			r_shift_up(A,NULL);
		}
		p_move_top(A,B);
		triple_sort(A);
		p_move_top(B,A);
		
	}
}

void five_sort(Stack *stack_a, Stack *stack_b)
{
	p_move_top(stack_a, stack_b);
	p_move_top(stack_a, stack_b);
	triple_sort(stack_a);
	swap_sort(stack_b);
	p_move_top(stack_b, stack_a);
	p_move_top(stack_b, stack_a);
}
