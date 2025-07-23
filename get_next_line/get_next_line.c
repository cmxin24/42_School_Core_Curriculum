/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:52:46 by meyu              #+#    #+#             */
/*   Updated: 2025/07/23 12:12:56 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst || !src)
		return (NULL);
	if (n == 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

static char	*read_to_buffer(int fd, char *temp)
{
	char	*buffer;
	ssize_t	content_len;
	char	*joined_temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	content_len = 1;
	while ((temp == NULL || !ft_strchr(temp, '\n')) && content_len > 0)
	{
		content_len = read(fd, buffer, BUFFER_SIZE);
		if (content_len == -1)
		{
			free(buffer);
			if (temp)
			{
				free(temp);
				temp = NULL;
			}
			return (NULL);
		}
		if (content_len == 0)
			break ;
		buffer[content_len] = '\0';
		joined_temp = ft_strjoin(temp, buffer);
		if (!joined_temp)
		{
			free(buffer);
			return (NULL);
		}
		if (temp)
			free(temp);
		temp = joined_temp;
	}
	free(buffer);
	if (temp && temp[0] == '\0')
	{
		free(temp);
		return (NULL);
	}
	return (temp);
}

static char	*delete_one_line(char *temp)
{
	char	*rest_temp;
	char	*end_of_line;

	end_of_line = ft_strchr(temp, '\n');
	if (!end_of_line)
	{
		free(temp);
		return (NULL);
	}
	rest_temp = ft_strdup(end_of_line +1);
	free(temp);
	return (rest_temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_to_buffer(fd, temp);
	if (!temp)
		return (NULL);
	len = 0;
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		len++;
	line = ft_substr(temp, 0, len);
	if (!line)
	{
		free(temp);
		return (NULL);
	}
	temp = delete_one_line(temp);
	if (line[0] == '\0' && temp == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
