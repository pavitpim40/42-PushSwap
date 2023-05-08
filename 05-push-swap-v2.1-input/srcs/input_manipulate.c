/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manipulate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:33:54 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 15:24:04 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// for trim, join, spilt

#include "../includes/push_swap.h"

void input_fill(Stack *stack,int argc, char **argv)
{
	int	i;
	int j;
	int len;
	char **array_word;

	array_word = NULL;
	i = argc - 1;
	len = 0;
	j = 0;
	while(*(argv+i) && i > 0) 
	{
		// printf("curr_argv = %s\n", *(argv+i));
		array_word = ft_split(*(argv+i), ' ');
		while(array_word[j++])
			len++;
		// printf("curr_len = %d\n", len);
		j = 0;
		while(j < len && array_word[len - 1 - j] != NULL)
		{
			// push to stack
			// printf("num is %s\n", array_word[j]);
			push(stack, ft_atoi(array_word[j]));
			j++;
			printf("j = %d\n", j);
			free(array_word[j]);
		}
		i--;
		free(array_word);
	}	
}