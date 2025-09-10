/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:39:05 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 15:39:26 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_consecutive(int a, int b, int c, int d)
{
	int	temp;

	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	return ((b - a == 1) && (c - b == 1) && (d - c == 1));
}

bool	a_partly_sort(t_ps *data, int from)
{
	t_stack	*a;
	int		i;
	int		value;

	a = &data->a;
	i = a->top;
	while (--from)
		i = ft_next_down(a, i);
	while (a->rank[i] != data->a.size)
	{
		value = a->rank[i];
		i = ft_next_down(a, i);
		if (a->rank[i] != value + 1)
			return (false);
	}
	return (true);
}

void	ft_split_max_reduction(t_ps *data, t_chunk *max)
{
	t_stack	*a;

	a = &data->a;
	if (max->loc == A_top && max->size == 3
		&& is_consecutive(ft_get_value(a, 1), ft_get_value(a, 2),
			ft_get_value(a, 3), ft_get_value(a, 4)) && a_partly_sort(data, 4))
	{
		ft_sort_three(data, max);
		return ;
	}
	if (max->loc == A_top && ft_get_value(a, 1) == ft_get_value(a, 3) - 1
		&& a_partly_sort(data, 3))
	{
		swap_a(data);
		max->size--;
	}
	if (max->loc == A_top && a_partly_sort(data, 1))
		max->size--;
}

int	ft_get_chunk_value(t_ps *data, t_chunk *chunk, int n)
{
	t_loc	loc;
	t_stack	*s;
	int		i;

	loc = chunk->loc;
	if (chunk->loc == A_top || (chunk->loc == A_bottom))
		s = &data->a;
	else
		s = &data->b;
	if (loc == A_top || loc == B_top)
		i = s->top;
	else if (loc == A_bottom || loc == B_bottom)
		i = s->bottom;
	if (loc == A_top || loc == B_top)
		while (--n > 0)
			i = ft_next_down(s, i);
	else if (loc == A_bottom || loc == B_bottom)
		while (--n > 0)
			i = ft_next_up(s, i);
	return (s->rank[i]);
}

int	ft_get_max_value(t_ps *data, t_chunk *chunk)
{
	t_stack	*s;
	int		size;
	int		max_value;
	int		i;

	if (chunk->loc == A_top || (chunk->loc == A_bottom))
		s = &data->a;
	else
		s = &data->b;
	size = chunk->size;
	max_value = 0;
	if (chunk->loc == A_top || chunk->loc == B_top)
		i = s->top;
	else if (chunk->loc == A_bottom || chunk->loc == B_bottom)
		i = s->bottom;
	while (size-- > 0)
	{
		if (s->rank[i] > max_value)
			max_value = s->rank[i];
		if (chunk->loc == A_top || chunk->loc == B_top)
			i = ft_next_down(s, i);
		else if (chunk->loc == A_bottom || chunk->loc == B_bottom)
			i = ft_next_up(s, i);
	}
	return (max_value);
}
