/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:29:38 by meyu              #+#    #+#             */
/*   Updated: 2025/08/26 20:04:31 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
}	t_data;

static inline uint32_t	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

static void	draw_checker(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	bool		on;

	x = 0;
	y = 0;
	while (++y < img->height)
	{
		while (++x < img->width)
		{
			on = ((x / 8) | (y / 8) & 1);
			if (on)
				mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			else
				mlx_put_pixel(img, x, y, 0x000000FF);
		}
	}
}

static void	loop_hook(void *param)
{
	t_data		*data;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			dx;
	int			dy;

	data = (t_data *)param;
	mlx = data->mlx;
	img = data->img;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		return ;
	}
	dx = 0;
	dy = 0;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		dx = -2;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		dx = +2;
	if (mlx_is_key_down(mlx, MLX_KEY_UP)	|| mlx_is_key_down(mlx, MLX_KEY_W))
		dy = -2;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN)	|| mlx_is_key_down(mlx, MLX_KEY_S))
		dy = +2;
	img->instances[0].x += dx;
	img->instances[0].y += dy;
}




