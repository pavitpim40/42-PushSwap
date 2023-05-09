/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:14:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/10 00:05:49 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"



void chunk_sort(Stack *A, Stack *B)
{
	int range = A->max - A->min + 1;
	int no_chunk = 3;

	int interval = range/no_chunk;
	int min_chunk = A->min;
	int max_chunk = min_chunk + interval - 1;

	printf("range %d\n",range);
	printf("range/no_chunk %d\n",range/no_chunk);
	printf("min_c %d\n",min_chunk);
	printf("max_c %d\n",max_chunk);

	int count = 0;


	Node *current = A->top;
	while(count < interval)
	{
		printf("data iterate %d\n",current->data);
		
		if(current->data >= min_chunk && current->data < max_chunk)
		{
			printf("hold first = %d with count = %d\n", current->data,count);
			while (count--)
			{
				r_shift_up(A,NULL);
			}
			p_move_top(A,B);
			break;
		}
		count++;
		current = current->prev;
	}


	print_stack(A);
	print_stack(B);
}


void label_rank(Stack *A)
{
	// find min => label index = 0;
	int rank = 1;
	int min = A->min;
	int new_min = A->min;
	Node *current = A->top;
	while(current)
	{
		printf("current data %d\n", current->data);
		printf("min = %d\n",min);
		// if(current->data == A->max)
		// {
		// 		current->index = A->size;
		// 		break;
		// }
		
		if(current->data == min)
		{
			printf("FOUND MIN\n");
			current->index = rank;
			rank++;
			printf("NEXT RANK %d\n", rank);
			current = A->top;
			new_min = INT_MAX;
			while(current)
			{
				// เลขที่ต้องการคือเลขที่น้อยลงเรื่อยๆ แต่ไม่น้อยกว่า min ตัวก่อน
				if(current->data < new_min && current->data != min)
					new_min = current->data;
				current=current->prev;
			}
			
			min = new_min;
			printf("NEW MIN %d\n", min);
			current = A->top;
		} 
		if (rank == A->size && current->data == A->max)
		{
			current->index = rank;
			break;
		}
		current = current->prev; 
	}
}