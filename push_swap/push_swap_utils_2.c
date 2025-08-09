/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:07:01 by xin               #+#    #+#             */
/*   Updated: 2025/08/09 11:08:17 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_reverse(t_stack *a, t_stack *b)
{
	int	num;

	while (a->top)
	{
		ft_pop(a, &num);
		ft_push(b, num);
	}
	while (b->top)
	{
		ft_pop(b, &num);
		ft_push(a, num);
	}
	return (true);
}

bool	ft_reverse_rotate(t_stack *a)
{
	t_node	*befor_last;
	t_node	*last;

	if (!a->top || !a->top->next)
		return (false);
	befor_last = a->top;
	while (befor_last->next->next)
		befor_last = befor_last->next;
	last = befor_last->next;
	befor_last->next = NULL;
	last->next = a->top;
	a->top = last;
	return (true);
}
