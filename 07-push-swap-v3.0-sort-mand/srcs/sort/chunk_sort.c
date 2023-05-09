/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 04:20:47 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// REFF # 1
// void chunk_sort(Stack *A, Stack *B)
// {
// 	int range = A->max - A->min + 1;
// 	int no_chunk = 3;

// 	int interval = range / no_chunk;
// 	int min_chunk = A->min;
// 	int max_chunk = min_chunk + interval - 1;

// 	printf("range %d\n", range);
// 	printf("range/no_chunk %d\n", range / no_chunk);
// 	printf("min_c %d\n", min_chunk);
// 	printf("max_c %d\n", max_chunk);

// 	int count = 0;

// 	Node *current = A->top;
// 	while (count < interval)
// 	{
// 		// printf("data iterate %d\n", current->data);

// 		if (current->data >= min_chunk && current->data < max_chunk)
// 		{
// 			// printf("hold first = %d with count = %d\n", current->data, count);
// 			while (count--)
// 			{
// 				r_shift_up(A, NULL);
// 			}
// 			p_move_top(A, B);
// 			break;
// 		}
// 		count++;
// 		current = current->prev;
// 	}

// 	print_stack(A);
// 	print_stack(B);
// }

// # OK : BUT ONLY FROM TOP

// void chunk_sort(Stack *A, Stack *B)
// {
// 	int chunk_size;

// 	if(A->size <= 100)
// 		chunk_size = 5;
// 	else
// 		chunk_size = 10;

// 	Node *curr_top = A->top;
// 	// Node *from_bot = A->bottom;
// 	int span = A->size / chunk_size;
// 	int round = 1;
// 	int max_in_round = round * span;
// 	int min_in_round = (round - 1)*span + 1;

// 	printf("min in round %d\n",min_in_round);
// 	printf("max in round %d\n",max_in_round);
// 	int count = 0;
// 	int loop_count = 1;
// 	while(loop_count < A->size)
// 	{
// 		// find num-in-range
// 		// printf("LOOP @ %d\n",loop_count);
// 		if(curr_top->data >= min_in_round && curr_top->data <= max_in_round)
// 		{
// 			while(count > 1) {
// 				printf("current el=%d\n",curr_top->data);
// 				r_shift_up(A,NULL);
// 				count--;
// 			}
// 			p_move_top(A,B);
// 			count=0;
// 			// print_stack(B);
// 		}
// 		else
// 		{

// 			count++;
// 		}
// 		loop_count++;
// 		curr_top = curr_top->prev;
// 	}
// 	// print_stack(B);
// }

// // REF #2
// void chunk_sort(Stack *A, Stack *B)
// {
// 	int chunk_size;

// 	if(A->size <= 100)
// 		chunk_size = 5;
// 	else
// 		chunk_size = 10;

// 	Node *curr_top = A->top;
// 	// Node *from_bot = A->bottom;
// 	int span = A->size / chunk_size;
// 	int round = 1;
// 	int max_in_round = round * span;
// 	int min_in_round = (round - 1)*span + 1;

// 	printf("min in round %d\n",min_in_round);
// 	printf("max in round %d\n",max_in_round);
// 	int count = 0;
// 	int loop_count = 1;
// 	while(loop_count < A->size)
// 	{
// 		// find num-in-range
// 		// printf("LOOP @ %d\n",loop_count);
// 		if(curr_top->data >= min_in_round && curr_top->data <= max_in_round)
// 		{
// 			while(count > 1) {
// 				printf("current el=%d\n",curr_top->data);
// 				r_shift_up(A,NULL);
// 				count--;
// 			}
// 			p_move_top(A,B);
// 			count=0;
// 			// print_stack(B);
// 		}
// 		else
// 		{

// 			count++;
// 		}
// 		loop_count++;
// 		curr_top = curr_top->prev;
// 	}
// 	// print_stack(B);
// }

void chunk_sort(Stack *A, Stack *B)
{
	Node *f_top = A->top;
	Node *f_bot = A->bottom;
	int c_top = 0;
	int c_bot = 0;
	// Node *f_bot = A->bottom;
	int fake_count = 20;
	// #1 ทำจน A หมด
	int mid = 5; // control ว่าหากี่ตัว
	while (fake_count)
	{	
		// printf("a\n");
		// #2 ทำทีละ chunk;
		
		int current_size = A->size;
		while (mid)
		{
			// printf("NEW ROUND , mid = %d\n",mid);
			// #3.1 ดูว่าไล่กี่ตัววถึงจะเจอใน range
			while ((f_top->data < 1 || f_top->data > 20) && c_top <= A->size/2)
			{
				c_top++;
				f_top = f_top->prev;
			}
			while((f_bot->data < 1 || f_bot->data > 20) && c_bot<= A->size/2)
			{	
				c_bot++;
				f_bot = f_bot->next;
			}
			printf("-------------ROUND : %d -------------\n", 6-mid);
			print_stack(A);
			printf("c_top=%d\n",c_top);
			printf("c_bot=%d\n",c_bot);
			printf("curren_size=%d\n",current_size);
			if (c_top - 1 <=  c_bot )
			{
				while (c_top--)
					r_shift_up(A, NULL);
				printf("PUSH EL from TOP = %d\n", f_top->data);
				p_move_top(A, B);
				
			}
			else
			{
				while (c_bot--)
					rr_shift_down(A, NULL);
				rr_shift_down(A, NULL);
				printf("PUSH EL from BOT = %d\n", f_bot->data);
				p_move_top(A, B);
				
			}
		
			f_top = A->top;
			
			f_bot = A->bottom;
			// #3.2 หมุนลงล่างตาม c_top
			c_top = 0;
			c_bot = 0;
			mid--;
			printf("BEF NEW ROUND , mid = %d\n",mid);
		}
		fake_count--;
	}
	
}
