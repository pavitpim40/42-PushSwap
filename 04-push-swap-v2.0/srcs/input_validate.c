/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:12:45 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 13:10:40 by ppimchan         ###   ########.fr       */
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
	int len;

	i = 0;
	len = ft_strlen(arg);
	// printf("str is %s\n",arg);
	// printf("str len is %d\n",len);
	if(*(arg+i) == '\0')
		return (0);
	while(i < len)
	{
		// printf("i ===================== %d\n",i);
		// printf("char %c\n",*(arg+i));
		if(*(arg+i) == ' ' || ft_is_sign(*(arg+i)) || ft_isdigit(*(arg+i)))
		{
			i++;
			// printf("i && len %d vs %d\n",i,len);
		}
		else {
			// printf("exit is_digit abnormal");
			return(0);
		}
			// return(0);
	}
	// printf("exit is_digit normal\n");
	return (1); // truthy
}

int is_valid_input(int argc, char **argv)
{
	int	i;

	i = 1;
	// printf("ARGC=====i = %d\n" ,  i);
	while(i < argc)
	{ 
		// printf("BEF=====i = %d\n" ,  i);
		// printf("argv = %s\n" , *(argv + i));
		
		int r = !is_digit_or_space(*(argv+i));
		// printf("result : %d\n",r);
		if(r) // error
		{
			write(2, "Error\n",6);
			return (0);	
		}
		i++;
		// printf("AFTER====i = %d\n" ,  i);
	}
	return (1);
}