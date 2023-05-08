/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 17:25:21 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// FOR INPUT
int main(int argc, char *argv[])
{

	// printf("%d\n",ft_atoi("-2147483649"));
	// printf("%s\n",ft_itoa(-2147483647));
	if(!is_valid_input(argc,argv)) // implicit print Error
	{	
		write(2,"Error\n",6);
		return(1);
	}
	Stack *stack_A = create_stack("a");
	Stack *stack_B = create_stack("b");
	// printf("ADD of STACK_A %p\n", stack_A);
	// printf("stack size in MAIN  %d\n", stack_A->size);
	if(check_dup_all(argc,argv) == 1)
	{
		// printf("DUPPPPP and EXIT\n");
		write(2,"Error\n",6);
		return (1);
	};
	input_fill(stack_A,argc,argv);
	// printf("stack size in MAIN  %d with ADDRESS %p\n", stack_A->size, &stack_A->size);
	

	print_stack(stack_A);
	// s_swap_top(stack_A);
	// if(stack_A->size != 0)
	bubble_sort(stack_A,stack_B);
	print_stack(stack_A);
}
