/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:07:01 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 12:28:07 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_array_to_stack(t_stack *s, int *num_array, size_t num_size)
{
	s->top = NULL;
	while (num_size > 0)
	{
		num_size --;
		ft_push(s, num_array[num_size]);
	}
}
