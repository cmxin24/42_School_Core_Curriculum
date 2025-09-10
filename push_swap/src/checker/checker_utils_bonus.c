/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:01:48 by xin               #+#    #+#             */
/*   Updated: 2025/09/09 20:05:21 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

static int	read_char_line(int fd, char *buf)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 4)
	{
		ret = read(fd, &buf[i], 1);
		if (ret <= 0)
			break ;
		if (buf[i] == '\n')
			break ;
		i++;
	}
	buf[i] = '\0';
	if (ret == 0 && i == 0)
		return (-1);
	return (i);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buf[5];
	int		len;
	int		i;

	line = malloc(5);
	if (!line)
		return (NULL);
	len = read_char_line(fd, buf);
	if (len == -1)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
