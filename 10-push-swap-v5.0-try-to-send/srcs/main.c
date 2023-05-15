/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/15 17:08:01 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_and_exit(char *word, t_stack *A, t_stack *B)
{
	if (A)
		free_stack(A);
	if (B)
		free_stack(B);
	write(2, word, ft_strlen(word));
	exit(1);
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		swap_sort(a);
	else if (a->size == 3)
		triple_sort(a);
	else if (a->size == 4)
		forth_sort(a, b);
	else if (a->size == 5)
		five_sort(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = fill_stack(argc, argv);
	b = create_stack("b");
	if (!a)
		error_and_exit("Error\n", a, b);
	if (a->size == 0 || is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	label_rank(a);
	if (a->size <= 5)
		small_sort(a, b);
	else 
		turk_sort(a, b);
	// else
	// 	chunk_sort(a, b);
	// print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
