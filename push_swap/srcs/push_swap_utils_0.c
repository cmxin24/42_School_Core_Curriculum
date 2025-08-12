/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:10:29 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 12:25:24 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *s, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
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

bool	get_num(t_stack *a, int index, int	*num)
{
	t_node	*current_node;

	current_node = a->top;
	while (current_node && index > 0)
	{
		current_node = current_node->next;
		index --;
	}
	if (current_node)
		num = current_node->data;
	else
		return (false);
	return (true);
}
