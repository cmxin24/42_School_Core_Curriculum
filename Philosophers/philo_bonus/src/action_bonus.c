/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:08:30 by xin               #+#    #+#             */
/*   Updated: 2025/10/07 17:26:31 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_is_full(t_philo	*philo)
{
	if (philo->data->meal_nums != -1 && philo->meals_eaten
		>= philo->data->meal_nums)
	{
		sem_wait(philo->data->full);
		philo->data->is_full++;
		sem_post(philo->data->full);
	}
}

void	*ft_philo_actions(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->dead && (philo->data->meal_nums == -1
			|| philo->meals_eaten < philo->data->meal_nums))
	{
		if (philo->pos % 2 == 0)
			usleep(1000);
		sem_wait(philo->data->forks);
		ft_print_action(philo, "has taken a fork");
		sem_wait(philo->data->forks);
		ft_print_action(philo, "has taken a fork");
		philo->last_meal = ft_get_time();
		ft_print_action(philo, "is eating");
		ft_usleep(philo->data, philo->data->time_to_eat);
		philo->meals_eaten++;
		ft_is_full(philo);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		ft_print_action(philo, "is sleeping");
		ft_usleep(philo->data, philo->data->time_to_sleep);
		ft_print_action(philo, "is thinking");
	}
	return (NULL);
}

static int	ft_number_len(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	generate_str(char *str, long m, int len)
{
	if (m == 0)
		str[0] = '0';
	while (m > 0)
	{
		str[--len] = (m % 10) + '0';
		m /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	m;
	int		sign;
	char	*str;
	int		len;

	m = n;
	sign = (m < 0);
	if (sign)
		m = -m;
	len = ft_number_len(m);
	str = (char *)malloc(len + sign + 1);
	if (!str)
		return (NULL);
	str[len + sign] = '\0';
	if (sign)
		str[0] = '-';
	generate_str(str + sign, m, len);
	return (str);
}
