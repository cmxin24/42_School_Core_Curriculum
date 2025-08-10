/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:53:29 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 10:28:59 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_reverse_rotate(t_stack *s)
{
	t_node	*befor_last;
	t_node	*last;

	if (!s->top || !s->top->next)
		return (false);
	befor_last = s->top;
	while (befor_last->next->next)
		befor_last = befor_last->next;
	last = befor_last->next;
	befor_last->next = NULL;
	last->next = s->top;
	s->top = last;
	return (true);
}

void	ft_rra(t_stack *a)
{
	if (ft_reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b)
{
	if (ft_reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	if (!a->top || !a->top->next || !b->top || !b->top->next)
		return ;
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
