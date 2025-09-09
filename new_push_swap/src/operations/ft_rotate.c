/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:32:14 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 17:42:23 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	rotate(t_stack *s)
{
	if (s->size == ft_current_size(s))
	{
		s->bottom = s->top;
		s->top = ft_next_down(s, s->top);
	}
	else
	{
		s->bottom = ft_next_down(s, s->bottom);
		s->rank[s->bottom] = s->rank[s->top];
		s->rank[s->top] = 0;
		s->top = ft_next_down(s, s->top);
	}
}

void	rotate_a(t_ps *data)
{
	rotate(&data->a);
	if (data->mandatory_part)
		ft_save_operation(data, ra);
}

void	rotate_b(t_ps *data)
{
	rotate(&data->b);
	if (data->mandatory_part)
		ft_save_operation(data, rb);
}

void	rotate_ab(t_ps *data)
{
	rotate(&data->a);
	rotate(&data->b);
	if (data->mandatory_part)
		ft_save_operation(data, rr);
}
