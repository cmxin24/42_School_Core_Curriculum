/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:13:20 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 10:43:43 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

const char	*operation_to_string(t_op opt)
{
	static const char	*strings[12];

	strings[0] = "NULL_OP";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "ra";
	strings[4] = "rb";
	strings[5] = "rr";
	strings[6] = "rra";
	strings[7] = "rrb";
	strings[8] = "rrr";
	strings[9] = "sa";
	strings[10] = "sb";
	strings[11] = "ss";
	return (strings[opt]);
}

void	ft_print_operations(t_list *opt)
{
	t_list	*opt_cpy;

	opt_cpy = opt;
	while (opt_cpy)
	{
		ft_printf("%s\n",
			operation_to_string((t_op)(uintptr_t)opt_cpy->content));
		opt_cpy = opt_cpy->next;
	}
}
