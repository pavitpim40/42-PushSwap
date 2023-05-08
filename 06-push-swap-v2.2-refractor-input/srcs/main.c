/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 18:58:14 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// FOR INPUT
int main(int argc, char *argv[])
{

	// printf("%d\n",ft_atoi("-2147483649"));
	// printf("%s\n",ft_itoa(-2147483647));


	// ## START
	Stack *stack_A;
	// Stack *stack_B;

	// ### CHECK VALID ARGS
	stack_A = input_check(argc,argv);
	print_stack(stack_A);
	// if(!is_valid_input(argc,argv)) // implicit print Error
	// {	
	// 	write(2,"Error\n",6);
	// 	return(1);
	// }

	// ### CHECK OVERFLOW and DUP with Stack;
	// if(check_dup_all(argc,argv) == 1)
	// {
	// 	write(2,"Error\n",6);
	// 	return (1);
	// };
	// ### FILL IN STACK
	// stack_A = create_stack("a");
	// stack_B = create_stack("b");
	// input_fill(stack_A,argc,argv);
	

	// ### SORTED
	// print_stack(stack_A);
	// s_swap_top(stack_A);
	// if(stack_A->size != 0)
	// bubble_sort(stack_A,stack_B);
	// print_stack(stack_A);

	// ### EXIT
	// free_stack(stack_A);
	// free_stack(stack_B);
}
