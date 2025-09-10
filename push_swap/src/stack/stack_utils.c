/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:18:41 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 17:25:53 by xin              ###   ########.fr       */
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

void	ft_check_duplicates(t_ps *data, int *num_array, int lenth)
{
	int	i;
	int	j;

	i = 0;
	while (i < lenth - 1)
	{
		j = i + 1;
		while (j < lenth)
		{
			if (num_array[i] == num_array[j])
			{
				free(num_array);
				ft_error(data);
			}
			j++;
		}
		i++;
	}
}

int	ft_next_up(t_stack *s, int index)
{
	if (ft_current_size(s) == 0)
		return (index);
	if (index == 0)
		return (s->size - 1);
	else
		return (index - 1);
}

int	ft_next_down(t_stack *s, int index)
{
	if (ft_current_size(s) == 0)
		return (index);
	if (index == s->size - 1)
		return (0);
	else
		return (index + 1);
}
