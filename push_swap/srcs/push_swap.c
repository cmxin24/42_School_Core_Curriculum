/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:50:03 by xin               #+#    #+#             */
/*   Updated: 2025/08/19 11:05:28 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_push_swap(t_stack *a, t_stack *b, int num_size)
{
	if (num_size == 3)
		return (ft_sort_three(a));
	else if (num_size <= 10)
		return (ft_sort_small(a, b, num_size));
	else if (num_size <= 100)
		return (ft_sort_chunk(a, b, 5));
	else if (num_size <= 300)
		return (ft_sort_chunk(a, b, 8));
	else if (num_size <= 500)
		return (ft_sort_chunk(a, b, 9));
	else
		return (ft_sort_chunk(a, b, 13));
	return (false);
}

void	ft_update_chunk(int *start, int *end, int chunk_size, int *pushed)
{
	*start = *end;
	*end += chunk_size;
	*pushed = 0;
}

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

// 找到栈 b 中的最大 rank 及其下标
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

// 找到最小/最大 rank 及其下标
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

// 找到 rank 插入到栈 a 的正确位置
int	ft_find_insert_pos(t_stack *a, int rank, int index)
{
	t_node	*current;
	int		min_rank;
	int		max_rank;
	int		min_i;
	int		max_i;

	if (a->size == 0 || a->size == 1)
		return (0);
	// 找到最小值和最大值及其下标
	max_i = ft_minmax_rank_index(a, &min_rank, &max_rank, &min_i);
	// 情况1: 比最小值还小 → 插到最小值前面
	if (rank < min_rank)
		return (min_i);
	// 情况2: 比最大值还大 → 插到最大值后面
	if (rank > max_rank)
		return (max_i + 1 == a->size ? 0 : max_i + 1);
	// 情况3: 插到第一个比它大的元素之前
	current = a->top;
	index = 0;
	while (current)
	{
		if (current->rank > rank)
			return (index);
		current = current->next;
		index++;
	}
	return (0);
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

/* void	ft_push_chunks(t_stack *a, t_stack *b, int chunk_num, int total_size)
{
	int		start;
	int		end;
	int		pushed;
	int		chunk_size;
	int		mid;
	t_node	*cur;

	start = 0;
	chunk_size = total_size / chunk_num + 1;
	end = chunk_size;
	while (start < total_size)
	{
		pushed = 0;
		mid = (start + end) / 2;
		while (pushed < chunk_size && a->size > 0)
		{
			cur = a->top;
			if (cur->rank >= start && cur->rank < end)
			{
				ft_pb(a, b);
				if (b->top->rank < mid)
					ft_rb(b);
				pushed++;
			}
			else
				ft_ra(a);
		}
		start = end;
		end += chunk_size;
		if (end > total_size)
			end = total_size;
	}
} */

// 找某个 rank 在栈 a 中的位置
int	ft_find_index_by_rank(t_stack *a, int rank)
{
	t_node	*cur;
	int		i;

	cur = a->top;
	i = 0;
	while (cur)
	{
		if (cur->rank == rank)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

// 计算从A到B的最优旋转成本
int	ft_get_cost_to_b(t_stack *a, t_stack *b, int rank, int *case_type)
{
	int	pos_a = ft_find_index_by_rank(a, rank);
	int	pos_b = ft_find_insert_pos(b, rank, 0);
	int	size_a = a->size;
	int	size_b = b->size;
	int	cost_rarb = (pos_a > pos_b ? pos_a : pos_b);
	int	cost_rrarrb = ((size_a - pos_a) > (size_b - pos_b)
			? (size_a - pos_a) : (size_b - pos_b));
	int	cost_rarrb = pos_a + (size_b - pos_b);
	int	cost_rrarb = (size_a - pos_a) + pos_b;
	int	best = cost_rarb;

	*case_type = 0;
	if (cost_rrarrb < best)
		(best = cost_rrarrb, *case_type = 1);
	if (cost_rarrb < best)
		(best = cost_rarrb, *case_type = 2);
	if (cost_rrarb < best)
		(best = cost_rrarb, *case_type = 3);
	return (best);
}


// 根据 case_type 执行旋转，直到 rank 到达正确位置
void	ft_apply_rotation_to_push(t_stack *a, t_stack *b, int rank, int case_type)
{
	int	pos_a;
	int	pos_b;

	while (1)
	{
		pos_a = ft_find_index_by_rank(a, rank);
		pos_b = ft_find_insert_pos(b, rank, 0);
		if (pos_a == 0 && pos_b == 0)
			break ;
		if (case_type == 0) // rarb
		{
			if (pos_a > 0 && pos_b > 0)
				ft_rr(a, b);
			else if (pos_a > 0)
				ft_ra(a);
			else if (pos_b > 0)
				ft_rb(b);
		}
		else if (case_type == 1) // rrarrb
		{
			if (pos_a > 0 && pos_b > 0)
				ft_rrr(a, b);
			else if (pos_a > 0)
				ft_rra(a);
			else if (pos_b > 0)
				ft_rrb(b);
		}
		else if (case_type == 2) // rarrb
		{
			if (pos_a > 0)
				ft_ra(a);
			else if (pos_b > 0)
				ft_rrb(b);
		}
		else if (case_type == 3) // rrarb
		{
			if (pos_a > 0)
				ft_rra(a);
			else if (pos_b > 0)
				ft_rb(b);
		}
	}
}


// 计算从B到A的最优旋转成本
int	ft_get_cost_to_a(t_stack *a, t_stack *b, int rank, int *case_type)
{
	int	pos_a = ft_find_insert_pos(a, rank, 0);
	int	pos_b = ft_find_index_by_rank(b, rank);
	int	size_a = a->size;
	int	size_b = b->size;
	int	cost_rarb = (pos_a > pos_b ? pos_a : pos_b);
	int	cost_rrarrb = ((size_a - pos_a) > (size_b - pos_b)
			? (size_a - pos_a) : (size_b - pos_b));
	int	cost_rarrb = pos_a + (size_b - pos_b);
	int	cost_rrarb = (size_a - pos_a) + pos_b;
	int	best = cost_rarb;

	*case_type = 0;
	if (cost_rrarrb < best)
		(best = cost_rrarrb, *case_type = 1);
	if (cost_rarrb < best)
		(best = cost_rarrb, *case_type = 2);
	if (cost_rrarb < best)
		(best = cost_rrarb, *case_type = 3);
	return (best);
}

/* ** 根据 case_type 执行旋转，直到 rank 到达 A 的正确位置 */
void	ft_apply_rotation_to_insert(t_stack *a, t_stack *b,
			int rank, int case_type)
{
	int	pos_a;
	int	pos_b;

	while (1)
	{
		pos_a = ft_find_insert_pos(a, rank, 0);
		pos_b = ft_find_index_by_rank(b, rank);
		if (pos_a == 0 && pos_b == 0)
			break ;
		if (case_type == 0) // rarb
		{
			if (pos_a > 0 && pos_b > 0)
				ft_rr(a, b);
			else if (pos_a > 0)
				ft_ra(a);
			else if (pos_b > 0)
				ft_rb(b);
		}
		else if (case_type == 1) // rrarrb
		{
			if (pos_a > 0 && pos_b > 0)
				ft_rrr(a, b);
			else if (pos_a > 0)
				ft_rra(a);
			else if (pos_b > 0)
				ft_rrb(b);
		}
		else if (case_type == 2) // rarrb
		{
			if (pos_a > 0)
				ft_ra(a);
			else if (pos_b > 0)
				ft_rrb(b);
		}
		else if (case_type == 3) // rrarb
		{
			if (pos_a > 0)
				ft_rra(a);
			else if (pos_b > 0)
				ft_rb(b);
		}
	}
}

void ft_optimized_rotate_to_insert(t_stack *a, t_stack *b) {
    int best_rank = -1;
    int min_cost = INT_MAX;
    int best_case = 0;
    t_node *current = b->top;
    
    // 预计算所有元素的插入成本
    while (current) {
        int case_type;
        int cost = ft_get_cost_to_a(a, b, current->rank, &case_type);
        if (cost < min_cost) {
            min_cost = cost;
            best_rank = current->rank;
            best_case = case_type;
        }
        current = current->next;
    }
    
    // 执行最优旋转
    ft_apply_rotation_to_insert(a, b, best_rank, best_case);
}

void ft_final_optimize(t_stack *a) {
    int min_pos = ft_find_index_by_rank(a, 0);
    int half = a->size / 2;
    
    if (min_pos <= half) {
        while (min_pos-- > 0) ft_ra(a);
    } else {
        min_pos = a->size - min_pos;
        while (min_pos-- > 0) ft_rra(a);
    }
}

/* // 主排序函数：使用chunk策略和cost-based优化
bool ft_sort_chunk(t_stack *a, t_stack *b, int chunk_num) {
    int total_size = a->size;
    
    // 推送阶段
    ft_push_chunks(a, b, chunk_num, total_size);
    
    // 回收阶段
    while (b->size > 0) {
        ft_optimized_rotate_to_insert(a, b);
        ft_pa(a, b);
    }
    
    // 最终整理
    ft_final_optimize(a);
    return true;
} */

bool ft_has_in_range(t_stack *a, int start, int end)
{
    t_node *cur;

    cur = a->top;
    while (cur)
    {
        if (cur->rank >= start && cur->rank < end)
            return (true);
        cur = cur->next;
    }
    return (false);
}

// 找出 [start,end) 范围内的元素，并用更优的旋转方式推送到 B
// 找出 [start,end) 范围内的元素，并用更优的旋转方式推送到 B
void ft_smart_push(t_stack *a, t_stack *b, int start, int end)
{
    int top_steps;
    int bottom_steps;
    int index;
    int target_index;
    t_node *cur;

    // 先找目标在栈中的位置（从上往下第几个）
    target_index = -1;
    index = 0;
    cur = a->top;
    while (cur)
    {
        if (cur->rank >= start && cur->rank < end)
        {
            target_index = index;
            break ;
        }
        index++;
        cur = cur->next;
    }
    if (target_index == -1) // 没找到，直接返回
        return ;

    top_steps = target_index;
    bottom_steps = a->size - target_index;

    if (top_steps <= bottom_steps)
    {
        while (top_steps-- > 0)
            ft_ra(a);
    }
    else
    {
        while (bottom_steps-- > 0)
            ft_rra(a);
    }
    ft_pb(a, b);
}


// 改进后的推送阶段：动态 chunk + 双端推送
void ft_push_chunks(t_stack *a, t_stack *b, int chunk_num, int total_size)
{
    int start;
    int end;
    int chunk_size;
    int i;

    start = 0;
    i = 0;
    while (i < chunk_num)
    {
        chunk_size = total_size / chunk_num;
        if (i < total_size % chunk_num)
            chunk_size++;
        end = start + chunk_size;

        while (ft_has_in_range(a, start, end))
        {
            if (a->top->rank >= start && a->top->rank < end)
            {
                ft_pb(a, b);
                if (b->top->rank >= start + chunk_size / 2)
                    ft_rb(b);
            }
            else
                ft_smart_push(a, b, start, end);
        }
        start = end;
        i++;
    }
}

// 回收阶段：不断把 B 的最大值移到顶再 pa
void ft_recover_from_b(t_stack *a, t_stack *b)
{
    int max_rank;
    size_t max_index;
    int steps;

    while (b->size > 0)
    {
        ft_find_max(b, &max_rank, &max_index);
        if ((int)max_index <= b->size / 2)
        {
            while ((int)max_index-- > 0)
                ft_rb(b);
        }
        else
        {
            steps = b->size - (int)max_index;
            while (steps-- > 0)
                ft_rrb(b);
        }
        ft_pa(a, b);
    }
}

// 整体排序：优化版 chunk 策略
bool ft_sort_chunk(t_stack *a, t_stack *b, int chunk_num)
{
    int total_size;

    total_size = a->size;
    ft_push_chunks(a, b, chunk_num, total_size);
    ft_recover_from_b(a, b);
    ft_final_optimize(a);
    return (true);
}
