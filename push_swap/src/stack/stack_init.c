/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:41:50 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 11:10:47 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_init_stack(t_ps *data, t_stack *s, int size)
{
	s->rank = malloc(sizeof(int) * size);
	if (!s->rank)
		ft_error(data);
	s->top = 0;
	s->bottom = 0;
	s->size = size;
	ft_memset(s->rank, 0, sizeof(int) * size);
}

void	ft_quicksort(int *num_array, int left, int right)
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
		ft_quicksort(num_array, left, j);
	if (i < right)
		ft_quicksort(num_array, i, right);
}

int	ft_find_rank(int *sorted_num, int size, int input_num)
{
	int	left;
	int	mid;
	int	right;
	int	rank;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (sorted_num[mid] <= input_num)
		{
			rank = mid + 1;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return (rank);
}

bool	ft_set_rank(int *numbers, int *rank, int size)
{
	int	i;
	int	*sorted_num;

	sorted_num = malloc (sizeof(int) * size);
	if (!sorted_num)
		return (false);
	i = 0;
	while (i < size)
	{
		sorted_num[i] = numbers[i];
		i++;
	}
	ft_quicksort(sorted_num, 0, size - 1);
	i = 0;
	while (i < size)
	{
		rank[i] = ft_find_rank(sorted_num, size, numbers[i]);
		i++;
	}
	free(sorted_num);
	return (true);
}

void	ft_add_number_to_stack(t_ps *data, t_stack *s, int size, char **argv)
{
	int	i;
	int	*numbers;

	i = 0;
	numbers = malloc (sizeof(int) * size);
	if (!numbers)
		ft_error(data);
	while (argv[i])
	{
		if (!ft_argv_check(argv[i]))
			ft_error(data);
		numbers[i] = ft_atoi(argv[i]);
		i++;
	}
	ft_check_duplicates(data, numbers, size);
	if (!ft_set_rank(numbers, s->rank, size))
		ft_error(data);
	s->bottom = size - 1;
	free(numbers);
}
