/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:25:59 by xin               #+#    #+#             */
/*   Updated: 2025/08/12 19:45:25 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_rank(int *num_arry, size_t num_size, int num)
{
	int	bottom;
	int	top;
	int	mid;

	bottom = 0;
	top = num_size - 1;
	while (bottom <= top)
	{
		mid = (bottom + top) / 2;
		if (num_arry[mid] == num)
			return (mid);
		else if (num_arry[mid] < num)
			bottom = mid + 1;
		else
			top = mid - 1;
	}
	return (-1);
}

void	ft_set_rank(t_stack *a, size_t num_size, int *num_array)
{
	t_node	*temp;
	int		i;

	temp = a->top;
	i = 0;
	while (temp)
	{
		num_array[i++] = temp->data;
		temp = temp->next;
	}
	quicksort(num_array, 0, num_size - 1);
	temp = a->top;
	while (temp)
	{
		temp->rank = ft_find_rank(num_array, num_size, temp->data);
		temp = temp->next;
	}
	free(num_array);
}

bool	ft_sort_chunk(t_stack *a, t_stack *b, int chunk_num)
{
	int		size;
	int		chunk_size;
	int		push_rank;
	t_node	*top;

	size = a->size;
	chunk_size = size / chunk_num;
	push_rank = 0;
	while (a->size > 0)
	{
		top = a->top;
		if (top->rank >= push_rank && top->rank < push_rank + chunk_size)
		{
			ft_pb(a, b);
			push_rank++;
		}
		else
			ft_ra(a);
	}
	while (b->top)
	{
		ft_max_to_top(b, size);
		ft_pa(a, b);
	}
	return (true);
}
