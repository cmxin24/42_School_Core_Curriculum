/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:34:57 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 09:53:07 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_rotate(t_stack *s)
{
	t_node	*first;
	t_node	*last;

	if (!s->top || !s->top->next)
		return (false);
	first = s->top;
	s->top = first->next;
	first->next = NULL;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = first;
	return (true);
}

void	ft_ra(t_stack *a)
{
	if (ft_rotate(a))
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b)
{
	if (ft_rotate(b))
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	if (!a->top || !a->top->next || b->top || !b->top->next)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
