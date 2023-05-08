/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 23:13:14 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// FOR INPUT
int main(int argc, char *argv[])
{

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

	if(stack_A->size == 2)
		swap_sort(stack_A);
	bubble_sort(stack_A, stack_B);


	// ### EXIT
	free_stack(stack_A);
	free_stack(stack_B);
}
