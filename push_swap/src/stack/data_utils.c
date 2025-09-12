/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:17:44 by meyu              #+#    #+#             */
/*   Updated: 2025/09/10 15:37:55 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_free_split(char **s, size_t size)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < size)
	{
		free (s[i]);
		i++;
	}
	free (s);
}

int	ft_fill_numbers_to_res(int argc, char **argv, char **res, int k)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
		{
			res[k] = ft_strdup(temp[j]);
			if (!res[k])
			{
				ft_free_split(res, k);
				ft_free_split(temp, j);
				return (0);
			}
			k++;
			j++;
		}
		ft_free_split(temp, j);
		i++;
	}
	return (res[k] = NULL, 1);
}

char	**ft_split_argv(int argc, char **argv, int *size)
{
	char	**temp;
	char	**res;
	int		i;
	int		j;
	int		total_num;

	i = 1;
	total_num = 0;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j++])
			total_num++;
		ft_free_split(temp, j);
		i++;
	}
	res = (char **)malloc (sizeof(char *) * (total_num + 1));
	if (!res)
		return (NULL);
	i = 1;
	if (ft_fill_numbers_to_res(argc, argv, res, 0) == 0)
		return (NULL);
	*size = total_num;
	return (res);
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
