/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 21:58:03 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// FOR INPUT
int main(int argc, char *argv[])
{

	// printf("hi\n");
	Stack *stack_A;
	Stack *stack_B;

	// ### CHECK VALID ARGS
	stack_A = fill_stack(argc, argv);
	stack_B = create_stack("b");
	if (!stack_A)
	{
		// 	free_stack(stack_A);
		free_stack(stack_B);
		write(2, "Error\n", 6);
		return (1);
	}
	// PRESORTED
	if(is_sorted(stack_A))
	{
		free_stack(stack_A);
		free_stack(stack_B);
		// printf("SORTED");
		return (0);
	}
	label_rank(stack_A);
	if (stack_A->size == 2)
		swap_sort(stack_A);
	else if (stack_A->size == 3)
		triple_sort(stack_A);
	else if (stack_A->size == 4)
		forth_sort(stack_A,stack_B);
	else if (stack_A->size == 5)
		five_sort(stack_A,stack_B);
	else
		chunk_sort(stack_A, stack_B);

	// write(1,"OK\n",3);
	// print_stack(stack_A);
	// printf("======================================\n");
	// printf("==========  SORTED STACK-A  ==========\n");
	// printf("======================================\n");
	// print_stack(stack_A);
	// ### EXIT
	free_stack(stack_A);
	free_stack(stack_B);
}
