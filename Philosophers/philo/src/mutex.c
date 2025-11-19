/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:11:46 by xin               #+#    #+#             */
/*   Updated: 2025/11/19 21:15:31 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_dead(t_data *data)
{
	bool	d;

	pthread_mutex_lock(&data->death);
	d = data->dead;
	pthread_mutex_unlock(&data->death);
	return (d);
}

long long	get_meals_eaten(t_philo *philo)
{
	long long	meals;

	pthread_mutex_lock(&philo->meal);
	meals = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meal);
	return (meals);
}
