/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 13:19:12 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void error_and_exit(char *word, Stack *A,Stack *B)
{
	if(A)
		free_stack(A);
	if(B)
		free_stack(B);
	write(2, word, ft_strlen(word));
	exit(1);
}

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
		error_and_exit("Error\n",stack_A,stack_B);
	
	// PRESORTED
	if (is_sorted(stack_A))
	{
		free_stack(stack_A);
		free_stack(stack_B);
		// printf("SORTED");
		return (0);
	}
	label_rank(stack_A);

	// printf("======================================\n");
	// printf("========== STARTING SORTED ==========\n");
	// printf("======================================\n");
	// printf("MAIN:A->min = %d\n",stack_A->min);
	// print_stack(stack_A);
	if (stack_A->size == 2)
		swap_sort(stack_A);
	else if (stack_A->size == 3)
		triple_sort(stack_A);
	else if (stack_A->size == 4)
		forth_sort(stack_A, stack_B);
	else if (stack_A->size == 5)
		five_sort(stack_A, stack_B);
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
	return (0);
}
