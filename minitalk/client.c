/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:50:52 by meyu              #+#    #+#             */
/*   Updated: 2025/08/19 18:23:41 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	ft_send_message(pid_t	pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
	}
	usleep(500);
}

int	main(int argc, char **argv)
{
	char	*message;
	pid_t	pid;
	size_t	index;

	if (argc != 3)
	{
		write(2, "Please Use: ./client <PID> <Messages>\n", 37);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (write(2, "Please check the PID.\n", 22), 1);
	message = argv[2];
	index = 0;
	while (index < ft_strlen(message))
	{
		ft_send_message(pid, message[index]);
		index++;
	}
	ft_send_message(pid, '\0');
	return (0);
}
