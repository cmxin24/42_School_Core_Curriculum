/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:41:50 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 20:42:53 by meyu             ###   ########.fr       */
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

void	ft_generate_numbers(t_ps *data, int **numbers, int size, char **argv)
{
	*numbers = malloc (sizeof(int) * size);
	if (!*numbers)
	{
		ft_free_split(argv, size);
		ft_error(data);
	}
}

void	ft_add_number_to_stack(t_ps *data, t_stack *s, int size, char **argv)
{
	int	i;
	int	*numbers;

	i = 0;
	ft_generate_numbers(data, &numbers, size, argv);
	while (argv[i])
	{
		if (argv[i][0] == '\0' || !ft_argv_check(argv[i]))
		{
			free(numbers);
			ft_free_split(argv, size);
			ft_error(data);
		}
		numbers[i] = ft_atoi(argv[i]);
		i++;
	}
	if (!ft_check_duplicates(numbers, size, argv))
		ft_error(data);
	if (!ft_set_rank(numbers, s->rank, size))
	{
		ft_free_split(argv, size);
		ft_error(data);
	}
	s->bottom = size - 1;
	free(numbers);
}
