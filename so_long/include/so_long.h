/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:29:07 by meyu              #+#    #+#             */
/*   Updated: 2025/09/01 10:50:23 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define STEP	32
# define TILE	32

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"
# include "../lib/includes/get_next_line.h"

char	**load_maps(const char *path, int *width, int *height);
void	ft_free_map(char **map, int h);
int		count_coins(char **map, int width, int height);

typedef struct s_coin
{
	int		x;
	int		y;
	int		coin_id;
	bool	collected;
}	t_coin;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	*tex_left;
	mlx_texture_t	*tex_right;
	mlx_image_t		*player_left;
	mlx_image_t		*player_right;
	mlx_image_t		*current;
	mlx_texture_t	*tex_bg;
	mlx_image_t		*background;
	mlx_texture_t	*tex_wall;
	mlx_image_t		*wall;
	mlx_texture_t	*tex_coin;
	mlx_image_t		*coin;
	mlx_texture_t	*tex_exit;
	mlx_image_t		*exit;
	char			**map;
	int				width;
	int				height;
	int				step_count;
	int				player_x;
	int				player_y;
	t_coin			*coins;
	int				coin_left;
	int				coin_count;
}	t_game;


#endif