/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_untils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:36:10 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 17:20:54 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_split_location(t_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == A_top)
	{
		min->loc = B_bottom;
		mid->loc = B_top;
		max->loc = A_bottom;
	}
	else if (loc == A_bottom)
	{
		min->loc = B_bottom;
		mid->loc = B_top;
		max->loc = A_top;
	}
	else if (loc == B_top)
	{
		min->loc = B_bottom;
		mid->loc = A_bottom;
		max->loc = A_top;
	}
	else if (loc == B_bottom)
	{
		min->loc = B_top;
		mid->loc = A_bottom;
		max->loc = A_top;
	}
}

void	set_third_piovt(t_loc loc, int current_size, int *piovt_1, int *piovt_2)
{
	*piovt_2 = current_size / 3;
	if (loc == A_top || loc == A_bottom)
		*piovt_1 = 2 * current_size / 3;
	if (loc == B_top || loc == B_bottom)
		*piovt_1 = current_size / 2;
	if ((loc == A_top || loc == A_bottom) && current_size < 15)
		*piovt_1 = current_size;
	if (loc == B_bottom && current_size < 8)
		*piovt_2 = current_size / 2;
}
