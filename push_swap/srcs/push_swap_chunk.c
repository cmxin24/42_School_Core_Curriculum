/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:25:59 by xin               #+#    #+#             */
/*   Updated: 2025/08/14 15:15:21 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_max_rank_to_top(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		max_rank;
	size_t	max_index;
	size_t	index;
	int		pos_a;
	int		pos_b;
	int		target;

	current = b->top;
	max_rank = current->rank;
	max_index = 0;
	index = 0;

	ft_find_max(b, &max_rank, &max_index);
	target = ft_find_insert_pos(a, max_rank);
	if (max_index <= b->size / 2)
		pos_b = (int)max_index;
	else
		pos_b = -(int)(b->size - max_index);
	if (target <= (int)(a->size / 2))
		pos_a = target;
	else
		pos_a = -(int)(a->size - target);
	while (pos_a > 0 && pos_b > 0)
	{
		ft_rr(a, b);
		pos_a--;
		pos_b--;
	}
	while (pos_a < 0 && pos_b < 0)
	{
		ft_rrr(a, b);
		pos_a++;
		pos_b++;
	}
	while (pos_b > 0)
	{
		ft_rb(b);
		pos_b--;
	}
	while (pos_b < 0)
	{
		ft_rrb(b);
		pos_b++;
	}
	while (pos_a > 0)
	{
		ft_ra(a);
		pos_a--;
	}
	while (pos_a < 0)
	{
		ft_rra(a);
		pos_a++;
	}
}

bool	ft_sort_chunk(t_stack *a, t_stack *b, int chunk_num)
{
	int	total_size;

	total_size = a->size;
	ft_push_chunks(a, b, chunk_num, total_size);
	while (b->size > 0)
	{
		ft_max_rank_to_top(a, b);
		ft_pa(a, b);
	}
	return (true);
}
