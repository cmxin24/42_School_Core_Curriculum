/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:50:03 by xin               #+#    #+#             */
/*   Updated: 2025/08/14 15:15:28 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_push_swap(t_stack *a, t_stack *b, int num_size)
{
	if (num_size == 3)
		return (ft_sort_three(a));
	else if (num_size <= 10)
		return (ft_sort_small(a, b, num_size));
	else if (num_size <= 100)
		return (ft_sort_chunk(a, b, 5));
	else if (num_size <= 300)
		return (ft_sort_chunk(a, b, 9));
	else if (num_size <= 500)
		return (ft_sort_chunk(a, b, 10));
	else
		return (ft_sort_chunk(a, b, 13));
	return (false);
}
