/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pirnt)bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:46:18 by meyu              #+#    #+#             */
/*   Updated: 2025/08/18 16:02:28 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write (1, &bit, 1);
	}
}

int	main(int argc, char **argv)
{
	unsigned char	a = 65;
	print_bits(a);
}
