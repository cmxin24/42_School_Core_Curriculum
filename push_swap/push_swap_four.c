/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:22:48 by xin               #+#    #+#             */
/*   Updated: 2025/08/12 13:47:00 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack *a)
{
	t_node	*current;
	int		min;
	int		index;
	int		min_index;

	current = a->top;
	min = current->data;
	index = 0;
	min_index = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	ft_min_to_top(t_stack *a, size_t num_size)
{
	int	min_index;
	int	pos;

	min_index = ft_find_min(a);
	if (min_index <= (num_size / 2))
	{
		while (min_index-- > 0)
			ft_ra(a);
	}
	else
	{
		pos = num_size - min_index;
		while (pos-- > 0)
			ft_rra(a);
	}
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	ft_min_to_top(a, 4);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	ft_min_to_top(a, 5);
	ft_pb(a, b);
	ft_sort_four(a, b);
	ft_pa(a, b);
}
