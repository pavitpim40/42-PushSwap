/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:53:15 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 17:37:48 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	<unistd.h>
# include	<stdlib.h>
# include	<limits.h>
# include	<stdio.h>

typedef struct node {
	int	data;
	struct node* next;
	struct node* prev;
} Node;

typedef struct {
	Node* top;
	Node* bottom;
	int	size;
	char *name;
} Stack;

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_isdigit(int c);

// STACK
Stack *create_stack(char *name);
void free_stack(Stack *stack);
void print_stack(Stack* stack);
void push(Stack *stack, int data);
int	pop(Stack* stack);

// STACK-ACTION
void s_swap_top(Stack *stack);
void p_move_top(Stack *stack_src,Stack *stack_dst);
void r_shift_up(Stack *stack_one, Stack *stack_two);
void rr_shift_down(Stack *stack_one, Stack *stack_two);

// INPUT_VALIDATE
int is_valid_input(char **argv);
