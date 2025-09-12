/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:40:10 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 18:03:13 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_init_data(t_ps *data, int argc, char **argv, bool mandatory_part)
{
	int		size;
	char	**numbers;

	size = 0;
	data->opt = NULL;
	data->mandatory_part = mandatory_part;
	numbers = ft_split_argv(argc, argv, &size);
	if (!numbers)
		ft_error(data);
	ft_init_stack(data, &data->a, size);
	ft_init_stack(data, &data->b, size);
	ft_add_number_to_stack(data, &data->a, size, numbers);
	ft_free_split(numbers, size);
}

void	ft_free_data(t_ps *data)
{
	if (data->a.rank)
	{
		free(data->a.rank);
		data->a.rank = NULL;
	}
	if (data->b.rank)
	{
		free(data->b.rank);
		data->b.rank = NULL;
	}
	if (data->opt)
		ft_lstclear(&data->opt, NULL);
}

void	ft_error(t_ps *data)
{
	ft_free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	ft_get_rank(t_stack *s, int n)
{
	int	i;

	i = s->top;
	while (--n > 0)
		i = ft_next_down(s, i);
	return (s->rank[i]);
}

bool	ft_is_sorted(t_ps *data)
{
	int	i;
	int	rank;

	i = data->a.top;
	rank = 1;
	while (rank <= data->a.size)
	{
		if (data->a.rank[i] != rank)
			return (false);
		i = ft_next_down(&data->a, i);
		rank++;
	}
	return (true);
}
