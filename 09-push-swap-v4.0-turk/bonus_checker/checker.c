/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:56:39 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 13:50:39 by ppimchan         ###   ########.fr       */
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

void execute_action(Stack *A, Stack *B, char *action)
{
	printf("ACTION CMP = %d\n", ft_strncmp(action, "sa\n", 4));
	if (ft_strncmp(action, "sa\n", 4) == 0)
		s_swap_top(A);
	else if (ft_strncmp(action, "sb\n", 4) == 0)
		s_swap_top(B);
	else if (ft_strncmp(action, "ss\n", 4) == 0)
	{
		s_swap_top(A);
		s_swap_top(B);
	}
	else if (ft_strncmp(action, "pa\n", 4) == 0)
		p_move_top(B, A);
	else if (ft_strncmp(action, "pb\n", 4) == 0)
		p_move_top(A, B);
	else if (ft_strncmp(action, "ra\n", 4) == 0)
		r_shift_up(A, NULL);
	else if (ft_strncmp(action, "rb\n", 4) == 0)
		r_shift_up(B, NULL);
	else if (ft_strncmp(action, "rr\n", 4) == 0)
		r_shift_up(A, B);
	else if (ft_strncmp(action, "rra\n", 5) == 0)
		rr_shift_down(A, NULL);
	else if (ft_strncmp(action, "rrb\n", 5) == 0)
		rr_shift_down(B, NULL);
	else if (ft_strncmp(action, "rrr\n", 5) == 0)
		rr_shift_down(A, B);
	else
		error_and_exit("Error\n",A,B);
	print_stack(A);
}

void checker(Stack *A, Stack *B)
{
	char *action;

	action = get_next_line(STDIN_FILENO);
	printf("ACTION = %s\n", action);
	while (action && !is_sorted(A))
	{
		execute_action(A, B, action);
		free(action);
		if(is_sorted(A))
			break;
		action = get_next_line(STDIN_FILENO);
		print_stack(A);
	}
	// if(action)
	// 	free(action);
	if (is_sorted(A) && B->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("OK\n", STDOUT_FILENO);
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
	{
		// 	free_stack(stack_A);
		free_stack(stack_B);
		write(2, "Error\n", 5);
		exit(1);
	}
	// PRESORTED
	if (is_sorted(stack_A))
	{
		free_stack(stack_A);
		free_stack(stack_B);
		// printf("SORTED");
		return (0);
	}
	// printf("hello checker");
	label_rank(stack_A);
	checker(stack_A,stack_B);
	
	free_stack(stack_A);
	free_stack(stack_B);
	return (0);
}
