/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:00:21 by xin               #+#    #+#             */
/*   Updated: 2025/08/13 02:26:31 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	ft_init_stack(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		if (*a)
			free(*a);
		if (*b)
			free(*b);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	size_t	num_size;
	int		*num_array;
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	if (ft_init_stack(&a, &b) == 0)
		return (0);
	num_size = argc - 1;
	num_array = ft_argv_check(argc, argv);
	if (!num_array)
		return (free(a), free(b), 0);
	if (!ft_array_to_stack(a, num_array, num_size))
		return (free(a), free(b), free(num_array), 0);
	b->top = NULL;
	ft_set_rank(a, num_size, num_array);
	ft_push_swap(a, b, num_size);
	ft_free_stack(a);
	ft_free_stack(b);
	return (free(a), free(b), free(num_array), 0);
}
