/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:12:00 by xin               #+#    #+#             */
/*   Updated: 2025/09/10 18:42:33 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_stack
{
	int	*rank;
	int	size;
	int	top;
	int	bottom;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	t_list	*opt;
	bool	mandatory_part;
}	t_ps;

typedef enum e_operates
{
	NULL_OP,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
}	t_op;

void	ft_init_data(t_ps *data, int argc, char **argv, bool writing_mode);
void	ft_free_data(t_ps *data);
void	ft_free_split(char **s, size_t size);
void	ft_error(t_ps *data);
bool	ft_is_sorted(t_ps *data);

int		ft_next_up(t_stack *s, int index);
int		ft_next_down(t_stack *s, int index);
int		ft_get_rank(t_stack *s, int n);
t_op	op_from(t_list *node);
int		ft_current_size(t_stack *s);

void	ft_init_stack(t_ps *data, t_stack *s, int size);
bool	ft_set_rank(int *numbers, int *rank, int size);
bool	ft_argv_check(char *argv);
int		ft_check_duplicates(int *num_array, int size, char **argv);
char	**ft_split_argv(int argc, char **argv, int *size);
void	ft_quicksort(int *num_array, int left, int right);
int		ft_find_rank(int *sorted_num, int size, int input_num);
void	ft_add_number_to_stack(t_ps *data, t_stack *s, int size, char **argv);

void	ft_save_operation(t_ps *data, t_op operation);
void	push_a(t_ps *data);
void	push_b(t_ps *data);
void	r_rotate_a(t_ps *data);
void	r_rotate_b(t_ps *data);
void	r_rotate_ab(t_ps *data);
void	rotate_a(t_ps *data);
void	rotate_b(t_ps *data);
void	rotate_ab(t_ps *data);
void	swap_a(t_ps *data);
void	swap_b(t_ps *data);
void	swap_ab(t_ps *data);

void	ft_print_operations(t_list *opt);

#endif
