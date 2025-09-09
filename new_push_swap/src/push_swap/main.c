/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:11:01 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 17:11:35 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	data;

	if (argc < 2)
		ft_putendl_fd("Please use: ./push_swap <your numbers\
			 separate by " ">", 2);
	ft_init_data(&data, argc, argv, true);
	ft_sort_stack(&data);
	ft_final_optimization(&data);
	ft_print_operations(data.opt);
	ft_free_data(&data);
	exit(EXIT_SUCCESS);
}
