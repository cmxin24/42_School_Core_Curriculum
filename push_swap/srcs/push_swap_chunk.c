/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:25:59 by xin               #+#    #+#             */
/*   Updated: 2025/08/13 02:20:23 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_max_rank_to_top(t_stack *b, size_t num_size)
{
	t_node	*current;
	int		max_rank;
	size_t	max_index;
	size_t	index;
	int		pos;

	current = b->top;
	max_rank = current->rank;
	max_index = 0;
	index = 0;
	while (current)
	{
		if (current->rank > max_rank)
		{
			max_rank = current->rank;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	if (max_index <= (num_size / 2))
	{
		while (max_index-- > 0)
			ft_rb(b);
	}
	else
	{
		pos = num_size - max_index;
		while (pos-- > 0)
			ft_rrb(b);
	}
}

bool	ft_sort_chunk(t_stack *a, t_stack *b, int chunk_num)
{
	int	total_size;

	total_size = a->size;
	ft_push_chunks(a, b, chunk_num, total_size);
	while (b->size > 0)
	{
		ft_max_rank_to_top(b, b->size);
		ft_pa(a, b);
	}
	return (true);
}
