/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:28:37 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 10:32:29 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

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
int		ft_pop(t_stack *s, int *num);
bool	ft_swap(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
bool	ft_push_to(t_stack *dest, t_stack *src);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
bool	ft_rotate(t_stack *s);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
bool	ft_reverse_rotate(t_stack *s);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_print_error(void);
int		ft_atol(char *s);
int		is_number(char *s);
int		ft_check_duplicates(int *num_array, int lenth);
int		*ft_argv_check(int argc, char *argv[]);

#endif
