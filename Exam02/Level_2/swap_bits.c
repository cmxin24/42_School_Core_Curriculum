/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:22:27 by meyu              #+#    #+#             */
/*   Updated: 2025/08/18 17:52:10 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	int	i;
	unsigned char temp;
	unsigned char result;

	i = 4;
	result = 0;
	temp = octet;
	while (i --)
	{
		temp = temp >> i;
		result = (result << 1) | (temp & 1);
		temp = octet;
	}
	i = 8;
	while (i-- > 4)
	{
		temp = temp >> i;
		result = (result << 1) | (temp & 1);
		temp = octet;
	}
	return (result);
}

// return ((octet >> 4 | octet << 4));