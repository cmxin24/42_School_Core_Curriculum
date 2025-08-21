/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:04:29 by meyu              #+#    #+#             */
/*   Updated: 2025/08/21 18:12:51 by xin              ###   ########.fr       */
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

static void	ft_get_message(int sig_num, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bits = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (sig_num == SIGUSR2)
		c |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			if (kill(client_pid, SIGUSR2) == -1)
				ft_error(0);
			write (1, "\n", 1);
		}
		else
			write (1, &c, 1);
		bits = 0;
		c = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1)
		ft_error(0);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Meyu's Server is Running.\n");
	ft_printf("Server PID is: %d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_get_message;
	sigemptyset(&sig.sa_mask);
	if (sigaction(SIGUSR1, &sig, NULL) == -1
		|| sigaction(SIGUSR2, &sig, NULL) == -1)
		ft_error(1);
	while (1)
		pause();
	return (0);
}
