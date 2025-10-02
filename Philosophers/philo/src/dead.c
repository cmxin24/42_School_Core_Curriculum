/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:14:06 by xin               #+#    #+#             */
/*   Updated: 2025/10/02 17:18:44 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(t_data *data, long long ms)
{
	long long	start;

	start = ft_get_time();
	while (!data->dead && (ft_get_time() - start) < ms)
		usleep(500);
}

static int	ft_all_full(t_data *data)
{
	int	full;

	pthread_mutex_lock(&data->full);
	full = (data->meal_nums != -1 && data->is_full >= data->philo_nums);
	pthread_mutex_unlock(&data->full);
	return (full);
}

static int	ft_check_death(t_data *data, int i)
{
	long long	now;

	pthread_mutex_lock(&data->philos[i].meal);
	if (data->meal_nums == -1 || data->philos[i].meals_eaten < data->meal_nums)
	{
		now = ft_get_time();
		if (now - data->philos[i].last_meal > data->time_to_die)
		{
			pthread_mutex_unlock(&data->philos[i].meal);
			pthread_mutex_lock(&data->print);
			if (!data->dead)
			{
				printf("%lld %d died\n",
					now - data->start_time, data->philos[i].pos);
				data->dead = true;
			}
			pthread_mutex_unlock(&data->print);
			return (1);
		}
	}
	pthread_mutex_unlock(&data->philos[i].meal);
	return (0);
}

void	*ft_dead_detector(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		if (ft_all_full(data))
			return (NULL);
		i = 0;
		while (i < data->philo_nums)
		{
			if (ft_check_death(data, i))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	ft_clean_memory(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->philo_nums)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&philos[i].meal);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->full);
	free(data->forks);
	free(philos);
}
