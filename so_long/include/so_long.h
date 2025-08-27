/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:29:07 by meyu              #+#    #+#             */
/*   Updated: 2025/08/28 00:55:08 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH  640
# define HEIGHT 320
# define STEP	32
# define TILE	32

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/get_next_line/get_next_line.h"

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	*tex_left;
	mlx_texture_t	*tex_right;
	mlx_texture_t	*tex_bg;
	mlx_image_t		*player_left;
	mlx_image_t		*player_right;
	mlx_image_t		*current;
	mlx_image_t		*background;
	char			**map;
	int				width;
	int				height;
	int				collect_set;
	int				collect_count;
	int				step_num;
}	t_game;

#endif