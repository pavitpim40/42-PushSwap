/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manipulate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:33:54 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 17:02:46 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// for trim, join, spilt

#include "../includes/push_swap.h"

int check_dup(Stack *stack, int num)
{
	Node *current;
	current = stack->top;
	while (current != NULL)
	{
		if (current->data == num)
			return (1);
		current = current->prev;
	}
	return (0);
}

int check_dup_all(int argc, char **argv)
{
	int i;
	int j;
	int len;
	char **array_word;
	Stack *stack;

	array_word = NULL;
	i = argc - 1;
	len = 0;
	j = 0;
	stack = create_stack("temp");
	while (*(argv + i) && i > 0)
	{
		array_word = ft_split(*(argv + i), ' ');
		while (array_word[j++])
			len++;
		j = 0;
		while (j < len && array_word[len - 1 - j] != NULL)
		{
			
			if (check_dup(stack, ft_atoi(array_word[j])))
			{
				// printf("FIND BUG %p\n", array_word);
				free_stack(stack);
				free(array_word[j]);
				free(array_word);
				return (1);
			}
			else
			{
				push(stack, ft_atoi(array_word[j]));
				j++;
				free(array_word[j]);
			}
		}
		i--;
		free(array_word);
		// if(stack != NULL)
		// 	free_stack(stack);
	}
	return (0);
}

void input_fill(Stack *stack, int argc, char **argv)
{
	int i;
	int j;
	int len;
	char **array_word;

	array_word = NULL;
	i = argc - 1;
	len = 0;
	j = 0;

	while (*(argv + i) && i > 0)
	{
		array_word = ft_split(*(argv + i), ' ');
		while (array_word[j++])
			len++;
		j = 0;
		while (j < len && array_word[len - 1 - j] != NULL)
		{
			push(stack, ft_atoi(array_word[j]));
			j++;
			free(array_word[j]);
		}
		i--;
		free(array_word);
	}
}