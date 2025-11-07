/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:31:59 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 18:17:04 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_three_top_a(t_ps *data, t_chunk *to_sort, t_stack *s, int max)
{
	if (s->rank[s->top] == max)
	{
		swap_a(data);
		rotate_a(data);
		swap_a(data);
		r_rotate_a(data);
	}
	else if (s->rank[(s->top + 1) % s->size] == max)
	{
		rotate_a(data);
		swap_a(data);
		r_rotate_a(data);
	}
	to_sort->loc = A_top;
	to_sort->size -= 1;
	ft_sort_two(data, to_sort);
}

void	ft_sort_three_top_b(t_ps *data, t_chunk *to_sort, t_stack *s, int max)
{
	push_a(data);
	if (s->rank[s->top] == max)
	{
		push_a(data);
		swap_a(data);
	}
	else if (s->rank[(s->top + 1) % s->size] == max)
	{
		swap_b(data);
		push_a(data);
		swap_a(data);
	}
	else
		push_a(data);
	push_a(data);
	to_sort->loc = A_top;
	to_sort->size -= 1;
	ft_sort_two(data, to_sort);
}

void	ft_sort_three_bott_a(t_ps *data, t_chunk *to_sort, t_stack *s, int max)
{
	r_rotate_a(data);
	r_rotate_a(data);
	if (s->rank[s->top] == max)
	{
		swap_a(data);
		r_rotate_a(data);
	}
	else if (s->rank[(s->top + 1) % s->size] == max)
		r_rotate_a(data);
	else
	{
		push_b(data);
		r_rotate_a(data);
		swap_a(data);
		push_a(data);
	}
	to_sort->loc = A_top;
	to_sort->size -= 1;
	ft_sort_two(data, to_sort);
}

void	ft_sort_three_bott_b(t_ps *data, t_chunk *to_sort, t_stack *s, int max)
{
	r_rotate_b(data);
	r_rotate_b(data);
	if (s->rank[s->top] == max)
	{
		push_a(data);
		r_rotate_b(data);
	}
	else if (s->rank[(s->top + 1) % s->size] == max)
	{
		swap_b(data);
		push_a(data);
		r_rotate_b(data);
	}
	else
	{
		r_rotate_b(data);
		push_a(data);
	}
	to_sort->loc = B_top;
	to_sort->size -= 1;
	ft_sort_two(data, to_sort);
}

void	ft_sort_three(t_ps *data, t_chunk *to_sort)
{
	t_stack	*s;
	int		max;

	if (to_sort->loc == A_top || (to_sort->loc == A_bottom))
		s = &data->a;
	else
		s = &data->b;
	max = ft_get_max_rank(data, to_sort);
	if (to_sort->loc == A_top)
		ft_sort_three_top_a(data, to_sort, s, max);
	else if (to_sort->loc == A_bottom)
		ft_sort_three_bott_a(data, to_sort, s, max);
	else if (to_sort->loc == B_top)
		ft_sort_three_top_b(data, to_sort, s, max);
	else if (to_sort->loc == B_bottom)
		ft_sort_three_bott_b(data, to_sort, s, max);
}
