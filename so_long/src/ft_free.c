/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:05:50 by xin               #+#    #+#             */
/*   Updated: 2025/09/01 16:07:00 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_mlx(t_game *g)
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
}

void	ft_free_game(t_game *g)
{
	free_mlx(g);
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
