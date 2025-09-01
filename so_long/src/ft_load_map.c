/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:57:36 by xin               #+#    #+#             */
/*   Updated: 2025/08/29 21:57:34 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_coins(char **map, int width, int height)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	ft_free_map(char **map, int h)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < h)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**ft_add_lines(char **map, int count, char *line)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (count + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[count] = ft_strdup(line);
	new_map[count + 1] = NULL;
	if (map)
		free(map);
	return (new_map);
}

char	**load_maps(const char *path, int *width, int *height)
{
	int		fd;
	char	*line;
	char	**map;
	int		count;

	fd = open (path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		char *newline = strchr(line, '\n');
        if (newline)
			*newline = '\0';
		map = ft_add_lines(map, count, line);
		free(line);
		count ++;
		line = get_next_line(fd);
	}
	close(fd);
	if (count == 0)
		return (NULL);
	*width = ft_strlen(map[0]);
	*height = count;
	return (map);
}

