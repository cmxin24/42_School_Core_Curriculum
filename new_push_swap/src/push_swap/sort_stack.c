/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:19:42 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 18:54:29 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_three_a(t_ps *data)
{
	int	first;
	int	second;
	int	third;

	first = ft_get_value(&data->a, 1);
	second = ft_get_value(&data->a, 2);
	third = ft_get_value(&data->a, 3);
	if (first > second && third > second && third > first)
		swap_a(data);
	else if (first > second && third > second && first > third)
		rotate_a(data);
	else if (second > first && second > third && first > third)
		r_rotate_a(data);
	else if (second > first && second > third && third > first)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (first > second && second > third && first > third)
	{
		swap_a(data);
		r_rotate_a(data);
	}
}

void	ft_sort_five_a(t_ps *data)
{
	while (ft_current_size(&data->a) > 3)
	{
		if (ft_get_value(&data->a, 1) == 1
			|| ft_get_value(&data->a, 1) == 2)
			push_b(data);
		else
			rotate_a(data);
	}
	if (ft_get_value(&data->b, 1) < ft_get_value(&data->b, 2))
		swap_b(data);
	ft_sort_three_a(data);
	push_a(data);
	push_a(data);
}

void	ft_sort_stack(t_ps *data)
{
	if (data->a.size <= 1 || ft_is_sorted(data))
		return ;
	else if (data->a.size == 3)
		ft_sort_three_a(data);
	else if (data->a.size == 5)
		ft_sort_five_a(data);
	else
		ft_sort_chunk(data);
}
