/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:12:45 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 22:43:43 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_nan(char *word)
{
	int	i;

	i = 0;
	if (word[i] == '-' || word[i] == '+')
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
	long	num;
	long	max;
	long	min;

	max = INT_MAX;
	min = INT_MIN;
	if (!word)
		return (1);
	if (ft_strlen(word) > 11)
		return (1);
	num = ft_atol(word);
	if (max < num || num < min)
		return (1);
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
	if (is_nan(word))
		return (0);
	if (is_overflow(word))
		return (0);
	if (is_dup(A, ft_atoi(word)))
		return (0);
	return (1);
}
