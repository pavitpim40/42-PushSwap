/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 15:25:45 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// FOR INPUT
int main(int argc, char *argv[])
{
	// printf("ac = %d\n",argc);
	// printf("atoi  = %d\n",ft_atoi("one"));
	if(!is_valid_input(argc,argv)) // implicit print Error
	{	
		write(2,"Error\n",6);
		return(1);
	}
	// create Stack
	// printf("test main");
	Stack *stack_A = create_stack("a");
	Stack *stack_B = create_stack("b");
	input_fill(stack_A,argc,argv);

	print_stack(stack_A);
	// s_swap_top(stack_A);
	bubble_sort(stack_A,stack_B);
	print_stack(stack_A);
}
