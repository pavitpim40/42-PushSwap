/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:12:45 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 16:59:09 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int is_nan(char *word)
{
	int i;
	int found_num;

	i = 0;
	found_num = 0;

	if (*(word + i) == '\0')
		return (0);
	while (i < (int)ft_strlen(word) && *(word + i))
	{
		// printf("i = %d\n",i);
		if (is_sign(*(word + i)) && found_num == 0)
			i++;
		else if (ft_isdigit(*(word + i)))
		{
			i++;
			found_num = 1;
		}
		else
		{
			// printf("exit\n");
			return (1);
		}
	}
	return (0); // truthy
}


static int is_overflow(char *string)
{
	int num = ft_atoi(string);
	char *string_check = ft_itoa(num);
	int i = 0;
	int j = 0;

	
	while (string[i] && string_check[j])
	{
		// printf("in loop with str-check %s\n", string_check);
		if (string[i] == string_check[j])
		{
			i++;
			j++;
			continue;
		}
		else
		{
			// printf("Over flow\n");
			return (1);
		}
	}
	// printf("Not Over flow\n");
	return (0);
}

static int is_dup(Stack *stack, int num)
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

int verify_string(Stack* A,char *word)
{
	if(is_nan(word) || is_overflow(word) || is_dup(A,ft_atoi(word)))
		return 0;
	return 1;
}