/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:10:29 by xin               #+#    #+#             */
/*   Updated: 2025/08/09 11:08:20 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *s, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->data = num;
	new_node->next = s->top;
	s->top = new_node;
}

int	ft_pop(t_stack *s, int *num)
{
	t_node	*temp;

	if (s->top == NULL)
		return (0);
	temp = s->top;
	*num = temp->data;
	s->top = temp->next;
	free(temp);
	return (1);
}

bool	ft_swap(t_stack *a)
{
	int	num_1;
	int	num_2;

	if (!a->top || !a->top->next)
		return (false);
	ft_pop(a, &num_1);
	ft_pop(a, &num_2);
	ft_push(a, num_1);
	ft_push(a, num_2);
	return (true);
}

bool	ft_push_ab(t_stack *a, t_stack *b)
{
	int	num;

	if (!b->top)
		return (false);
	ft_pop(b, &num);
	ft_push(a, num);
	return (true);
}

bool	ft_rotate(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a->top || !a->top->next)
		return (false);
	first = a->top;
	a->top = first->next;
	first->next = NULL;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	return (true);
}
