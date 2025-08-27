/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:29:07 by meyu              #+#    #+#             */
/*   Updated: 2025/08/27 19:28:51 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH  1280
# define HEIGHT 640
# define STEP	32

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/get_next_line/get_next_line.h"

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player_right;
	mlx_image_t	*player_left;
	mlx_image_t	*current;
	char		**map;
	int			width;
	int			height;
	int			collect_set;
	int			collect_count;
	int			step_num;
}	t_game;

#endif