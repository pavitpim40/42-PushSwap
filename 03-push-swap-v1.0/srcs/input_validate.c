/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:12:45 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 17:52:46 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int ft_is_sign(char c)
{
	if(c == '-' || c == '+')
		return(1);
	return (0);
}
static int is_digit_or_space(char *arg)
{	
	// digit or space,not empty string
	int	i;

	i = 0;
	// printf("str is %s\n",arg);
	if(*(arg+i) == '\0')
		return (0);
	while(*(arg+i))
	{
		// printf("char %c\n",*(arg+i));
		if(*(arg+i) == ' ' || ft_is_sign(*(arg+i)) || ft_isdigit(*(arg+i)))
			i++;
		else 
			return(0);
	}
	return (1); // truthy
}

int is_valid_input(char **argv)
{
	int	i;

	i = 1;
	while(*(argv+i) != NULL)
	{ 
		if(!is_digit_or_space(*(argv+i))) // error
		{
			write(2, "Error\n",6);
			return (0);	
		}
		i++;
	}
	return (1);
}