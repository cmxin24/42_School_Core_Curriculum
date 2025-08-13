/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:28:37 by xin               #+#    #+#             */
/*   Updated: 2025/08/13 13:05:58 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>

typedef struct s_node
{
	int				data;
	int				rank;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

bool	ft_push(t_stack *s, int num);
int		ft_pop(t_stack *s, int *num);
bool	ft_swap(t_stack *a);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
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
void	ft_check_duplicates(int *num_array, int lenth);
int		*ft_argv_check(int argc, char **argv);
bool	ft_array_to_stack(t_stack *s, int *num_array, size_t num_size);
bool	ft_sort_three(t_stack *a);
int		ft_find_min(t_stack *a);
void	ft_min_to_top(t_stack *a, size_t num_size);
bool	ft_sort_four(t_stack *a, t_stack *b);
bool	ft_sort_five(t_stack *a, t_stack *b);
bool	ft_push_swap(t_stack *a, t_stack *b, int num_size);
void	quicksort(int *num_array, int left, int right);
void	ft_set_rank(t_stack *a, size_t num_size, int *num_array);
void	ft_push_chunks(t_stack *a, t_stack *b, int chunk_num, int start);
bool	ft_sort_chunk(t_stack *a, t_stack *b, int chunk_num);
void	ft_free_stack(t_stack *s);

#endif
