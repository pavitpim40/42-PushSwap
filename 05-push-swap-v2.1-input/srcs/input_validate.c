/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:12:45 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 15:11:04 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int ft_is_sign(char c)
{
	if(c == '-' || c == '+')
		return(1);
	return (0);
}
// static int is_digit_or_space(char *arg)
// {	
// 	// digit or space,not empty string
// 	int	i;
// 	int len;

// 	i = 0;
// 	len = ft_strlen(arg);
// 	// printf("str is %s\n",arg);
// 	// printf("str len is %d\n",len);
// 	if(*(arg+i) == '\0')
// 		return (0);
// 	while(i < len)
// 	{
// 		// printf("i ===================== %d\n",i);
// 		// printf("char %c\n",*(arg+i));
// 		if(*(arg+i) == ' ' || ft_is_sign(*(arg+i)) || ft_isdigit(*(arg+i)))
// 		{
// 			i++;
// 			// printf("i && len %d vs %d\n",i,len);
// 		}
// 		else {
// 			// printf("exit is_digit abnormal");
// 			return(0);
// 		}
// 			// return(0);
// 	}
// 	// printf("exit is_digit normal\n");
// 	return (1); // truthy
// }

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
		} else if(ft_is_sign(*(arg+i)) && must_be_white_space == 0)
		{
			i++;
		} else if (ft_isdigit(*(arg+i))) {
			i++;
			must_be_white_space = 1;
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
	// return  0 : not valid
	// return 1 : valid
	int	i;
	char **current_array_string;
	// char *current_string;

	i = 1;
	printf("ARGC = %d\n", argc);
	while(i < argc)
	{ 
		if(ft_strlen(*(argv+i)) == 0)
			printf("Error with empty string\n");
		if(is_digit_or_space(*(argv+i)) == 0)
			printf("Invalid Num\n");
		current_array_string = ft_split(*(argv+i), ' ');
		while (*current_array_string)
		{
			// printf("curr_arg %s\n",*current_array_string);
			current_array_string++;
		}
		i++;
		// printf("i = %d\n", i);
		
		// dup then join


	}
	return (1);
}