/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:30:10 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 18:34:46 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_op	op_from(t_list *node)
{
	return ((t_op)(uintptr_t)node->content);
}

t_op	opposite_op(t_op op)
{
	if (op == pa)
		return (pb);
	if (op == pb)
		return (pa);
	if (op == ra)
		return (rra);
	if (op == rb)
		return (rrb);
	if (op == rra)
		return (ra);
	if (op == rrb)
		return (rb);
	if (op == sa)
		return (sa);
	if (op == sb)
		return (sb);
	if (op == rr)
		return (rrr);
	if (op == rrr)
		return (rr);
	return (NULL_OP);
}
