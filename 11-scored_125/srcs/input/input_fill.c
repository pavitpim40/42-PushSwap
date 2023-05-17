/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:45:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/13 16:42:51 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	free_all(t_stack *src, char	**words)
{
	free(words);
	free_stack(src);
}

static int	try_to_fill_arg(t_stack *A, char *each_arg)
{
	char	**words;
	int		j;

	words = ft_split(each_arg, ' ');
	j = 0;
	while (words[j])
		j++;
	j--;
	while (j >= 0)
	{
		if (!verify_string(A, words[j]))
		{
			while (j)
				free(words[j--]);
			free(words[0]);
			free_all(A, words);
			return (0);
		}
		else
			push_with_rank(A, ft_atoi(words[j]), -1);
		free(words[j]);
		j--;
	}
	free(words);
	return (1);
}

t_stack	*fill_stack(int argc, char **argv)
{
	int		success_fill;
	t_stack	*a;

	a = create_stack("a");
	success_fill = 0;
	while (argc > 1)
	{
		if (ft_strlen(argv[argc - 1]) == 0)
			return (NULL);
		success_fill = try_to_fill_arg(a, argv[argc - 1]);
		if (!success_fill)
			return (NULL);
		argc--;
	}
	return (a);
}
