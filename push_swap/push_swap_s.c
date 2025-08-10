/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:17:49 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 10:29:00 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	int		num;

	if (!s->top || !s->top->next)
		return (false);
	first = s->top;
	second = s->top->next;
	num = first->data;
	first->data = second->data;
	second->data = num;
	return (true);
}

void	sa(t_stack *a)
{
	if (ft_swap(a))
		write (1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (ft_swap(b))
		write (1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a->top || !a->top->next || !b->top || !b->top->next)
		return ;
	ft_swap(a);
	ft_swap(b);
	write (1, "ss\n", 3);
}
