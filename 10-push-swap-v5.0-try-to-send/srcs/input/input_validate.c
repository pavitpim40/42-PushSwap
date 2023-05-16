/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:12:45 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/13 17:06:02 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	is_nan(char *word)
{
	int	i;

	i = 0;
	if (word[i] == '\0')
		return (0);
	if (is_sign(word[i]))
		i++;
	if (!word[i])
		return (1);
	while (ft_isdigit(word[i]))
		i++;
	if (word[i] != 0)
		return (1);
	return (0);
}

static int	is_overflow(char *word)
{
	int		num;
	char	*word_check;
	int		i;
	int		j;

	num = ft_atoi(word);
	word_check = ft_itoa(num);
	i = 0;
	j = 0;
	while (word[i] && word_check[j])
	{
		if (word[i++] == word_check[j++])
			continue ;
		else
		{
			free(word_check);
			return (1);
		}
	}
	free(word_check);
	return (0);
}

static int	is_dup(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		if (current->data == num)
			return (1);
		current = current->prev;
	}
	return (0);
}

int	verify_string(t_stack *A, char *word)
{
	if (is_nan(word) || is_overflow(word) || is_dup(A, ft_atoi(word)))
		return (0);
	return (1);
}
