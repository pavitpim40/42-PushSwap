/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manipulate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:33:54 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 18:25:17 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// for trim, join, spilt

#include "../includes/push_swap.h"

void input_fill(Stack *stack,char **argv)
{
	int	i;
	char **array_word;

	array_word = NULL;
	i = 1;

	while(*(argv+i)) 
	{
		// printf("%s\n", *argv);
		array_word = ft_split(*argv, ' ');
		int j = 0;
		while(array_word[j] != NULL)
		{
			// push to stack
			// printf("num is %s\n", array_word[j]);
			push(stack, ft_atoi(array_word[j]));
			j++;
			free(array_word[j]);
		}
		i++;
		free(array_word);
	}	
}