/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:08:05 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 03:39:25 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void find_rank(Stack *src, int num)
{
	Node *top;
	Node *bot;
	int c_top;
	int c_bot;

	top = src->top;
	bot = src->bottom;
	c_top = 0;
	c_bot = 0;
	while (top->rank != num && c_top++ <= src->size / 2)
		top = top->prev;
	while (bot->rank != num && c_bot++ <= src->size / 2)
		bot = bot->next;
	if (c_top - 1 <= c_bot)
		rotate_down(src, c_top);
	else
		rotate_up(src, c_top);
}

void find_cheapest_rotate(Stack *B, int target_rank)
{
	// if target_rank new min
	//  - ทำไงก็ได้ให้ max_rank อยู่บนสุด
	//  หา max_rank ว่าอยู่คร่ึงบนหรือครึ่งล่าง
	if (target_rank < B->min)
	{
		printf("new rank %d\n", target_rank);
		printf("stack B\n");
		print_stack(B);
		find_rank(B, B->max_rank);
	}

	// else if(target_rank > B->max)
}