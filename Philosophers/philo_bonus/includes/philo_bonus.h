/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:48:57 by meyu              #+#    #+#             */
/*   Updated: 2025/10/07 17:23:55 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <semaphore.h>

typedef struct s_data
{
	int				philo_nums;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				meal_nums;
	bool			dead;
	sem_t			*forks;
	sem_t			*print;
	struct s_philo	*philos;
	long long		start_time;
	int				is_full;
	sem_t			*full;

}	t_data;

typedef struct s_philo
{
	int				pos;
	long long		meals_eaten;
	long long		last_meal;
	sem_t			*meal;
	t_data			*data;
	bool			live;
	pthread_t		thread;
}	t_philo;

char		*ft_itoa(int n);
int			ft_atoi(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_check_argv(int argc, char **argv);
int			ft_init_data(t_data *data, int argc, char **argv);
int			ft_init_philos(t_data *data, t_philo **philos);
int			ft_start_philos(t_data *data);
void		ft_print_action(t_philo *philo, char *action);
void		*ft_philo_actions(void *arg);
long long	ft_get_time(void);
void		ft_usleep(t_data *data, long long ms);
void		*ft_dead_detector(void *arg);
void		ft_clean_memory(t_data *data, t_philo *philos);

#endif