/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:35:19 by meyu              #+#    #+#             */
/*   Updated: 2025/08/29 12:38:26 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



void	*draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height * TILE)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_image_to_window(game->mlx, game->background, x, y);
			x += TILE;
		}
		y += TILE;
	}
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	char	character;

	y = 0;
	while (y < game->height * TILE)
	{
		x = 0;
		while (x < game->width)
		{
			character = game->map[y][x];
			if (character == '1')
				mlx_image_to_window(game->mlx, game->wall, x * TILE, y * TILE);
			else if (character == 'C')
				mlx_image_to_window(game->mlx, game->coin, x * TILE, y * TILE);
			else if (character == 'E')
				mlx_image_to_window(game->mlx, game->exit, x * TILE, y * TILE);
		}
		y += TILE;
	}
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	mlx_image_t	*prev;
	int			dx;
	int			dy;

	game = (t_game *)param;
	dx = 0;
	dy = 0;
	prev = game->current;

	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		{
			dx = -STEP;
			game->current = game->player_left;
		}
		else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		{
			dx = STEP;
			game->current = game->player_right;
		}
		else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			dy = -STEP;
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			dy = STEP;
		if (prev != game->current)
		{
			prev->instances[0].enabled = false;
			game->current->instances[0].x = prev->instances[0].x;
			game->current->instances[0].y = prev->instances[0].y;
			game->current->instances[0].enabled = true;
		}
		game->current->instances[0].x += dx;
		game->current->instances[0].y += dy;
	}
}

int	ft_game_init(t_game *game, char *map_path)
{
	game->map = load_map(map_path, &game->width, &game->height);
	if (!game->map)
		return (EXIT_FAILURE);
	game->mlx = mlx_init(game->width, game->height, "So_long!", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->tex_bg = mlx_load_png("./assets/images/background.png");
	game->tex_wall = mlx_load_png("./assets/images/wall.png");
	game->tex_collcetion = mlx_load_png("./assets/images/collect.png");
	game->tex_exit = mlx_load_png("./assets/images/exit.png");
	game->tex_left = mlx_load_png("./assets/images/hollow_knight_left.png");
	game->tex_right = mlx_load_png("./assets/images/hollow_knight_right.png");
	if (!game->tex_bg || !game->tex_wall || !game->tex_collcetion
		|| !game->tex_exit || !game->tex_left || !game->tex_right)
		return (EXIT_FAILURE);
	game->background = mlx_texture_to_image(game->mlx, game->tex_bg);
	game->wall = mlx_texture_to_image(game->mlx, game->tex_wall);
	game->collection = mlx_texture_to_image(game->mlx, game->tex_collcetion);
	game->exit = mlx_texture_to_image(game->mlx, game->tex_exit);
	game->player_left = mlx_texture_to_image(game->mlx, game->tex_left);
	game->player_right = mlx_texture_to_image(game->mlx, game->tex_right);
	if (!game->background || !game->wall || !game->collection
		|| !game->exit || !game->player_left || !game->player_right)
		return (EXIT_FAILURE);
	draw_background(game);
	draw_map(game);
	
}

int	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*tex_l;
	mlx_texture_t	*tex_r;
	mlx_image_t		*player_l;
	mlx_image_t		*player_r;
	t_game			game;
	mlx_texture_t	*tex_bg;

	mlx = mlx_init(WIDTH, HEIGHT, "So_Long!", true);
	if (!mlx)
		return (EXIT_FAILURE);
	game.mlx = mlx;
	tex_bg = mlx_load_png("./assets/images/background.png");
	game.background = draw_background(mlx, tex_bg);
	if (!game.background)
		return (mlx_terminate(mlx), EXIT_FAILURE);
	tex_l = mlx_load_png("./assets/images/hollow_knight_left.png");
	tex_r = mlx_load_png("./assets/images/hollow_knight_right.png");
	if (!tex_l || !tex_r)
	{
		puts("Failed to load player images");
		if (tex_l)
			mlx_delete_texture(tex_l);
		if (tex_r)
			mlx_delete_texture(tex_r);
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	player_l = mlx_texture_to_image(mlx, tex_l);
	player_r = mlx_texture_to_image(mlx, tex_r);
	if (!player_l || !player_r)
	{
		puts("Failed to convert textures to images");
		if (player_l)
			mlx_delete_image(mlx, player_l);
		if (player_r)
			mlx_delete_image(mlx, player_r);
		mlx_delete_texture(tex_r);
		mlx_delete_texture(tex_l);
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, player_l, WIDTH / 2, HEIGHT / 2) < 0
		|| mlx_image_to_window(mlx, player_r, WIDTH / 2, HEIGHT / 2) < 0)
	{
		puts("Failed to place images in window");
		mlx_delete_image(mlx, player_l);
		mlx_delete_image(mlx, player_r);
		mlx_delete_texture(tex_r);
		mlx_delete_texture(tex_l);
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	player_l->instances[0].enabled = false;
	game.tex_right = tex_r;
	game.tex_left = tex_l;
	game.player_left = player_l;
	game.player_right = player_r;
	game.current = player_r;
	mlx_key_hook(mlx, key_hook, &game);
	mlx_loop(mlx);
	mlx_delete_image(mlx, player_l);
	mlx_delete_image(mlx, player_r);
	mlx_delete_image(mlx, game.background);
	mlx_delete_texture(tex_bg);
	mlx_delete_texture(tex_r);
	mlx_delete_texture(tex_l);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
