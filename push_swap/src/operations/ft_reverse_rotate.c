/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:35:07 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 17:42:11 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	r_rotate(t_stack *s)
{
	if (s->size == ft_current_size(s))
	{
		s->top = s->bottom;
		s->bottom = ft_next_up(s, s->bottom);
	}
	else
	{
		s->top = ft_next_up(s, s->top);
		s->rank[s->top] = s->rank[s->bottom];
		s->rank[s->bottom] = 0;
		s->bottom = ft_next_up(s, s->bottom);
	}
}

void	r_rotate_a(t_ps *data)
{
	r_rotate(&data->a);
	if (data->mandatory_part)
		ft_save_operation(data, rra);
}

void	r_rotate_b(t_ps *data)
{
	r_rotate(&data->b);
	if (data->mandatory_part)
		ft_save_operation(data, rrb);
}

void	r_rotate_ab(t_ps *data)
{
	r_rotate(&data->a);
	r_rotate(&data->b);
	if (data->mandatory_part)
		ft_save_operation(data, rrr);
}
