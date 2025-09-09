/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:34:50 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 20:21:25 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"
#include <stdio.h>

void	ft_run_opt(t_ps *data, t_op opt)
{
	if (opt == pa)
		push_a(data);
	else if (opt == pb)
		push_b(data);
	else if (opt == rra)
		r_rotate_a(data);
	else if (opt == rrb)
		r_rotate_b(data);
	else if (opt == rrr)
		r_rotate_ab(data);
	else if (opt == ra)
		rotate_a(data);
	else if (opt == rb)
		rotate_b(data);
	else if (opt == rr)
		rotate_ab(data);
	else if (opt == sa)
		swap_a(data);
	else if (opt == sb)
		swap_b(data);
	else if (opt == ss)
		swap_ab(data);
	else
		ft_error(data);
}

int	ft_checker(t_ps *data)
{
	t_list	*opt;

	opt = data->opt;
	while (opt)
	{
		ft_run_opt(data, (t_op)(uintptr_t)opt->content);
		opt = opt->next;
	}
	if (data->a.size == ft_current_size(&data->a) && ft_is_sorted(data))
		return (1);
	else
		return (0);
}

t_op	ft_detect_opt(const char *str)
{
	if (!ft_strncmp(str, "pa", 2) && ft_strlen(str) == 2)
		return (pa);
	else if (!ft_strncmp(str, "pb", 2) && ft_strlen(str) == 2)
		return (pb);
	else if (!ft_strncmp(str, "rra", 3) && ft_strlen(str) == 3)
		return (rra);
	else if (!ft_strncmp(str, "rrb", 3) && ft_strlen(str) == 3)
		return (rrb);
	else if (!ft_strncmp(str, "rrr", 3) && ft_strlen(str) == 3)
		return (rrr);
	else if (!ft_strncmp(str, "ra", 2) && ft_strlen(str) == 2)
		return (ra);
	else if (!ft_strncmp(str, "rb", 2) && ft_strlen(str) == 2)
		return (rb);
	else if (!ft_strncmp(str, "rr", 2) && ft_strlen(str) == 2)
		return (rr);
	else if (!ft_strncmp(str, "sa", 2) && ft_strlen(str) == 2)
		return (sa);
	else if (!ft_strncmp(str, "sb", 2) && ft_strlen(str) == 2)
		return (sb);
	else if (!ft_strncmp(str, "ss", 2) && ft_strlen(str) == 2)
		return (ss);
	else
		return (NULL_OP);
}

void	ft_read_opt(t_ps *data)
{
	t_list	*new;
	char	*line;
	t_op	opt;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		opt = ft_detect_opt(line);
		free(line);
		if (opt == NULL_OP)
			ft_error(data);
		new = ft_lstnew((void *)(uintptr_t)opt);
		if (!new)
			ft_error(data);
		ft_lstadd_back(&data->opt, new);
	}
}

int	main(int argc, char **argv)
{
	t_ps	data;
	int		status;

	ft_init_data(&data, argc, argv, false);
	if (data.a.size == 0)
		return (0);
	ft_read_opt(&data);
	status = ft_checker(&data);
	if (status == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_data(&data);
	return (0);
}
