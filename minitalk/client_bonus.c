/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:50:52 by meyu              #+#    #+#             */
/*   Updated: 2025/08/19 19:32:35 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

static volatile int	g_ack = 0;

void	ack_handler(int signum)
{
	(void)signum;
	g_ack = 1;
}

void	ft_send_message(pid_t	pid, char c)
{
	int	i;

	g_ack = 0;
	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
	}
	while (!g_ack)
		pause();
}

int	main(int argc, char **argv)
{
	char				*message;
	pid_t				pid;
	size_t				index;
	struct sigaction	sig;

	if (argc != 3)
	{
		write(2, "Please Use: ./client <PID> <Messages>\n", 37);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (write(2, "Please check the PID.\n", 22), 1);
	message = argv[2];
	sig.sa_handler = ack_handler;
	sig.sa_flags = 0;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR2, &sig, NULL);
	index = 0;
	while (index < ft_strlen(message))
	{
		ft_send_message(pid, message[index]);
		index++;
	}
	ft_send_message(pid, '\0');
}
