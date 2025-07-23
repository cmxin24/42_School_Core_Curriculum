/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:52:46 by meyu              #+#    #+#             */
/*   Updated: 2025/07/23 19:41:18 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append_buffer(char *s1, const char *s2, size_t s2_len)
{
	size_t	len1 = s1 ? ft_strlen(s1) : 0;
	char	*new_str;

	new_str = realloc(s1, len1 + s2_len + 1);
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	memcpy(new_str + len1, s2, s2_len);
	new_str[len1 + s2_len] = '\0';
	return (new_str);
}

static char	*read_to_buffer(int fd, char *temp)
{
	char	*buffer;
	ssize_t	content_len;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(temp), NULL);
	content_len = 1;
	while ((!temp || !ft_strchr(temp, '\n')) && content_len > 0)
	{
		content_len = read(fd, buffer, BUFFER_SIZE);
		if (content_len == -1)
			return (free(buffer), free(temp), NULL);
		if (content_len == 0)
			break ;
		buffer[content_len] = '\0';
		temp = ft_append_buffer(temp, buffer, content_len);
		if (!temp)
			return (free(buffer), NULL);
	}
	free(buffer);
	if (temp && temp[0] == '\0')
		return (free(temp), NULL);
	return (temp);
}

static char	*delete_one_line(char *temp)
{
	char	*rest_temp;
	char	*end_of_line;

	if (!temp)
		return (NULL);
	end_of_line = ft_strchr(temp, '\n');
	if (!end_of_line)
	{
		free(temp);
		return (NULL);
	}
	rest_temp = ft_strdup(end_of_line + 1);
	free(temp);
	return (rest_temp);
}

char	*get_next_line(int fd)
{
	static char	*temp = NULL;
	char		*line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(temp), temp = NULL, NULL);

	temp = read_to_buffer(fd, temp);
	if (!temp)
		return (NULL);

	if (!ft_strchr(temp, '\n'))
	{
		if (temp[0] == '\0')
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		line = ft_strdup(temp);
		free(temp);
		temp = NULL;
		return (line);
	}

	len = 0;
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		len++;

	line = ft_substr(temp, 0, len);
	if (!line)
		return (free(temp), temp = NULL, NULL);
	temp = delete_one_line(temp);
	return (line);
}
