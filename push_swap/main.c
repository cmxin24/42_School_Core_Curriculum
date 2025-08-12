/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:00:21 by xin               #+#    #+#             */
/*   Updated: 2025/08/10 12:44:39 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	size_t	num_size;
	int		*num_array;
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	num_size = argc - 1;
	num_array = ft_argv_check(argc, **argv);
	if (!num_array)
		return (0);
	ft_array_to_stack(a, num_array, num_size);
	b->top = NULL;
	ft_push_swap(a, num_size);
	return (0);
}
