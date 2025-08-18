/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bitsc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:11:19 by meyu              #+#    #+#             */
/*   Updated: 2025/08/18 17:21:21 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned char	result;

	i = 4;
	result = 0;
	while (i--)
	{
		result = (result << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (result);
}

