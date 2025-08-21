/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:50:52 by meyu              #+#    #+#             */
/*   Updated: 2025/08/21 18:21:02 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	ft_error(int i)
{
	if (i == 0)
	{
		write(1, "Kill Error!\n", 12);
		exit(1);
	}
	if (i == 1)
	{
		write(1, "Sigaction Error!\n", 17);
		exit(1);
	}
}

void	ft_send_terminator(pid_t	pid)
{
	static int	i = 0;

	if (i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error(0);
		i++;
	}
}

void	ft_send_message(pid_t	pid, char *str)
{
	static int	bit = 0;
	static char	*str_cpy = 0;

	if (str)
		str_cpy = str;
	if (*str_cpy)
	{
		if ((((unsigned char)*str_cpy >> bit) & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(0);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				ft_error(0);
		bit++;
		if (bit == 8)
		{
			str_cpy++;
			bit = 0;
		}
	}
	else
		ft_send_terminator(pid);
}

void	ft_receive(int sig, siginfo_t *info, void *context)
{
	static pid_t	pid;

	(void)context;
	if (info->si_pid != 0)
		pid = info->si_pid;
	if (sig == SIGUSR1)
	{
		ft_send_message(pid, NULL);
	}
	if (sig == SIGUSR2)
	{
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	if (argc != 3)
	{
		write(2, "Please Use: ./client <PID> <Messages>\n", 37);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (write(2, "Please check the PID.\n", 22), 1);
	sig.sa_sigaction = ft_receive;
	if (sigaction(SIGUSR1, &sig, NULL) == -1
		|| sigaction(SIGUSR2, &sig, NULL) == -1)
		ft_error(1);
	ft_send_message(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
