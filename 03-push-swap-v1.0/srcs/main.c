/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 20:31:52 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int main()
// {
// 	Stack *stack = create_stack("a");
// 	Stack *stack_b = create_stack("b");

//     push(stack, 10);
//     push(stack, 20);
//     push(stack, 30);
//     push(stack, 40);
//     push(stack, 50);

//     print_stack(stack);

// 	// pop(stack);
	
// 	print_stack(stack);
	
// 	// rr_shift_down(stack,NULL);
// 	// p_move_top(stack,stack_b);
// 	// p_move_top(stack,stack_b);
// 	// p_move_top(stack,stack_b); 
// 	print_stack(stack);
// 	// print_stack(stack_b);

// 	// s_swap_top(stack_b);
// 	// action_push_stack(stack_b,stack);
// 	// rr_shift_down(stack,stack_b);
// 	// r_shift_up(stack_b,stack);
// 	// s_swap_top(stack);
// 	// print_stack(stack);
// 	// print_stack(stack_b);

	

// 	printf("TOP %d\n", stack->top->data);
// 	printf("BOT %d\n", stack->bottom->data);
	
// 	free_stack(stack);
// 	free_stack(stack_b);
// }



// FOR INPUT
int main(int argc, char *argv[])
{
	printf("ac = %d\n",argc);

	if(!is_valid_input(argv)) // implicit print Error
		return (1);
	// create Stack
	Stack *stack_A = create_stack("a");
	input_fill(stack_A,argc,argv);

	print_stack(stack_A);
	s_swap_top(stack_A);
	print_stack(stack_A);
}
