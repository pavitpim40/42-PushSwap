/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 22:55:05 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// FOR INPUT
int main(int argc, char *argv[])
{

	// printf("%d\n",ft_atoi("-2147483649"));
	// printf("%s\n",ft_itoa(-2147483647));
	// printf("%d\n",ft_atoi("2147483648"));
	// printf("%s\n",ft_itoa(2147483648));
	// printf("ARGC %d\n", argc);
	// ## START
	Stack *stack_A;
	Stack *stack_B;

	// ### CHECK VALID ARGS
	stack_A = input_check(argc, argv);
	stack_B = create_stack("b");
	if (!stack_A)
	{
		free_stack(stack_A);
		free_stack(stack_B);
		write(2, "Error\n", 6);
		return (1);
	}

	// print_stack(stack_A);
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
	// printf("size %s\n", stack_A->name);
	bubble_sort(stack_A, stack_B);
	// write(1,"OK\n",3);
	// print_stack(stack_A); 

	// ### EXIT
	free_stack(stack_A);
	free_stack(stack_B);
}
