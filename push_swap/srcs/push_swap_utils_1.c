/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:57:00 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 10:43:13 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_atol(char *s)
{
	long	num;
	int		sign;
	size_t	index;

	num = 0;
	sign = 1;
	index = 0;
	if (s[index] == '+' || s[index] == '-')
	{
		if (s[index] == '-')
			sign = -1;
		index += 1;
	}
	while (s[index] >= '0' && s[index] <= '9')
	{
		num = num * 10 + (s[index] - '0');
		index += 1;
	}
	return (num * sign);
}

int	is_number(char *s)
{
	size_t	index;

	index = 0;
	if (s[index] == '+' || s[index] == '-')
		index += 1;
	if (s[index] == '\0')
		return (0);
	while (s[index])
	{
		if (s[index] < '0' || s[index] > '9')
			return (0);
		index += 1;
	}
	return (1);
}

void	ft_check_duplicates(int *num_array, int lenth)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < lenth - 1)
	{
		j = i + 1;
		while (j < lenth)
		{
			if (num_array[i] == num_array[j])
				ft_print_error();
			j++;
		}
		i++;
	}
}

int	*ft_argv_check(int argc, char *argv[])
{
	int		*num_array;
	size_t	i;
	long	num;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	num_array = (int *)malloc((argc - 1) * sizeof(int));
	if (!num_array)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			ft_print_error();
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_print_error();
		num_array[i - 1] = (int)num;
		i++;
	}
	ft_check_duplicates(num_array, argc - 1);
	return (num_array);
}
