/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:12:45 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/11 17:11:35 by ppimchan         ###   ########.fr       */
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
		if (is_sign(*(word + i)) && found_num == 0)
			i++;
		else if (ft_isdigit(*(word + i)))
		{
			i++;
			found_num = 1;
		}
		else
			return (1);
	}
	return (0);
}

static int is_overflow(char *word)
{
	int num = ft_atoi(word);
	char *word_check = ft_itoa(num);
	int i = 0;
	int j = 0;

	while (word[i] && word_check[j])
	{
		if (word[i++] == word_check[j++])
			continue;
		else
			return (1);
	}
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

int verify_string(Stack *A, char *word)
{
	if (is_nan(word) || is_overflow(word) || is_dup(A, ft_atoi(word)))
		return 0;
	return 1;
}