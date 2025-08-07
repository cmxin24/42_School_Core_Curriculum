/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:10:29 by xin               #+#    #+#             */
/*   Updated: 2025/08/05 12:31:25 by xin              ###   ########.fr       */
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

void	pop(s_stack *s, int *num)
{
	if
}
