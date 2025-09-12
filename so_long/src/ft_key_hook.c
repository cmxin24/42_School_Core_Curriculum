/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:53:45 by xin               #+#    #+#             */
/*   Updated: 2025/09/02 12:22:43 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	switch_facing(mlx_image_t **curr, mlx_image_t *l, mlx_image_t *r)
{
	mlx_image_t	*prev;

	prev = *curr;
	if (prev == l)
		*curr = r;
	else
		*curr = l;
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

static int	get_direction(t_game *g, mlx_key_data_t keydata, int *n_x, int *n_y)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		dx = -1;
		if (g->current != g->player_left)
			switch_facing(&g->current, g->player_left, g->player_right);
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		dx = 1;
		if (g->current != g->player_right)
			switch_facing(&g->current, g->player_left, g->player_right);
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		dy = -1;
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		dy = 1;
	if (dx == 0 && dy == 0)
		return (0);
	*n_x = g->player_x + dx;
	return ((*n_y = g->player_y + dy), 1);
}

static void	ft_handle_coin_and_exit(t_game *g, int new_x, int new_y)
{
	collcet_coin(g, new_x, new_y);
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

static int	move_player(t_game *g, int new_x, int new_y, char **step_num)
{
	char		*step_str;

	if (g->current && g->current->count > 0)
	{
		g->current->instances[0].x = new_x * TILE;
		g->current->instances[0].y = new_y * TILE;
	}
	g->player_x = new_x;
	g->player_y = new_y;
	g->step_count++;
	ft_handle_coin_and_exit(g, new_x, new_y);
	step_str = ft_itoa(g->step_count);
	if (!step_str)
		return (0);
	*step_num = ft_strjoin("The number of moves: ", step_str);
	free(step_str);
	if (!(*step_num))
		return (0);
	return (1);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*g;
	int			new_x;
	int			new_y;
	char		*step_num;

	if (keydata.action != MLX_PRESS)
		return ;
	g = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(g->mlx);
		return ;
	}
	if (!get_direction(g, keydata, &new_x, &new_y))
		return ;
	if (new_x < 0 || new_y < 0 || new_x >= g->width || new_y >= g->height
		|| g->map[new_y][new_x] == '1')
		return ;
	if (!move_player(g, new_x, new_y, &step_num))
		return ;
	mlx_delete_image(g->mlx, g->step_next);
	g->step_next = mlx_put_string(g->mlx, step_num, 10, 10);
	free(step_num);
}
