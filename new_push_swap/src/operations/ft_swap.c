/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:09:16 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 17:42:32 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s->rank[ft_next_down(s, s->top)] == 0)
		return ;
	tmp = s->rank[ft_next_down(s, s->top)];
	s->rank[ft_next_down(s, s->top)] = s->rank[s->top];
	s->rank[s->top] = tmp;
}

void	swap_a(t_ps *data)
{
	swap(&data->a);
	if (data->mandatory_part)
		ft_save_operation(data, sa);
}

void	swap_b(t_ps *data)
{
	swap(&data->b);
	if (data->mandatory_part)
		ft_save_operation(data, sb);
}

void	swap_ab(t_ps *data)
{
	swap(&data->a);
	swap(&data->b);
	if (data->mandatory_part)
		ft_save_operation(data, ss);
}
