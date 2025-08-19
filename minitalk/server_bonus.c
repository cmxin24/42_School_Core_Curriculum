/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:04:29 by meyu              #+#    #+#             */
/*   Updated: 2025/08/19 19:09:25 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

static void	ft_get_message(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bits;
	pid_t					client_pid;

	(void)context;
	client_pid = info->si_pid;
	c = c << 1;
	if (signum == SIGUSR2)
		c = c | 1;
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			write (1, "\n", 1);
		else
			write (1, &c, 1);
		bits = 0;
		c = 0;
		kill(client_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Meyu's Server is Running.\n");
	ft_printf("Server PID is: %d\n", getpid());
	sig.sa_sigaction = ft_get_message;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
