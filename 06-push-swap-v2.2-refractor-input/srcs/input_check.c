/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:45:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 18:54:24 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ######################################
// ######################## CHECK BY CHAR
// ######################################
int ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

// int is_white_pace(char c)
// {
// 	if (c == ' ')
// 		return (1);
// 	return (0);
// }

// ######################################
// ####################### Each String ARGS ( 1 or multiple)
// ######################################
// int is_digit_or_space(char *arg)
// {
// 	int i;
// 	int len;
// 	int must_be_white_space;

// 	i = 0;
// 	len = ft_strlen(arg);
// 	must_be_white_space = 0;

// 	if (*(arg + i) == '\0')
// 		return (0);
// 	while (i < len)
// 	{
// 		if (is_white_pace(*(arg + i)))
// 		{
// 			i++;
// 			must_be_white_space = 0;
// 		}
// 		else if (ft_is_sign(*(arg + i)) && must_be_white_space == 0)
// 			i++;
// 		else if (ft_isdigit(*(arg + i)))
// 		{
// 			i++;
// 			must_be_white_space = 1;
// 		}
// 		else
// 			return (0);
// 	}
// 	return (1); // truthy
// }

// int is_digit_or_sign(char *word)
// {
// 	int i;
// 	int found_num;

// 	i = 0;
// 	found_num = 0;

// 	if (*(word + i) == '\0')
// 		return (0);
// 	while (*(word+i))
// 	{
// 		if (ft_is_sign(*(word + i)) && found_num == 0)
// 			i++;
// 		else if (ft_isdigit(*(word + i)))
// 		{
// 			i++;
// 			found_num = 1;
// 		}
// 		else
// 			return (-1);
// 	}
// 	return (0); // truthy
// }



int not_digit_or_sign(char *word)
{
	int i;
	int found_num;

	i = 0;
	found_num = 0;

	if (*(word + i) == '\0')
		return (0);
	while (i < (int)ft_strlen(word) && *(word+i))
	{
		// printf("i = %d\n",i);
		if (ft_is_sign(*(word + i)) && found_num == 0)
			i++;
		else if (ft_isdigit(*(word + i)))
		{
			i++;
			found_num = 1;
		}
		else{
			// printf("exit\n");
			return (1);
		}
			
	}
	return (0); // truthy
}

// ######################################
// ####################### Each A String (only one string)
// ######################################
int is_overflow(char *string)
{
	int num = ft_atoi(string);
	char *string_check = ft_itoa(num);
	int i = 0;
	int j = 0;

	// printf("STRING %s\n",string);
	// printf("NUM %d\n",num);
	while(string[i] && string_check[j])
	{
		if(string[i] == string_check[j])
		{
			i++;
			j++;
			continue;
		} else {
			// printf("Over flow\n");
			return (1);
		}
	}
// printf("Not Over flow\n");
	return (0);
}

int overflow(char *string)
{
	int num = ft_atoi(string);
	char *string_check = ft_itoa(num);
	int i = 0;
	int j = 0;

	while(string[i] && string_check[j])
	{
		if(string[i] == string_check[j])
		{
			i++;
			j++;
			continue;
		} else {
			// printf("Over flow\n");
			return (1);
		}
	}
// printf("Not Over flow\n");
	return (0);
}


// ######################################
// ####################### DUP
// ######################################
int check_dup(Stack *stack, int num)
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

int check_dup_all(int argc, char **argv)
{
	int i;
	int j;
	int len;
	char **array_word;
	Stack *stack;

	array_word = NULL;
	i = argc - 1;
	len = 0;
	j = 0;
	stack = create_stack("temp");
	while (*(argv + i) && i > 0)
	{
		array_word = ft_split(*(argv + i), ' ');
		while (array_word[j++])
			len++;
		j = 0;
		while (j < len && array_word[len - 1 - j] != NULL)
		{
			// printf("check loop\n");
			if (is_overflow(array_word[j]) || check_dup(stack, ft_atoi(array_word[j])))
			{
				// printf("DUP in check\n");
				free_stack(stack);
				free(array_word[j]);
				free(array_word);
				return (1);
			}
			else
			{
				printf("PUSH in check\n");
				push(stack, ft_atoi(array_word[j]));
				j++;
				free(array_word[j]);
			}
		}
		i--;
			
		free(array_word);
		// if(stack != NULL)
		// 	free_stack(stack);
	}
	return (0);
}



// ######################################
// ######################## ALL ARGUMENT
// ######################################
// int is_valid_input(int argc, char **argv)
// {
// 	// return  0 : not valid
// 	// return 1 : valid
// 	int i;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (ft_strlen(*(argv + i)) == 0)
// 			return 0;
// 		if (is_digit_or_space(*(argv + i)) == 0)
// 			return 0;
// 		i++;
// 	}
// 	// check dup
// 	i = 1;

// 	return (1);
// }

// return  0 : not valid
// return 1 : valid
int input_check(int argc, char **argv)
{
	
	int i;
	int j;
	char **words;
	Stack *stack;
	// char *word;

	i = 1;
	j = 0;
	stack = create_stack("a");
	while (i < argc)
	{
		// check ว่าเป็น empty string รึเปล่า
		if (ft_strlen(*(argv + i)) == 0)
			return 0;
		// เป็น string แต่อาจจะเป็น stringที่ spilt ได้/ไม่ได้ ก็ได้
		words = ft_split(*(argv+i),' ');
		j = 0;
		while(words[j])
		{
			// printf("word %s and len is %zu\n", words[j],ft_strlen(words[j]));
			// ในแต่ละ word ต้องเช็คอะไรบ้าง 
			// sign หรือ เลขเท่าน้น 
	
			if(not_digit_or_sign(words[j]))
			{
				
				printf("not valid %s\n", words[j]);
				j++;
				continue;
			}
			// ไม่ overflow
			if(overflow(words[j]))
			{
				printf("overflow %s\n", words[j]);
				j++;
				continue;
			}
			// dup_in_stack
			if(check_dup(stack,ft_atoi(words[j])))
			{
				printf("dup with %d\n", ft_atoi(words[j]));
			} 
			else 
			{
				printf("push with %d\n", ft_atoi(words[j]));
				push(stack, ft_atoi(words[j]));
			}

			
			free(words[j]);
			j++;
		}
		// if (is_digit_or_space(*(argv + i)) == 0)
		// 	return 0;
		free(words);
		i++;
	}
	

	return (1);
}