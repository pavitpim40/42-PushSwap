/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:10:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 17:35:03 by ppimchan         ###   ########.fr       */
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
		// printf("CASE1-2\n");
		p_move_top(A, B);
		// print_stack(A);
		triple_sort(A);
		// print_stack(A);
		p_move_top(B, A);
		// print_stack(A);
		if (top == 4)
			r_shift_up(A, NULL);
		// printf("END---------------------------CASE1-2\n");
		// print_stack(A);
	}
	else if (bot == 1 || bot == 4)
	{
		rr_shift_down(A, NULL);
		p_move_top(A, B);
		triple_sort(A);
		p_move_top(B, A);
		if (bot == 4)
			r_shift_up(A, NULL);
	}
	else
	{
		int c_top = 0;
		Node *curr = A->top;

		while (curr->rank != 1)
		{

			c_top++;
			curr = curr->prev;
		}
		while (c_top--)
		{
			r_shift_up(A, NULL);
		}
		p_move_top(A, B);
		triple_sort(A);
		p_move_top(B, A);
	}
}

void five_sort(Stack *A, Stack *B)
{
	// find Min
	Node *top = A->top;
	Node *bot = A->bottom;
	int c_top = 0;
	int c_bot = 0;

	int bound = 2;
	int start = 1;
	while (start <= bound)
	{
		top = A->top;
		bot = A->bottom;
		c_top = 0;
		c_bot = 0;
		while (top->rank != start && c_top <= A->size / 2)
		{
			c_top++;
			top = top->prev;
		}

		while (bot->rank != start && c_bot <= A->size / 2)
		{
			c_bot++;
			bot = bot->next;
		}

		// printf("c_top=%d\n",c_top);
		// printf("c_bot=%d\n",c_bot);
		if (c_top-1  <= c_bot)
		{
				// printf("PUSH FROM top with data = %d and rank %d\n", top->data, top->rank);
				rotate_down(A, c_top);
			// rotate_down(A, c_top);
		}
		else
		{
			// printf("PUSH FROM Bott with data = %d and rank %d\n", bot->data, bot->rank);
				rotate_up(A, c_bot);
		}

		p_move_top(A, B);
		// print_stack(A);
		start++;
	}
	// print_stack(A);
	// printf("=================SORT-3==================\n");
	triple_sort(A);
	// print_stack(A);
	// printf("=================SORT-2==================\n");
	swap_sort(B);
	// print_stack(B);
	r_shift_up(B, NULL);
	p_move_top(B, A);
	// print_stack(A);
	
	p_move_top(B, A);
	// r_shift_up(A,NULL);
}
