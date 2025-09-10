/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:41:16 by xin               #+#    #+#             */
/*   Updated: 2025/09/08 17:32:07 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_from_a_top(t_ps *data, t_loc to)
{
	if (to == B_top)
		push_b(data);
	else if (to == A_bottom)
		rotate_a(data);
	else if (to == B_bottom)
	{
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_b_top(t_ps *data, t_loc to)
{
	if (to == A_top)
		push_a(data);
	else if (to == B_bottom)
		rotate_b(data);
	else if (to == A_bottom)
	{
		push_a(data);
		rotate_a(data);
	}
}

void	move_from_a_bottom(t_ps *data, t_loc to)
{
	if (to == A_top)
		r_rotate_a(data);
	else if (to == B_top)
	{
		r_rotate_a(data);
		push_b(data);
	}
	else if (to == B_bottom)
	{
		r_rotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_b_bottom(t_ps *data, t_loc to)
{
	if (to == B_top)
		r_rotate_b(data);
	else if (to == A_top)
	{
		r_rotate_b(data);
		push_a(data);
	}
	else if (to == A_bottom)
	{
		r_rotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}

int	ft_move(t_ps *data, t_loc from, t_loc to)
{
	if (from == A_top)
		move_from_a_top(data, to);
	else if (from == B_top)
		move_from_b_top(data, to);
	else if (from == A_bottom)
		move_from_a_bottom(data, to);
	else if (from == B_bottom)
		move_from_b_bottom(data, to);
	return (1);
}
