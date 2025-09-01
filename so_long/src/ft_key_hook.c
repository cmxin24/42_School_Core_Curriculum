/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:53:45 by xin               #+#    #+#             */
/*   Updated: 2025/09/01 16:07:54 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	switch_facing(mlx_image_t **curr, mlx_image_t *left, mlx_image_t *right)
{
	mlx_image_t	*prev;

	prev = *curr;
	if (prev == left)
		*curr = right;
	else
		*curr = left;
	if (prev && (*curr) && prev != *curr)
	{
		if (prev->count > 0)
			prev->instances[0].enabled = false;
		if ((*curr)->count > 0)
		{
			(*curr)->instances[0].x = prev->instances[0].x;
			(*curr)->instances[0].y = prev->instances[0].y;
			(*curr)->instances[0].enabled = true;
		}
	}
}

static void	get_direction(t_game *g, mlx_key_data_t keydata, int *dx, int *dy)
{
	*dx = 0;
	*dy = 0;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		*dx = -1;
		if (g->current != g->player_left)
			switch_facing(&g->current, g->player_left, g->player_right);
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		*dx = 1;
		if (g->current != g->player_right)
			switch_facing(&g->current, g->player_left, g->player_right);
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		*dy = -1;
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		*dy = 1;
}

static void	move_player(t_game *g, int new_x, int new_y)
{
	if (g->current && g->current->count > 0)
	{
		g->current->instances[0].x = new_x * TILE;
		g->current->instances[0].y = new_y * TILE;
	}
	g->player_x = new_x;
	g->player_y = new_y;
}

static void	ft_handle_exit(t_game *g, int new_x, int new_y)
{
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->coin_left == 0)
		{
			printf("You collected all coins! Exiting...\n");
			mlx_close_window(g->mlx);
		}
		else
			printf("You need to collect all coins before exiting!\n");
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*g;
	int			dx;
	int			dy;
	int			new_x;
	int			new_y;

	if (keydata.action != MLX_PRESS)
		return ;
	g = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(g->mlx);
		return ;
	}
	get_direction(g, keydata, &dx, &dy);
	if (dx == 0 && dy == 0)
		return ;
	new_x = g->player_x + dx;
	new_y = g->player_y + dy;
	if (new_x < 0 || new_y < 0 || new_x >= g->width || new_y >= g->height
		|| g->map[new_y][new_x] == '1')
		return ;
	move_player(g, new_x, new_y);
	collcet_coin(g, new_x, new_y);
	ft_handle_exit(g, new_x, new_y);
}
