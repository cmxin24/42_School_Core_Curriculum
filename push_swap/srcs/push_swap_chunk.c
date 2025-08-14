/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:25:59 by xin               #+#    #+#             */
/*   Updated: 2025/08/14 19:08:02 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_find_max(t_stack *b, int *max_rank, size_t *max_index)
{
	t_node	*current;
	size_t	i;

	current = b->top;
	i = 0;
	*max_rank = current->rank;
	*max_index = 0;
	while (current)
	{
		if (current->rank > *max_rank)
		{
			*max_rank = current->rank;
			*max_index = i;
		}
		current = current->next;
		i++;
	}
}

int	ft_minmax_rank_index(t_stack *a, int *min_rank, int *max_rank, int *min_i)
{
	int		max_i;
	t_node	*current;
	size_t	i;

	current = a->top;
	i = 0;
	*min_i = 0;
	max_i = 0;
	*min_rank = current->rank;
	*max_rank = current->rank;
	while (current)
	{
		if (current->rank < *min_rank)
		{
			*min_rank = current->rank;
			*min_i = i;
		}
		if (current->rank > *max_rank)
		{
			*max_rank = current->rank;
			max_i = i;
		}
		current = current->next;
		i++;
	}
	return (max_i);
}

int	ft_find_insert_pos(t_stack *a, int rank, int index)
{
	t_node	*current;
	int		min_rank;
	int		max_rank;
	int		min_i;
	int		max_i;

	if (a->size == 0 || a->size == 1)
		return (0);
	max_i = ft_minmax_rank_index(a, &min_rank, &max_rank, &min_i);
	if (rank > max_rank || rank < min_rank)
	{
		if (a->size > 0)
			return ((max_i + 1) % a->size);
		else
			return (0);
	}
	current = a->top;
	while (current)
	{
		if (current->rank > rank)
			return (index);
		current = current->next;
		index++;
	}
	return (index);
}

void	ft_max_rank_to_top(t_stack *a, t_stack *b)
{
	int		max_rank;
	size_t	max_index;
	int		pos_a;
	int		pos_b;
	int		target;

	max_index = 0;
	ft_find_max(b, &max_rank, &max_index);
	target = ft_find_insert_pos(a, max_rank, 0);
	if ((int)max_index <= b->size / 2)
		pos_b = (int)max_index;
	else
		pos_b = -(int)(b->size - max_index);
	if (target <= (int)(a->size / 2))
		pos_a = target;
	else
		pos_a = -(int)(a->size - target);
	while (pos_a != 0 || pos_b != 0)
	{
		if (pos_a > 0 && pos_b > 0)
			(ft_rr(a, b), pos_a--, pos_b--);
		else if (pos_a < 0 && pos_b < 0)
			(ft_rrr(a, b), pos_a++, pos_b++);
		else if (pos_b > 0)
			(ft_rb(b), pos_b--);
		else if (pos_b < 0)
			(ft_rrb(b), pos_b++);
		else if (pos_a > 0)
			(ft_ra(a), pos_a--);
		else if (pos_a < 0)
			(ft_rra(a), pos_a++);
	}
}

int	ft_calculate_reserve_threshold(int total_size, int chunk_num)
{
	int chunk_size = total_size / chunk_num + 1;
	
	// 根据总大小动态调整保留阈值
	if (total_size <= 100)
		return chunk_size * 2;  // 保留最后2个chunk
	else if (total_size <= 500)
		return chunk_size * 3;  // 保留最后3个chunk
	else
		return chunk_size * 4;  // 保留最后4个chunk
}

void	ft_sort_last_chunk_in_a(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->top->rank > a->top->next->rank)
		ft_sa(a);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size <= 5)
		ft_sort_small(a, b, a->size);
	else
	{
		while (!ft_is_stack_sorted(a))
		{
			if (a->top->rank > a->top->next->rank)
				ft_sa(a);
			ft_ra(a);
		}
	}
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
			if (b->top->rank < (start + end) / 2)
				ft_rb(b);
		}
		else
			ft_ra(a);
		if (pushed >= chunk_size)
			ft_update_chunk(&start, &end, chunk_size, &pushed);
	}
}

bool	ft_sort_chunk(t_stack *a, t_stack *b, int chunk_num)
{
	int	total_size;

	total_size = a->size;
	while (a->size > 0)
		ft_push_chunks(a, b, chunk_num, total_size);
	while (b->size > 0)
	{
		ft_max_rank_to_top(a, b);
		ft_pa(a, b);
	}
	return (true);
}
