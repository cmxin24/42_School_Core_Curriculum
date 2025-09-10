/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:49:49 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 18:42:17 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	remove_op(t_list *to_delete)
{
	to_delete->prev->next = to_delete->next;
	if (to_delete->next)
		to_delete->next->prev = to_delete->prev;
	ft_lstdelone(to_delete, NULL);
}

bool	op_on_same_stack(t_op ref, t_op to_check)
{
	if (ref == pa || ref == pb || ref == rr || ref == rrr)
		return (true);
	if (to_check == pa || to_check == pb || to_check == rr || to_check == rrr)
		return (true);
	else if ((ref == ra || ref == rra || ref == sa) && (to_check == ra
			|| to_check == rra || to_check == sa))
		return (true);
	else if ((ref == rb || ref == rrb || ref == sb) && (to_check == rb
			|| to_check == rrb || to_check == sb))
		return (true);
	return (false);
}

void	eliminate_opposite_op(t_list *op_list)
{
	t_list	*ref;
	t_list	*cmp;
	t_op	op_neutral;

	ref = op_list->next;
	while (ref && ref->next)
	{
		op_neutral = neutral_op(op_from(ref));
		if (op_neutral)
		{
			cmp = ref->next;
			while (!op_on_same_stack(op_from(ref), op_from(cmp))
				&& op_from(cmp) != op_neutral && cmp->next)
				cmp = cmp->next;
			if (ref->prev && op_from(cmp) == op_neutral)
			{
				ref = ref->prev;
				remove_op(ref->next);
				remove_op(cmp);
				continue ;
			}
		}
		ref = ref->next;
	}
}

t_op	child_op(t_op first, t_op second)
{
	if ((first == ra && second == rb) || (first == rb && second == ra))
		return (rr);
	else if ((first == rra && second == rrb) || (first == rrb && second == rra))
		return (rrr);
	else if ((first == sa && second == sb) || (first == sb && second == sa))
		return (ss);
	else
		return (NULL_OP);
}

void	ft_final_optimization(t_ps *data)
{
	t_list	*opt;
	t_op	child;

	if (!data->opt)
		return ;
	eliminate_opposite_op(data->opt);
	opt = data->opt;
	while (opt && opt->next)
	{
		child = child_op(op_from(opt), op_from(opt->next));
		if (child)
		{
			remove_op(opt->next);
			opt->content = (void *)(uintptr_t)child;
		}
		opt = opt->next;
	}
}
