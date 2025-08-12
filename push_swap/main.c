/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:00:21 by xin               #+#    #+#             */
/*   Updated: 2025/08/12 19:47:59 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	size_t	num_size;
	int		*num_array;
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	if (argc <= 1)
		return (0);
	num_size = argc - 1;
	num_array = ft_argv_check(argc, argv);
	if (!num_array)
		return (0);
	if (!ft_array_to_stack(a, num_array, num_size))
		return (0);
	b->top = NULL;
	ft_push_swap(a, b, num_size);
	free(a);
	free(b);
	return (0);
}
