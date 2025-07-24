/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:52:46 by meyu              #+#    #+#             */
/*   Updated: 2025/07/24 16:42:23 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	append_to_buffer(t_buffer *buf, const char *data, size_t len)
{
	if (!expand_buffer(buf, len))
		return (0);
	ft_memmove(buf->data + buf->len, data, len);
	buf->len += len;
	buf->data[buf->len] = '\0';
	return (1);
}

static int	read_chunk_to_buffer(int fd, t_buffer *buf)
{
	char	*temp_buffer;
	ssize_t	bytes_read;
	size_t	total_read;
	size_t	i;
	int		found_newline;

	temp_buffer = malloc(BUFFER_SIZE * 8);
	if (!temp_buffer)
		return (-1);
	total_read = 0;
	found_newline = 0;
	while (total_read < BUFFER_SIZE * 8 && !found_newline)
	{
		bytes_read = read(fd, temp_buffer + total_read, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp_buffer), -1);
		if (bytes_read == 0)
			break ;
		i = total_read;
		while (i < total_read + (size_t)bytes_read && temp_buffer[i] != '\n')
			i++;
		if (i < total_read + (size_t)bytes_read)
			found_newline = 1;
		total_read += bytes_read;
	}
	if (total_read > 0 && !append_to_buffer(buf, temp_buffer, total_read))
		return (free(temp_buffer), -1);
	free(temp_buffer);
	if (total_read > 0)
		return (1);
	return (0);
}

static t_buffer	*read_to_buffer_optimized(int fd, t_buffer *buf)
{
	int	read_result;

	if (!buf)
	{
		buf = init_buffer();
		if (!buf)
			return (NULL);
	}
	if (buf->len > 0 && ft_strchr(buf->data, '\n'))
		return (buf);
	while (1)
	{
		read_result = read_chunk_to_buffer(fd, buf);
		if (read_result == -1)
			return (free_buffer(buf), NULL);
		if (read_result == 0)
			break ;
		if (ft_strchr(buf->data, '\n'))
			break ;
	}
	if (buf->len == 0)
		return (free_buffer(buf), NULL);
	return (buf);
}

static char	*extract_line_from_buffer(t_buffer *buf)
{
	char	*newline_pos;
	char	*line;
	size_t	line_len;
	size_t	remaining_len;

	if (!buf || buf->len == 0)
		return (NULL);
	newline_pos = ft_strchr(buf->data, '\n');
	if (newline_pos)
	{
		line_len = newline_pos - buf->data + 1;
		line = malloc(line_len + 1);
		if (!line)
			return (NULL);
		ft_memmove(line, buf->data, line_len);
		line[line_len] = '\0';
		remaining_len = buf->len - line_len;
		if (remaining_len > 0)
			ft_memmove(buf->data, buf->data + line_len, remaining_len);
		buf->len = remaining_len;
		buf->data[buf->len] = '\0';
	}
	else
	{
		line = malloc(buf->len + 1);
		if (!line)
			return (NULL);
		ft_memmove(line, buf->data, buf->len);
		line[buf->len] = '\0';
		buf->len = 0;
		buf->data[0] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	*buffer = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
		{
			free_buffer(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_to_buffer_optimized(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line_from_buffer(buffer);
	if (!line)
		return (free_buffer(buffer), buffer = NULL, NULL);
	if (buffer->len == 0)
	{
		free_buffer(buffer);
		buffer = NULL;
	}
	return (line);
}
