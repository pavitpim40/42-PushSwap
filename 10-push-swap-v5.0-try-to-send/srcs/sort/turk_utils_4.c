/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:55:53 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/16 17:12:14 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// START - SMART_MOVE
void	smart_move_tt(int *action_array, t_stack *src, t_stack *dst, int mode)
{
	int	src_top;
	int	dst_top;
	int	common_count;
	int	gap_count;

	src_top = action_array[3];
	dst_top = action_array[4];
	if (src_top >= dst_top)
		common_count = dst_top;
	else
		common_count = src_top;
	gap_count = src_top - dst_top;
	if (gap_count < 0)
		gap_count = -1 * gap_count;
	while (common_count && common_count--)
		r_shift_up(src, dst, 1);
	while (gap_count && gap_count--)
	{
		if (src_top >= dst_top || mode == 1)
			r_shift_up(src, NULL, 1);
		else
			r_shift_up(dst, NULL, 1);
	}
}

void	smart_move_bb(int *action_array, t_stack *src, t_stack *dst)
{
	int	src_bot;
	int	dst_bot;
	int	common_count;
	int	gap_count;

	src_bot = action_array[5];
	dst_bot = action_array[6];
	if (src_bot >= dst_bot)
		common_count = dst_bot;
	else
		common_count = src_bot;
	gap_count = dst_bot - src_bot;
	if (gap_count < 0)
		gap_count = -1 * gap_count;
	while (common_count && common_count--)
		rr_shift_down(src, dst, 1);
	if (src_bot >= dst_bot)
		while (gap_count && gap_count--)
			rr_shift_down(src, NULL, 1);
	else
		while (gap_count && gap_count--)
			rr_shift_down(dst, NULL, 1);
}

void	smart_move_crossone(int *action_array, t_stack *src, t_stack *dst)
{
	int	src_top;
	int	dst_bot;

	src_top = action_array[3];
	dst_bot = action_array[6];
	while (src_top--)
		r_shift_up(src, NULL, 1);
	while (dst_bot--)
		rr_shift_down(dst, NULL, 1);
}

void	smart_move_crosstwo(int *action_array, t_stack *src, t_stack *dst)
{
	int	dst_top;
	int	src_bot;

	dst_top = action_array[4];
	src_bot = action_array[5];
	while (src_bot--)
		rr_shift_down(src, NULL, 1);
	while (dst_top--)
		r_shift_up(dst, NULL, 1);
}

void	smart_move(int *action_array, t_stack *src, t_stack *dst, int move_back)
{
	int	action_case;

	action_case = action_array[2];
	if (action_case == 1)
		smart_move_tt(action_array, src, dst, move_back);
	if (action_case == 2 && move_back == 0)
		smart_move_bb(action_array, src, dst);
	if (action_case == 2 && move_back == 1)
		smart_move_bb(action_array, dst, src);
	if (action_case == 3 && move_back == 0)
		smart_move_crossone(action_array, src, dst);
	if (action_case == 3 && move_back == 1)
		smart_move_crossone(action_array, dst, src);
	if (action_case == 4 && move_back == 0)
		smart_move_crosstwo(action_array, src, dst);
	if (action_case == 4 && move_back == 1)
		smart_move_crosstwo(action_array, dst, src);
	if (move_back == 0)
		p_move_top(src, dst, 1);
	else if (move_back == 1)
		p_move_top(dst, src, 1);
}
