/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:09:48 by xin               #+#    #+#             */
/*   Updated: 2025/10/02 17:11:48 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_data(t_data *data, int argc, char **argv)
{
	int	i;

	data->philo_nums = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meal_nums = ft_atoi(argv[5]);
	else
		data->meal_nums = -1;
	data->dead = false;
	data->is_full = 0;
	data->forks = malloc (data->philo_nums * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (-1);
	i = 0;
	while (i++ < data->philo_nums)
		pthread_mutex_init(&data->forks[i - 1], NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->full, NULL);
	data->start_time = ft_get_time();
	return (0);
}

int	ft_init_philos(t_data *data, t_philo **philos)
{
	int	i;

	*philos = malloc (data->philo_nums * sizeof(t_philo));
	if (!*philos)
		return (-1);
	i = 0;
	while (i++ < data->philo_nums)
	{
		(*philos)[i - 1].pos = i;
		(*philos)[i - 1].live = true;
		(*philos)[i - 1].meals_eaten = 0;
		(*philos)[i - 1].last_meal = data->start_time;
		(*philos)[i - 1].left_fork = &data->forks[i - 1];
		(*philos)[i - 1].right_fork = &data->forks[i % data->philo_nums];
		(*philos)[i - 1].data = data;
		pthread_mutex_init(&(*philos)[i - 1].meal, NULL);
	}
	data->philos = *philos;
	return (0);
}

void	ft_print_action(t_philo *philo, char *action)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print);
	if (!philo->data->dead)
	{
		time = ft_get_time() - philo->data->start_time;
		printf("%lld %d %s\n", time, philo->pos, action);
	}
	pthread_mutex_unlock(&philo->data->print);
}

int	ft_start_philos(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	if (pthread_create(&monitor, NULL, ft_dead_detector, data) != 0)
		return (-1);
	while (i < data->philo_nums)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				ft_philo_actions, &data->philos[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data->philo_nums)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	return (0);
}
