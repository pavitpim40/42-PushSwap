/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:43:22 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/14 01:09:26 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Main Problem : Move with Cheapest Instruction
// Sub-PB1 : calc. cost from stack A to Top
// Sub-PB2 : calc. cost to move to stack B (1)
// Sub-PB3 : calc. cost to rotate to right position in Stack B
// Sub-PB4 : find minimum cost
// Sub-PB5 : take that action


// lowest_pos

int		cal_lowest_move(int	c_top, int c_bot)
{
	if(c_top <= c_bot * -1 )
	{
		printf("1\n");
		return (c_top);
	}
	else
	{
		printf("2\n");
		return (c_bot);
	}
}
// เจอตำแหน่งที่ต้องการคือจบ
int		find_pos(int find_rank, t_stack *b)
{
	t_node	*f_top;
	t_node	*f_bot;
	int		c_top;
	int		c_bot;
	// int		founded;
	
	c_top = 0;
	c_bot = -1;
	f_top = b->top;
	f_bot = b->bottom;
	// founded = 0;
	printf("B->max = %d\n", b->max);
	printf("find_rank = %d\n", find_rank);
	while(f_top || f_bot)
	{
		// กรณีที่จะหาตัว max
		if(find_rank == b->max && (f_top->rank == b->max || f_bot->rank == b->max))
			{
					c_top++;
					return cal_lowest_move(c_top,c_bot);
			}
		else if(find_rank == b->max && f_bot->rank == b->max)
		{
			c_bot--;
			return cal_lowest_move(c_top,c_bot);
		}

		else if(find_rank == f_top->rank)
		{
				c_top++;
				return cal_lowest_move(c_top,c_bot);
		}
		else if(f_bot->rank == find_rank)
			{
				c_bot--;
		return cal_lowest_move(c_top,c_bot);
		}
			
		c_top++;
		c_bot--;
		f_top = f_top->prev;
		f_bot = f_bot->next;
	}
		
		return (-1);
}


// หาตำแหน่งที่น้อยกว่า 1 และหาต่อถ้าไม่เจอ (น้อยกว่า 2,3,4)
int		find_less_than_pos(int rank, t_stack *b)
{
		int target_rank = rank - 1;

		while(target_rank > 0)
		{
			int pos = find_pos(target_rank,b);
			printf("target rank = %d , pos = %d\n",target_rank,pos);
			if(pos != -1)
				return (pos);
			target_rank--;
		}
		return (-1);
}


int		cal_rotate_cost(int move_rank, t_stack *b)
{
		int	cost;

		cost = 0;
		if(move_rank < b->min)
			cost = find_pos(b->max, b);
		else if(move_rank > b->max)
		{
			printf("move as a NEW_MAX = %d\n", move_rank);
			cost = find_pos(b->max, b);
			printf("rotate_cost of NEW_MAX = %d\n", cost);
		}
			
		else
		{		
			printf("find rank = %d\n", move_rank);
				cost = find_less_than_pos(move_rank, b);
		}
		
		return (cost);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	// #1 Move to B
	int	size_a;
	t_node	*current;
	
	size_a = a->size;
	p_move_top(a, b, 1);
	p_move_top(a, b, 1);
	current = a->top;
	int index = 0;
	while(size_a && current)
	{
		// ## 1.1 start from top node
		
		// int index = 0;
		printf("============ LOOP %d ==============\n", index+1);
		int rotate_cost = cal_rotate_cost(current->rank, b);
		if(index <= size_a / 2) {
			printf("ftop:node-data = %d , cost = %d , total_cost = %d\n", current->data, rotate_cost,index + 1 + rotate_cost);
		} else {
			printf("fbot:node-data = %d \n", current->data);
			printf("rotate_a_cost = %d\n", a->size-index);
			printf("rotate_b_cost = %d\n",rotate_cost);
			printf("push_cost = 1\n");
			printf("total cost = %d\n",a->size-index + 1 + rotate_cost);
		}
		
		printf("=================================\n");
		
		// update to next node
		current = current->prev;
		index++;
		size_a--;
	}

	// #1.5 Triple sort
	// #2 Move back to A
}