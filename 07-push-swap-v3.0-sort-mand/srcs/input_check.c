/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:45:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/08 22:22:26 by ppimchan         ###   ########.fr       */
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


// ######################################
// ####################### Each String ARGS ( 1 or multiple)
// ######################################


int not_digit_or_sign(char *word)
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
		if (ft_is_sign(*(word + i)) && found_num == 0)
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

// ######################################
// ####################### Each A String (only one string)
// ######################################

int overflow(char *string)
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


// ######################################
// ######################## ALL ARGUMENT
// ######################################

// return  0 : not valid
// return 1 : valid
Stack *input_check(int argc, char **argv)
{

	int i;
	int j;
	// int len;
	char **words;
	Stack *stack;
	// char *word;

	i = argc - 1; // as a index
	j = 0;
	// len = 0;
	stack = create_stack("a");
	while (i > 0)
	{
		// printf("i is %d\n",i);
		// printf("argv is %s\n",*(argv+i));
		// check ว่าเป็น empty string รึเปล่า
		if (ft_strlen(*(argv + i)) == 0)
			return 0;
		// เป็น string แต่อาจจะเป็น stringที่ spilt ได้/ไม่ได้ ก็ได้
		
		words = ft_split(*(argv + i), ' ');
		
		j = 0;
		while(words[j])
			j++;
		// printf("j is %d\n",j);
		j--;
		// printf("j is %d\n",j);
		// printf("len is %d\n",len);

		while (j >= 0)
		{
			// printf("word %s and len is %zu\n", words[j],ft_strlen(words[j]));
			// ในแต่ละ word ต้องเช็คอะไรบ้าง
			// sign หรือ เลขเท่าน้น
			
			// printf("word is %s\n", words[j]);
			if (not_digit_or_sign(words[j]))
			{

				// printf("not valid %s\n", words[j]);
				free(words[j]);
				free(words);
				free_stack(stack);
				return NULL;
				// continue;
			}
			// ไม่ overflow
			if (overflow(words[j]))
			{
				// printf("overflow %s\n", words[j]);
				free(words[j]);
				free(words);
				free_stack(stack);
				return NULL;
			}
			// dup_in_stack
			if (check_dup(stack, ft_atoi(words[j])))
			{
				// printf("dup with %d\n", ft_atoi(words[j]));
				free(words[j]);
				free(words);
				free_stack(stack);
				return NULL;
			}
			else
			{
				// printf("push with %d\n", ft_atoi(words[j]));
				push(stack, ft_atoi(words[j]));
			}
			free(words[j]);
			j--;
		}
		free(words);
		i--;
	}

	return stack;
}