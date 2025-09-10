/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:31:47 by meyu              #+#    #+#             */
/*   Updated: 2025/08/12 15:13:42 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	write_unsigned_decimal(unsigned int n)
{
	char	digit;
	int		len;
	int		tmp;

	len = 0;
	if (n >= 10)
	{
		tmp = write_unsigned_decimal(n / 10);
		if (tmp < 0)
			return (-1);
		len += tmp;
	}
	digit = (n % 10) + '0';
	if (write(1, &digit, 1) < 0)
		return (-1);
	return (len + 1);
}

int	print_decimal_num(int n)
{
	int				len;
	unsigned int	num;
	int				temp;

	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		len++;
		num = -n;
	}
	else
		num = n;
	temp = write_unsigned_decimal(num);
	if (temp < 0)
		return (-1);
	return (len + temp);
}
