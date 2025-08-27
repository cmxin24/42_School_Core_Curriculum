/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:35:47 by meyu              #+#    #+#             */
/*   Updated: 2025/08/27 16:11:16 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static inline uint32_t	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		time;
}	t_data;

static void	redraw(t_data *data)
{
	uint32_t	x;
	uint32_t	y;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	mlx_image_t	*img;
	double		v;

	img = data->img;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			v = sin((x + data->time) * 0.05) + cos((y + data->time) * 0.05);
			if (v > 1.0)
				v = 1.0;
			if (v < -1.0)
				v = -1.0;
			r = (uint8_t)((v + 1.0) * 127);
			g = (uint8_t)(255 - r);
			b = 128;
			mlx_put_pixel(img, x, y, rgba(r, g, b, 255));
			x++;
		}
		y++;
	}
}

static void	loop_hook(void *param)
{
	t_data	*data;

	data = (t_data*)param;
	data->time += data->mlx->delta_time * 60.0;
	redraw(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		data;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42 - test_3", true);
	if (!mlx)
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (puts(mlx_strerror(mlx_errno)), mlx_terminate(mlx), EXIT_FAILURE);
	data.mlx = mlx;
	data.img = img;
	data.time = 0.0;
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		puts(mlx_strerror(mlx_errno));
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, loop_hook, &data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
