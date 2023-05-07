/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:53:15 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/07 15:39:47 by ppimchan         ###   ########.fr       */
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

// STACK
Stack *create_stack(char *name);
void free_stack(Stack *stack);
void print_stack(Stack* stack);
void push(Stack *stack, int data);
int	pop(Stack* stack);
