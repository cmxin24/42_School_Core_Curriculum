/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:41:13 by meyu              #+#    #+#             */
/*   Updated: 2025/08/18 14:43:17 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int	main(int argc, int **argv)
{
	if (argc != 4)
	{
		write (1, "\n", 1);
		return (0);
	}
	int	num_1 = atoi(argv[1][1]);
	int	num_2 = atoi(argv[1][3]);
	return (0);
}
