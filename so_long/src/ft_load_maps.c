/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:57:36 by xin               #+#    #+#             */
/*   Updated: 2025/08/29 12:38:27 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**load_maps(const char *path, int *width, int height, int fd)
{
	char 	*buffer;
	char 	*line;
	char 	**map;
	size_t	len;
	ssize_t	bytes;

	map = NULL;
	len = 0;
	fd = open(path, O_RDONLY);
		if (fd < 0)
			return (NULL);
	buffer = malloc (10000);
	if (!buffer)
		return (NULL);
	bytes = read (fd, buffer, 9999);
	close (fd);
	if (bytes <= 0)
		return (free(buffer), NULL);
	buffer[bytes] = '\0';
	
	// TODO
	get_next_line;

}

