/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:08:30 by xin               #+#    #+#             */
/*   Updated: 2025/11/19 21:06:06 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_action(philo, "has taken a fork");
	ft_usleep(philo->data, philo->data->time_to_die);
	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->death);
	if (!philo->data->dead)
	{
		printf("%lld %d died\n",
			ft_get_time() - philo->data->start_time, philo->pos);
		philo->data->dead = true;
	}
	pthread_mutex_unlock(&philo->data->death);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_unlock(philo->left_fork);
}

static void	ft_take_forks(t_philo *philo)
{
	if (philo->pos % 2 == 0)
		usleep(100);
	if (philo->pos % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has taken a fork");
	}
}

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal);
	ft_print_action(philo, "is eating");
	ft_usleep(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (philo->data->meal_nums != -1
		&& philo->meals_eaten >= philo->data->meal_nums)
	{
		pthread_mutex_lock(&philo->data->full);
		philo->data->is_full++;
		pthread_mutex_unlock(&philo->data->full);
	}
}

static void	ft_sleep_and_think(t_philo *philo)
{
	ft_print_action(philo, "is sleeping");
	ft_usleep(philo->data, philo->data->time_to_sleep);
	ft_print_action(philo, "is thinking");
}

void	*ft_philo_actions(void *arg)
{
	t_philo	*philo;
	bool	dead;

	philo = (t_philo *)arg;
	if (philo->data->philo_nums == 1)
	{
		ft_handle_one_philo(philo);
		return (NULL);
	}
	pthread_mutex_lock(&philo->data->death);
	dead = philo->data->dead;
	pthread_mutex_unlock(&philo->data->death);
	while (!dead && (philo->data->meal_nums == -1
			|| philo->meals_eaten < philo->data->meal_nums))
	{
		ft_take_forks(philo);
		ft_eat(philo);
		if (philo->data->meal_nums != -1
			&& philo->meals_eaten >= philo->data->meal_nums)
			break ;
		ft_sleep_and_think(philo);
	}
	return (NULL);
}
