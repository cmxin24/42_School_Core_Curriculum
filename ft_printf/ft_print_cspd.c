/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cspd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:43:21 by xin               #+#    #+#             */
/*   Updated: 2025/07/12 11:43:30 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char(char c)
{
	return (write(1, &c, 1));
}

static int	print_string(const char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

static int	print_pointer_hexa(void *p)
{
	unsigned long	num;
	int				digit_num;
	char			*hexa;
	char			buffer[16];
	int				index;

	num = (unsigned long)p;
	digit_num = 0;
	hexa = "0123456789abcdef";
	digit_num += write (1, "0x", 2);
	if (num == 0)
		digit_num += write (1, "0", 1);
	else
	{
		while (num)
		{
			buffer[index++] = hexa[num % 16];
			num /= 16;
		}
		while (--index >= 0)
			digit_num += write(1, &buffer[index], 1);
	}
	return (digit_num);
}

static int	print_decimal_num(int n)
{
	int				n_len;
	unsigned int	num;
	char			digit;

	n_len = 0;
	if (n < 0)
	{
		n_len += write(1, "-", 1);
		num = -n;
	}
	else
		num = n;
	if (num >= 10)
		n_len += print_decimal_num(num / 10);
	digit = (num % 10) + '0';
	n_len += write(1, &digit, 1);
	return (n_len);
}

