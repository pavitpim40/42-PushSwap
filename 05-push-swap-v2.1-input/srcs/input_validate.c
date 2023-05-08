/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:12:45 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 15:26:14 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int ft_is_sign(char c)
{
	if(c == '-' || c == '+')
		return(1);
	return (0);
}

static int is_white_pace(char c)
{
	if(c == ' ')
		return (1);
	return (0);
}

static int is_digit_or_space(char *arg)
{	
	int	i;
	int len;
	int must_be_white_space;

	i = 0;
	len = ft_strlen(arg);
	must_be_white_space = 0;

	if(*(arg+i) == '\0')
		return (0);
	while(i < len)
	{
		if(is_white_pace(*(arg+i)))
		{
			i++;
			must_be_white_space =0;
		} 
		else if(ft_is_sign(*(arg+i)) && must_be_white_space == 0)
			i++;
		 else if (ft_isdigit(*(arg+i))) 
		 {
			i++;
			must_be_white_space = 1;
		}
		else 
		return(0);
		

	}
	return (1); // truthy
}


int is_valid_input(int argc, char **argv)
{
	// return  0 : not valid
	// return 1 : valid
	int	i;

	i = 1;
	while(i < argc)
	{ 
		if(ft_strlen(*(argv+i)) == 0)
			return 0;
		if(is_digit_or_space(*(argv+i)) == 0)
			return 0;
	}
	return (1);
}