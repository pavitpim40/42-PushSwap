/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:12:34 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 17:30:23 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int main()
// {
// 	Stack *stack = create_stack("a");
// 	Stack *stack_b = create_stack("b");

//     push(stack, 10);
//     push(stack, 20);
//     push(stack, 30);
//     push(stack, 40);
//     push(stack, 50);

//     print_stack(stack);

// 	// pop(stack);
	
// 	print_stack(stack);
	
// 	// rr_shift_down(stack,NULL);
// 	// p_move_top(stack,stack_b);
// 	// p_move_top(stack,stack_b);
// 	// p_move_top(stack,stack_b); 
// 	print_stack(stack);
// 	// print_stack(stack_b);

// 	// s_swap_top(stack_b);
// 	// action_push_stack(stack_b,stack);
// 	// rr_shift_down(stack,stack_b);
// 	// r_shift_up(stack_b,stack);
// 	// s_swap_top(stack);
// 	// print_stack(stack);
// 	// print_stack(stack_b);

	

// 	printf("TOP %d\n", stack->top->data);
// 	printf("BOT %d\n", stack->bottom->data);
	
// 	free_stack(stack);
// 	free_stack(stack_b);
// }


int is_digit_or_space(char *arg)
{	
	// digit or space,not empty string
	int	i;

	i = 0;
	printf("str is %s\n",arg);
	if(*(arg+i) == '\0')
		return (0);
	while(*(arg+i))
	{
		printf("char %c\n",*(arg+i));
		if(*(arg+i) == ' ' || ft_isdigit(*(arg+i)))
			i++;
		else 
			return(0);
	}
	return (1); // truthy
}

int valid_input(char **argv)
{
	int	i;
	// int r;

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
// FOR INPUT
int main(int argc, char *argv[])
{
	// int i = 0;
	// int r;
	printf("ac = %d\n",argc);
	// i = 1;

	if(!valid_input(argv)) // implicit print Error
		return (1);

}
