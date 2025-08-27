/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:35:19 by meyu              #+#    #+#             */
/*   Updated: 2025/08/28 01:01:04 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*draw_background(mlx_t *mlx, mlx_texture_t *tex_bg)
{
	mlx_image_t		*background;
	int				x;
	int				y;

	background = mlx_texture_to_image(mlx, tex_bg);
	if (!background)
	{
		puts("Failed to convert background texture");
		mlx_delete_texture(tex_bg);
		return (NULL);
	}
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_image_to_window(mlx, background, x, y);
			x += TILE;
		}
		y += TILE;
	}
	return (background);
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
