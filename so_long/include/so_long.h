/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:29:07 by meyu              #+#    #+#             */
/*   Updated: 2025/09/01 20:24:31 by xin              ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

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

int		draw_bg(t_game *game);
int		draw_map(t_game *game, int x, int y);
char	**load_maps(const char *path, int *width, int *height, int count);
int		ft_game_init(t_game *game, char *map_path);
void	ft_free_map(char **map, int h);
int		count_coins(char **map, int width, int height);
void	ft_check_char(char c, char **map, int height);
void	ft_check_rectangle(char **map, int y, int width, int height);
void	ft_check_player(char **map, int x, int y, int *player);
void	ft_check_exit(char **map, int x, int y, int *exit);
void	ft_check_coin(char **map, int x, int y, int *coin);
void	collcet_coin(t_game *g, int x, int y);
int		count_coins(char **map, int width, int height);
void	key_hook(mlx_key_data_t keydata, void *param);
void	ft_free_game(t_game *g);
int		ft_check_path(t_map *map, int y, int px, int py);
int		ft_validate_map(char **map, int width, int height);
void	ft_free_game(t_game *g);

#endif