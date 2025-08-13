/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:26:06 by xin               #+#    #+#             */
/*   Updated: 2025/08/12 23:04:34 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_push_to(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	if (!src->top)
		return (false);
	temp = src->top;
	src->top = temp->next;
	src->size--;
	temp->next = dest->top;
	dest->top = temp;
	dest->size++;
	return (true);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	if (ft_push_to(a, b))
		write (1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (ft_push_to(b, a))
		write (1, "pb\n", 3);
}
