/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:38:13 by meyu              #+#    #+#             */
/*   Updated: 2025/09/25 20:16:55 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	//check argc and argv
	if (ft_check_argv(argc, argv) == -1)
		write(2, "Error arguments!\nPlease input: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat](option)\n", 153);
	
	(void)argv;
	//init philos
	//start ativity and print
	//check if need stop
	//clean the memory
	return (0);
}
