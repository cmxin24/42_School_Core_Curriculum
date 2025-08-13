/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:50:01 by xin               #+#    #+#             */
/*   Updated: 2025/08/13 01:03:07 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_sort_three(t_stack *a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = a->top->data;
	num2 = a->top->next->data;
	num3 = a->top->next->next->data;
	if (num1 < num2 && num2 < num3)
		return (true);
	if (num1 < num3 && num3 < num2)
		return (ft_rra(a), ft_sa(a), true);
	if (num2 < num1 && num1 < num3)
		return (ft_sa(a), true);
	if (num1 < num2 && num3 < num1)
		return (ft_rra(a), true);
	if (num1 > num3 && num2 < num3)
		return (ft_ra(a), true);
	if (num1 > num2 && num2 > num3)
		return (ft_sa(a), ft_rra(a), true);
	return (false);
}
