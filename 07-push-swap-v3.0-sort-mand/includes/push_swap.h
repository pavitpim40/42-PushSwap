/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:53:15 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/09 23:46:09 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	<unistd.h>
# include	<stdlib.h>
# include	<limits.h>
# include	<stdio.h>

typedef struct node {
	int	data;
	int index;
	struct node* next;
	struct node* prev;
} Node;

typedef struct {
	Node* top;
	Node* bottom;
	int	size;
	int	max;
	int min;
	char *name;
} Stack;

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

// STACK
Stack *create_stack(char *name);
void free_stack(Stack *stack);
void print_stack(Stack* stack);
void push(Stack *stack, int data);
void push_with_index(Stack *stack, int data);
int	pop(Stack* stack);

// STACK-ACTION
void s_swap_top(Stack *stack);
void p_move_top(Stack *stack_src,Stack *stack_dst);
void r_shift_up(Stack *stack_one, Stack *stack_two);
void rr_shift_down(Stack *stack_one, Stack *stack_two);

// INPUT_VALIDATE
Stack *input_check(int argc, char **argv);
int is_valid_input(int argc, char **argv);
int check_dup_all(int argc, char **argv);
void input_fill(Stack *stack,int argc, char **argv);

// RANKING
void label_rank(Stack *A);

// SORT
void swap_sort(Stack *stack_a);
void triple_sort(Stack *stack_a);
void five_sort(Stack *stack_a,Stack *stack_b);
void bubble_sort(Stack *stack_a, Stack *stack_b);
// void quick_sort(Stack *stack_a,Stack *stack_b);
// void quick_sort(Stack *stack_a,Stack *stack_b, int size);
void chunk_sort(Stack *A, Stack *B);