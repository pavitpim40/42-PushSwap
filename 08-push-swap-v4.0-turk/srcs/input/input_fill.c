/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:45:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 16:58:52 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"




// return  0 : not valid
// return 1 : valid
Stack *fill_stack(int argc, char **argv)
{

	int i;
	int j;
	// int len;
	char **words;
	Stack *stack;


	i = argc - 1; 
	j = 0;
	// len = 0;
	stack = create_stack("a");
	while (i > 0)
	{
		if (ft_strlen(*(argv + i)) == 0)
			return 0;
		// เป็น string แต่อาจจะเป็น stringที่ spilt ได้/ไม่ได้ ก็ได้
		
		words = ft_split(*(argv + i), ' ');
		j = 0;
		while(words[j])
			j++;
		j--;
		while (j >= 0)
		{

			if (!verify_string(stack,words[j]))
			{

			
				free(words[j]);
				free(words);
				free_stack(stack);
				return NULL;
			
			}
			else
		
				push_with_index(stack, ft_atoi(words[j]),-1);
			free(words[j]);
			j--;
		}
		free(words);
		i--;
	}

	return stack;
}