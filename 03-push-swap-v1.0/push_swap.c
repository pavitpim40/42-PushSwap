/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 15:40:01 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
int main()
{
	printf("ht");
	Stack *stack = create_stack("a");
	Stack *stack_b = create_stack("b");

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    print_stack(stack);

	// pop(stack);
	// swap_head(stack);
	// rr_shift_down(stack,NULL);
	// p_move_top(stack,stack_b);
	// p_move_top(stack,stack_b);
	// p_move_top(stack,stack_b); 
	print_stack(stack);
	print_stack(stack_b);

	// s_swap_top(stack_b);
	// action_push_stack(stack_b,stack);
	// rr_shift_down(stack,stack_b);
	// r_shift_up(stack_b,stack);
	// s_swap_top(stack);
	// print_stack(stack);
	// print_stack(stack_b);

	// swap_head(stack_b);
	// action_reverse_rotate(stack);
	// print_stack(stack);
	// print_stack(stack_b);

	// swap_head(stack);
	// print_stack(stack);

	printf("TOP %d\n", stack->top->data);
	printf("BOT %d\n", stack->bottom->data);
	
	free_stack(stack);
	free_stack(stack_b);
}