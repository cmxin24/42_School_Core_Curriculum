/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:00:19 by xin               #+#    #+#             */
/*   Updated: 2025/08/13 02:20:18 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_stack *s)
{
	t_node	*temp;

	while (s->top)
	{
		temp = s->top;
		s->top = s->top->next;
		free(temp);
	}
	s->size = 0;
}

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
}

void	ft_update_chunk(int *start, int *end, int chunk_size, int *pushed)
{
	*start = *end;
	*end += chunk_size;
	*pushed = 0;
}

void	ft_push_chunks(t_stack *a, t_stack *b, int chunk_num, int total_size)
{
	int		start;
	int		end;
	int		pushed;
	int		chunk_size;
	t_node	*top;

	start = 0;
	chunk_size = total_size / chunk_num + 1;
	end = chunk_size;
	pushed = 0;
	while (a->size > 0)
	{
		top = a->top;
		if (top->rank >= start && top->rank < end)
		{
			ft_pb(a, b);
			pushed++;
			if (b->top->rank < start + (chunk_size / 2))
				ft_rb(b);
		}
		else
			ft_ra(a);
		if (pushed >= chunk_size)
			ft_update_chunk(&start, &end, chunk_size, &pushed);
	}
}
