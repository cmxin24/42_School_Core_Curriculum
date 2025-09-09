/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:43:21 by xin               #+#    #+#             */
/*   Updated: 2025/08/12 15:13:42 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_char(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	print_string(const char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	if (write(1, s, len) < 0)
		return (-1);
	return (len);
}

static int	ft_write_hexa(unsigned long num, const char *hexa, int digit_num)
{
	char			buffer[16];
	int				index;

	index = 0;
	while (num)
	{
		buffer[index++] = hexa[num % 16];
		num /= 16;
	}
	while (--index >= 0)
	{
		if (write(1, &buffer[index], 1) < 0)
			return (-1);
		else
			digit_num ++;
	}
	return (digit_num);
}

int	print_pointer_hexa(void *p)
{
	unsigned long	num;
	int				digit_num;
	const char		*hexa;

	num = (unsigned long)p;
	digit_num = 0;
	hexa = "0123456789abcdef";
	if (num == 0)
	{
		if (write(1, NULL_POINTER_STR, NULL_POINTER_LEN) < 0)
			return (-1);
		return (NULL_POINTER_LEN);
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	digit_num += 2;
	digit_num = ft_write_hexa(num, hexa, digit_num);
	return (digit_num);
}
