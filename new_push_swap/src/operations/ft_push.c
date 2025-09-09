/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:34:03 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 17:42:00 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	push(t_stack *s, t_stack *d)
{
	int	d_i;

	if (d->size == ft_current_size(d))
		return ;
	d_i = ft_next_up(d, d->top);
	d->rank[d_i] = s->rank[s->top];
	d->top = d_i;
	s->rank[s->top] = 0;
	s->top = ft_next_down(s, s->top);
}

void	push_a(t_ps *data)
{
	push(&data->b, &data->a);
	if (data->mandatory_part)
		ft_save_operation(data, pa);
}

void	push_b(t_ps *data)
{
	push(&data->a, &data->b);
	if (data->mandatory_part)
		ft_save_operation(data, pb);
}
