/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uxX%.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:58:03 by meyu              #+#    #+#             */
/*   Updated: 2025/07/12 19:28:44 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_decimal(unsigned int n)
{
	int		n_len;
	char	digit;
	int		temp;

	n_len = 0;
	if (n >= 10)
	{
		temp = print_unsigned_decimal(n / 10);
		if (temp < 0)
			return (-1);
		n_len += temp;
	}
	digit = (n % 10) + '0';
	if (write(1, &digit, 1) < 0)
		return (-1);
	return (n_len + 1);
}

int	print_hexa_decimal(unsigned int n, int if_uppercase)
{
	int		n_len;
	char	*hexa;
	char	digit_num;
	int		temp;

	n_len = 0;
	if (if_uppercase)
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	if (n >= 16)
	{
		temp = print_hexa_decimal(n / 16, if_uppercase);
		if (temp < 0)
			return (-1);
		n_len += temp;
	}
	digit_num = hexa[n % 16];
	if (write (1, &digit_num, 1) < 0)
		return (-1);
	return (n_len + 1);
}

int	print_percent(void)
{
	if (write(1, "%", 1) < 0)
		return (-1);
	return (1);
}
