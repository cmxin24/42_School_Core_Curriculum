/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:18:41 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 17:30:49 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	ft_current_size(t_stack *s)
{
	if (s->top == s->bottom && s->rank[s->top] == 0)
		return (0);
	return (((s->bottom - s->top + s->size) % s->size) + 1);
}

bool	ft_argv_check(char *argv)
{
	long	num;
	int		sign;

	sign = 1;
	if (*argv == '\0')
		return (false);
	if (*argv == '-' || *argv == '+')
	{
		if (*argv == '-')
			sign = -1;
		argv++;
		if (*argv == '\0')
			return (false);
	}
	num = 0;
	while (*argv)
	{
		if (!ft_isdigit(*argv))
			return (false);
		num = num * 10 + (*argv - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
			return (false);
		argv++;
	}
	return (true);
}

int	ft_check_duplicates(int *num_array, int size, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (num_array[i] == num_array[j])
			{
				free(num_array);
				ft_free_split(argv, size);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
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
