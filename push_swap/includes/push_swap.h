/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:17:33 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 11:26:45 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include "../lib/includes/libft.h"
# include "stack.h"

typedef enum e_location
{
	A_top,
	A_bottom,
	B_top,
	B_bottom
}	t_loc;

typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}	t_chunk;

typedef struct s_split
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_split;

void	ft_sort_stack(t_ps *data);

void	ft_sort_three(t_ps *data, t_chunk *to_sort);
void	ft_sort_two(t_ps *data, t_chunk *to_sort);
void	ft_sort_one(t_ps *data, t_chunk *to_sort);

bool	a_partly_sort(t_ps *data, int from);
void	ft_easy_sort(t_ps *data, t_chunk *to_sort);

void	ft_split_max_reduction(t_ps *data, t_chunk *max);

int		ft_get_chunk_value(t_ps *data, t_chunk *chunk, int n);
int		ft_get_max_value(t_ps *data, t_chunk *chunk);

int		ft_move(t_ps *data, t_loc from, t_loc to);

void	set_split_location(t_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max);
void	set_third_piovt(t_loc loc, int current_size, int *piovt_1,
			int *piovt_2);
void	ft_sort_chunk(t_ps *data);

t_op	neutral_op(t_op op);
void	ft_final_optimization(t_ps *data);

#endif