/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:51:41 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 17:04:57 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_val(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	ft_chunk_split(t_ps *data, t_chunk *to_split, t_split *des)
{
	int	pivot_1;
	int	pivot_2;
	int	max_value;
	int	next_value;

	init_val(&des->min, &des->mid, &des->max);
	set_split_location(to_split->loc, &des->min, &des->mid, &des->max);
	set_third_piovt(to_split->loc, to_split->size, &pivot_1, &pivot_2);
	max_value = ft_get_max_value(data, to_split);
	while (to_split->size--)
	{
		next_value = ft_get_chunk_value(data, to_split, 1);
		if (next_value > max_value - pivot_2)
		{
			des->max.size += ft_move(data, to_split->loc, des->max.loc);
			ft_split_max_reduction(data, &des->max);
			if (a_partly_sort(data, 1) && to_split->size)
				ft_easy_sort(data, to_split);
		}
		else if (next_value > max_value - pivot_1)
			des->mid.size += ft_move(data, to_split->loc, des->mid.loc);
		else
			des->min.size += ft_move(data, to_split->loc, des->min.loc);
	}
}

void	ft_sort_chunk_recursive(t_ps *data, t_chunk *to_sort)
{
	t_split	des;

	if (to_sort->loc == B_bottom && ft_current_size(&data->b) == to_sort->size)
		to_sort->loc = B_top;
	if (to_sort->loc == A_bottom && ft_current_size(&data->a) == to_sort->size)
		to_sort->loc = A_top;
	ft_easy_sort(data, to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			ft_sort_three(data, to_sort);
		else if (to_sort->size == 2)
			ft_sort_two(data, to_sort);
		else if (to_sort->size == 1)
			ft_sort_one(data, to_sort);
		return ;
	}
	ft_chunk_split(data, to_sort, &des);
	ft_sort_chunk_recursive(data, &des.max);
	ft_sort_chunk_recursive(data, &des.mid);
	ft_sort_chunk_recursive(data, &des.min);
}

void	ft_sort_chunk(t_ps *data)
{
	t_chunk	all;

	all.loc = A_top;
	all.size = data->a.size;
	ft_sort_chunk_recursive(data, &all);
}
