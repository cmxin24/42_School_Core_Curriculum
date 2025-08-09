/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:28:37 by xin               #+#    #+#             */
/*   Updated: 2025/08/09 11:08:11 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	t_node	*top;
}	t_stack;

void	ft_push(t_stack *s, int num);
int	ft_pop(t_stack *s, int *num);
bool	ft_swap(t_stack *a);
bool	ft_push_ab(t_stack *a, t_stack *b);
bool	ft_rotate(t_stack *a);
bool	ft_reverse(t_stack *a, t_stack *b);
bool	ft_reverse_rotate(t_stack *a);

#endif
