/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:21:20 by meyu              #+#    #+#             */
/*   Updated: 2025/08/14 17:23:26 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_is_stack_sorted(t_stack *a)
{
	t_node	*current;

	if (!a->top)
		return (true);
	current = a->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}