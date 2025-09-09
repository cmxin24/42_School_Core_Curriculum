/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:11:42 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 15:31:52 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	handle_top_b(t_ps *data, t_chunk *to_sort)
{
	swap_b(data);
	push_a(data);
	if (ft_get_value(&data->b, 1) == ft_get_value(&data->a, 1) - 1)
	{
		push_a(data);
		to_sort->size--;
	}
}

void	handle_bottom_a(t_ps *data, t_chunk *to_sort)
{
	r_rotate_a(data);
	r_rotate_a(data);
	swap_a(data);
	if (ft_get_value(&data->a, 1) == ft_get_value(&data->a, 2) - 1)
		to_sort->size--;
	else
		rotate_a(data);
}

void	handle_bottom_b(t_ps *data, t_chunk *to_sort)
{
	r_rotate_b(data);
	r_rotate_b(data);
	push_a(data);
	if (ft_get_value(&data->b, 1) == ft_get_value(&data->a, 1) - 1)
	{
		push_a(data);
		to_sort->size--;
	}
	else
		rotate_b(data);
}

void	ft_easy_sort(t_ps *data, t_chunk *to_sort)
{
	while (to_sort->loc != A_top && to_sort->size)
	{
		if (ft_get_value(&data->a, 1) == ft_get_chunk_value(data, to_sort, 1)
			+ 1 && to_sort->size > 0)
			ft_sort_one(data, to_sort);
		else if (ft_get_value(&data->a, 1) == ft_get_chunk_value(data, to_sort,
				2) + 1 && to_sort->size > 1)
		{
			if (to_sort->loc == B_top)
				handle_top_b(data, to_sort);
			else if (to_sort->loc == A_bottom)
				handle_bottom_a(data, to_sort);
			else if (to_sort->loc == B_bottom)
				handle_bottom_b(data, to_sort);
			to_sort->size--;
		}
		else
			break ;
	}
}
