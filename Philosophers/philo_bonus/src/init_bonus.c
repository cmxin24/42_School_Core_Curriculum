/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:09:48 by xin               #+#    #+#             */
/*   Updated: 2025/10/07 17:20:13 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_init_data(t_data *data, int argc, char **argv)
{
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
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/full");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->philo_nums);
	data->print = sem_open("/print", O_CREAT, 0644, 1);
	data->full = sem_open("/full", O_CREAT, 0644, 1);
	if (data->forks == SEM_FAILED || data->print == SEM_FAILED
		|| data->full == SEM_FAILED)
	{
		perror("sem_open failed");
		exit(EXIT_FAILURE);
	}
	data->start_time = ft_get_time();
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	index = 0;
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	while (*s1)
		str[index++] = *s1++;
	while (*s2)
		str[index++] = *s2++;
	str[index] = '\0';
	return (str);
}

int	ft_init_philos(t_data *data, t_philo **philos)
{
	int		i;
	char	*pos;
	char	*sem_name;

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
		(*philos)[i - 1].data = data;
		pos = ft_itoa(i);
		sem_name = ft_strjoin("/meal_", pos);
		free(pos);
		sem_unlink(sem_name);
		(*philos)[i - 1].meal = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1);
		free(sem_name);
	}
	data->philos = *philos;
	return (0);
}

void	ft_print_action(t_philo *philo, char *action)
{
	long long	time;

	sem_wait(philo->data->print);
	if (!philo->data->dead)
	{
		time = ft_get_time() - philo->data->start_time;
		printf("%lld %d %s\n", time, philo->pos, action);
	}
	sem_post(philo->data->print);
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
