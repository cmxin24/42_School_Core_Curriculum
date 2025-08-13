/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:10:29 by xin               #+#    #+#             */
/*   Updated: 2025/08/13 01:53:23 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_push(t_stack *s, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (false);
	new->data = num;
	new->next = s->top;
	new->rank = -1;
	s->top = new;
	s->size++;
	return (true);
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
		*num = current_node->data;
	else
		return (false);
	return (true);
}

bool	ft_array_to_stack(t_stack *s, int *num_array, size_t num_size)
{
	size_t	i;

	i = num_size;
	s->top = NULL;
	s->size = 0;
	while (i > 0)
	{
		i --;
		if (!ft_push(s, num_array[i]))
			return (false);
	}
	return (true);
}

void	quicksort(int *num_array, int left, int right)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	i = left;
	j = right;
	pivot = num_array[(left + right) / 2];
	while (i <= j)
	{
		while (num_array[i] < pivot)
			i++;
		while (num_array[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = num_array[i];
			num_array[i++] = num_array[j];
			num_array[j--] = temp;
		}
	}
	if (left < j)
		quicksort(num_array, left, j);
	if (i < right)
		quicksort(num_array, i, right);
}
