/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:22:48 by xin               #+#    #+#             */
/*   Updated: 2025/08/13 13:29:36 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_sort_three(t_stack *a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = a->top->data;
	num2 = a->top->next->data;
	num3 = a->top->next->next->data;
	if (num1 < num2 && num2 < num3)
		return (true);
	if (num1 < num3 && num3 < num2)
		return (ft_rra(a), ft_sa(a), true);
	if (num2 < num1 && num1 < num3)
		return (ft_sa(a), true);
	if (num1 < num2 && num3 < num1)
		return (ft_rra(a), true);
	if (num1 > num3 && num2 < num3)
		return (ft_ra(a), true);
	if (num1 > num2 && num2 > num3)
		return (ft_sa(a), ft_rra(a), true);
	return (false);
}

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

bool	ft_sort_small(t_stack *a, t_stack *b, size_t num_size)
{
	size_t	push_count;

	push_count = num_size - 3;
	while (push_count > 0)
	{
		ft_min_to_top(a, a->size);
		ft_pb(a, b);
		push_count--;
	}
	ft_sort_three(a);
	while (b->size > 0)
		ft_pa(a, b);
	return (true);
}
