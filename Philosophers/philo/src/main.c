/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:38:13 by meyu              #+#    #+#             */
/*   Updated: 2025/10/02 16:29:58 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (ft_check_argv(argc, argv) == -1)
	{
		printf("Error arguments!\nPlease input: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat](option)\n");
		return (1);
	}
	if (ft_init_data(&data, argc, argv) == -1)
		return (1);
	data.start_time = ft_get_time();
	if (ft_init_philos(&data, &philos) == -1)
		return (1);
	if (ft_start_philos(&data) == -1)
		return (1);
	ft_clean_memory(&data, philos);
	return (0);
}
