/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:50:03 by xin               #+#    #+#             */
/*   Updated: 2025/08/13 02:08:20 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_push_swap(t_stack *a, t_stack *b, int num_size)
{
	if (num_size == 3)
		return (ft_sort_three(a));
	else if (num_size == 4)
		return (ft_sort_four(a, b));
	else if (num_size == 5)
		return (ft_sort_five(a, b));
	else if (num_size > 5 && num_size <= 100)
		return (ft_sort_chunk(a, b, 5));
	else if (num_size > 100 && num_size <= 500)
		return (ft_sort_chunk(a, b, 9));
	else
		return (ft_sort_chunk(a, b, 13));
	return (false);
}
