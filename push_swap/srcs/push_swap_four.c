/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:22:48 by xin               #+#    #+#             */
/*   Updated: 2025/08/12 19:38:22 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	ft_find_max(t_stack *a)
{
	t_node	*current;
	int		max;
	int		index;
	int		max_index;

	current = a->top;
	max = current->data;
	index = 0;
	max_index = 0;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

void	ft_min_to_top(t_stack *a, size_t num_size)
{
	size_t	min_index;
	int		pos;

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

void	ft_max_to_top(t_stack *a, size_t num_size)
{
	size_t	max_index;
	int		pos;

	max_index = ft_find_max(a);
	if (max_index <= (num_size / 2))
	{
		while (max_index-- > 0)
			ft_ra(a);
	}
	else
	{
		pos = num_size - max_index;
		while (pos-- > 0)
			ft_rra(a);
	}
}

bool	ft_sort_four(t_stack *a, t_stack *b)
{
	ft_min_to_top(a, 4);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
	return (true);
}

bool	ft_sort_five(t_stack *a, t_stack *b)
{
	ft_min_to_top(a, 5);
	ft_pb(a, b);
	ft_sort_four(a, b);
	ft_pa(a, b);
	return (true);
}
