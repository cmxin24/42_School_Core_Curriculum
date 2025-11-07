/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_and_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:50:13 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 18:01:47 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_two(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == A_bottom || to_sort->loc == B_bottom
		|| to_sort->loc == B_top)
	{
		ft_move(data, to_sort->loc, A_top);
		ft_move(data, to_sort->loc, A_top);
	}
	if (ft_get_rank(&data->a, 1) > ft_get_rank(&data->a, 2))
		swap_a(data);
	to_sort->size -= 2;
}

void	ft_sort_one(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == A_bottom || to_sort->loc == B_bottom
		|| to_sort->loc == B_top)
		ft_move(data, to_sort->loc, A_top);
	to_sort->size -= 1;
}
