/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:35:19 by meyu              #+#    #+#             */
/*   Updated: 2025/08/29 17:49:57 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	draw_bg(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_image_to_window(game->mlx, game->background, x * 32, y * 32);
			x ++;
		}
		y ++;
	}
	return (1);
}

int	draw_map(t_game *game, int x, int y)
{
	char		character;
	mlx_image_t	*img;
	int			id;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			character = game->map[y][x];
			img = NULL;
			if (character == '1')
				img = game->wall;
			else if (character == 'C')
			{
				id = mlx_image_to_window(game->mlx, game->coin, x * 32, y * 32);
				if (id >= 0)
				{
					game->coins[game->coin_count].x = x;
					game->coins[game->coin_count].y = y;
					game->coins[game->coin_count].coin_id = id;
					game->coin_count++;
				}
			}
			else if (character == 'E')
				img = game->exit;
			if (img)
			{
				mlx_image_to_window(game->mlx, img, x * TILE, y * TILE);
				img->instances[0].enabled = true;
			}
			x++;
		}
		y ++;
	}
	return (1);
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	mlx_image_t	*prev;
	int			dx;
	int			dy;
	int			new_x;
	int			new_y;

	if (keydata.action != MLX_PRESS)
		return ;
	game = (t_game *)param;
	dx = 0;
	dy = 0;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	prev = game->current;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		dx = -1;
		game->current = game->player_left;
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		dx = 1;
		game->current = game->player_right;
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		dy = -1;
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		dy = 1;
	if (prev != game->current)
	{
		if (prev->count > 0)
			prev->instances[0].enabled = false;
		if (game->current->count > 0)
		{
			game->current->instances[0].x = prev->instances[0].x;
			game->current->instances[0].y = prev->instances[0].y;
			game->current->instances[0].enabled = true;
		}
	}
	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_y < 0 || new_x >= game->width || new_y >= game->height
		|| game->map[new_y][new_x] == '1')
		return ;
	game->current->instances[0].x = new_x * TILE;
	game->current->instances[0].y = new_y * TILE;
	game->player_x = new_x;
	game->player_y = new_y;
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		int i = 0;
		while (i < game->coin_count)
		{
			if (game->coins[i].x == new_x && game->coins[i].y == new_y)
			{
				game->coin->instances[game->coins[i].coin_id].enabled = false;
				break ;
			}
			i++;
		}
		game->coin_left--;
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->coin_left == 0)
		{
			printf("You collected all coins! Exiting...\n");
			mlx_close_window(game->mlx);
		}
		else
		{
			printf("You need to collect all coins before exiting!\n");
		}
	}
}

int	ft_init_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				if (mlx_image_to_window(game->mlx, game->player_right, x * 32, y * 32) < 0)
					return (0);
				if (mlx_image_to_window(game->mlx, game->player_left, -100, -100) < 0)
					return (0);
				game->player_left->instances[game->player_left->count - 1].enabled = false;
				game->current = game->player_right;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_game_init(t_game *game, char *map_path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = load_maps(map_path, &game->width, &game->height);
	if (!game->map)
		return (0);
	game->mlx = mlx_init(game->width * 32, game->height * 32, "So_long!", true);
	if (!game->mlx)
		return (0);
	game->tex_bg = mlx_load_png("./assets/images/background.png");
	game->tex_wall = mlx_load_png("./assets/images/wall.png");
	game->tex_coin = mlx_load_png("./assets/images/collect.png");
	game->tex_exit = mlx_load_png("./assets/images/exit.png");
	game->tex_left = mlx_load_png("./assets/images/hollow_knight_left.png");
	game->tex_right = mlx_load_png("./assets/images/hollow_knight_right.png");
	if (!game->tex_bg || !game->tex_wall || !game->tex_coin
		|| !game->tex_exit || !game->tex_left || !game->tex_right)
		return (0);
	game->background = mlx_texture_to_image(game->mlx, game->tex_bg);
	game->wall = mlx_texture_to_image(game->mlx, game->tex_wall);
	game->coin = mlx_texture_to_image(game->mlx, game->tex_coin);
	game->exit = mlx_texture_to_image(game->mlx, game->tex_exit);
	game->player_left = mlx_texture_to_image(game->mlx, game->tex_left);
	game->player_right = mlx_texture_to_image(game->mlx, game->tex_right);
	if (!game->background || !game->wall || !game->coin
		|| !game->exit || !game->player_left || !game->player_right)
		return (0);
	if (!draw_bg(game) || !draw_map(game, 0, 0) || !ft_init_pos(game))
		return (0);
	return (1);
}

static void	ft_free_game(t_game *g)
{
	if (g->mlx)
	{
		if (g->player_left)
			mlx_delete_image(g->mlx, g->player_left);
		if (g->player_right)
			mlx_delete_image(g->mlx, g->player_right);
		if (g->background)
			mlx_delete_image(g->mlx, g->background);
		if (g->wall)
			mlx_delete_image(g->mlx, g->wall);
		if (g->coin)
			mlx_delete_image(g->mlx, g->coin);
		if (g->exit)
			mlx_delete_image(g->mlx, g->exit);
	}
	if (g->tex_bg)
		mlx_delete_texture(g->tex_bg);
	if (g->tex_wall)
		mlx_delete_texture(g->tex_wall);
	if (g->tex_coin)
		mlx_delete_texture(g->tex_coin);
	if (g->tex_exit)
		mlx_delete_texture(g->tex_exit);
	if (g->tex_left)
		mlx_delete_texture(g->tex_left);
	if (g->tex_right)
		mlx_delete_texture(g->tex_right);
	if (g->map)
		ft_free_map(g->map, g->height);
	if (g->mlx)
		mlx_terminate(g->mlx);
}

int	main(void)
{
	t_game	game;

	if (!ft_game_init(&game, "./assets/maps/map.ber"))
	{
		puts("Init failed");
		ft_free_game(&game);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	ft_free_game(&game);
	return (EXIT_SUCCESS);
}
