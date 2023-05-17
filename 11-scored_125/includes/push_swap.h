/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:53:15 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 17:24:07 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_node {
	int				data;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
	int		max;
	int		min;
	int		min_rank;
	int		max_rank;
	char	*name;
}	t_stack;

// LIBFT * 10 FN
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

// GNL
char	*get_next_line(int fd);
int		ft_char_index(const char *s, int c);

// STACK
t_stack	*create_stack(char *name);
void	free_stack(t_stack *stack);
void	push(t_stack *stack, int data);
void	push_with_rank(t_stack *dst, int data, int rank);
int		find_next_min_rank(t_stack *src);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack);

// STACK-ACTION
void	s_swap_top(t_stack *stack, int mode);
void	s_swap_both(t_stack *a, t_stack *b, int mode);
void	p_move_top(t_stack *stack_src, t_stack *stack_dst, int mode);
void	p_move_top_with_rank(t_stack *src, t_stack *dst, int rank, int mode);
void	r_shift_up(t_stack *stack_one, t_stack *stack_two, int mode);
void	rr_shift_down(t_stack *stack_one, t_stack *stack_two, int mode);

// INPUT
t_stack	*fill_stack(int argc, char **argv);
int		verify_string(t_stack *A, char *word);

// RANKING
int		find_min(t_stack *A);
void	label_rank(t_stack *A);

// SORT_UTILS
int		is_sorted(t_stack *stack);
void	rotate_down(t_stack *A, int c_top);
void	rotate_up(t_stack *A, int c_bot);

void	move_num(t_stack *src, t_stack *dst, int num);
void	move_num_in_range(t_stack *src, t_stack *dst, int start, int end);

void	move_first_found(t_stack *src, t_stack *dst, int min, int max);
void	move_first_found_optimize(t_stack *src, t_stack *dst, int min, int max);

// SORT_ALGO
void	swap_sort(t_stack *stack_a);
void	triple_sort(t_stack *stack_a);
void	forth_sort(t_stack *A, t_stack *B);
void	five_sort(t_stack *stack_a, t_stack *stack_b);
void	chunk_sort(t_stack *A, t_stack *B);
void	turk_sort(t_stack *a, t_stack *b);

// Util
int		find_pos_from_top(int find_rank, t_stack *b);
int		find_pos_from_bot(int find_rank, t_stack *b);
int		find_greater_than_pos_from_top(int rank, t_stack *b);
int		find_greater_than_pos_from_bot(int rank, t_stack *b);
int		find_less_than_pos_from_top(int rank, t_stack *b);
int		find_less_than_pos_from_bot(int rank, t_stack *b);
int		cal_rotate_cost_from_top(int move_rank, t_stack *b, int find_greater);
int		cal_rotate_cost_from_bot(int move_rank, t_stack *b, int find_greater);

int		calc_cheapest_case(int c_ta, int c_tb, int c_ba, int c_bb);
int		calc_cheapest_move(int move_case, int *action_array);

void	smart_move_tt(int *action_array, t_stack *src, t_stack *dst, int mode);
void	smart_move_bb(int *action_array, t_stack *src, t_stack *dst);
void	smart_move_crossone(int *action_array, t_stack *src, t_stack *dst);
void	smart_move_crosstwo(int *action_array, t_stack *src, t_stack *dst);
void	smart_move(int *action_array, t_stack *src, t_stack *dst, int move);

int		*calc_action(t_stack *src, t_stack *dst, int cheapest[], int mode);

void	cheapest_move(t_stack *src, t_stack *dst, int mode);
void	internal_sort(t_stack *a);
#endif