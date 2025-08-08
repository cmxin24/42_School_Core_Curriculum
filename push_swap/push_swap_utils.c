/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:10:29 by xin               #+#    #+#             */
/*   Updated: 2025/08/08 16:30:04 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->top = NULL;
}

bool	isEmpty(t_stack *s)
{
	return (s->top == NULL);
}

void	push(t_stack *s, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->data = num;
	new_node->next = s->top;
	s->top = new_node;
}

int	pop(t_stack *s, int *num)
{
	t_node	*temp;

	if (isEmpty(s))
		return (0);
	temp = s->top;
	*num = temp->data;
	s->top = temp->next;
	free(temp);
	return (1);
}

