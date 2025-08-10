/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:10:29 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 10:29:04 by xin              ###   ########.fr       */
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

