/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:25:33 by xin               #+#    #+#             */
/*   Updated: 2025/09/08 18:10:41 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	ft_save_operation(t_ps *data, t_op operation)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)operation);
	if (!new)
		ft_error(data);
	ft_lstadd_back(&data->opt, new);
}
