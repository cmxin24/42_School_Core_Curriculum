/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:09:28 by meyu              #+#    #+#             */
/*   Updated: 2025/08/27 16:04:38 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static inline uint32_t	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

static void	draw_gradient(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			r = (x * 255) / img->width;
			g = (y * 255) / img->height;
			b = 128;
			mlx_put_pixel(img, x, y, rgba(r, g, b, 255));
			x++;
		}
		y++;
	}
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42 - test_2", true);
	if (!mlx)
		return (puts(mlx_strerror(mlx_errno)), EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (puts(mlx_strerror(mlx_errno)), mlx_terminate(mlx), EXIT_FAILURE);
	draw_gradient(img);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		puts(mlx_strerror(mlx_errno));
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
