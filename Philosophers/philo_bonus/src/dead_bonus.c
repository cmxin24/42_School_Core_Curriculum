/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:14:06 by xin               #+#    #+#             */
/*   Updated: 2025/10/07 17:24:08 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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

	sem_wait(data->full);
	full = (data->meal_nums != -1 && data->is_full >= data->philo_nums);
	sem_post(data->full);
	return (full);
}

static int	ft_check_death(t_data *data, int i)
{
	long long	now;

	sem_wait(data->philos[i].meal);
	if (data->meal_nums == -1 || data->philos[i].meals_eaten < data->meal_nums)
	{
		now = ft_get_time();
		if (now - data->philos[i].last_meal > data->time_to_die)
		{
			sem_post(data->philos[i].meal);
			sem_wait(data->print);
			if (!data->dead)
			{
				printf("%lld %d died\n",
					now - data->start_time, data->philos[i].pos);
				data->dead = true;
			}
			sem_post(data->print);
			return (1);
		}
	}
	sem_post(data->philos[i].meal);
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
	int		i;
	char	*pos;
	char	*sem_name;

	i = 0;
	while (i < data->philo_nums)
	{
		sem_close(philos[i].meal);
		pos = ft_itoa(philos[i].pos);
		sem_name = ft_strjoin("/meal_", pos);
		free(pos);
		sem_unlink(sem_name);
		free(sem_name);
		i++;
	}
	sem_close(data->print);
	sem_close(data->full);
	sem_close(data->forks);
	free(philos);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/full");
}
