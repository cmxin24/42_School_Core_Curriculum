/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:44:11 by meyu              #+#    #+#             */
/*   Updated: 2025/08/12 15:24:05 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_format(const char *format, int index, int *len, va_list args)
{
	int	result;

	result = 0;
	if (format[index] == 'c')
		result = print_char(va_arg(args, int));
	else if (format[index] == 's')
		result = print_string(va_arg(args, char *));
	else if (format[index] == 'p')
		result = print_pointer_hexa(va_arg(args, void *));
	else if (format[index] == 'd' || format[index] == 'i')
		result = print_decimal_num(va_arg(args, int));
	else if (format[index] == 'u')
		result = print_unsigned_decimal(va_arg(args, unsigned int));
	else if (format[index] == 'x')
		result = print_hexa_decimal(va_arg(args, unsigned int), 0);
	else if (format[index] == 'X')
		result = print_hexa_decimal(va_arg(args, unsigned int), 1);
	else if (format[index] == '%')
		result = print_percent();
	else
		return (-1);
	if (result < 0)
		return (-1);
	*len += result;
	return (1);
}

static int	ft_process(const char *format, int *len, va_list args)
{
	int		index;
	int		if_error;

	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			if (!format[index])
				return (-1);
			if_error = ft_format(format, index, len, args);
			if (if_error == -1)
				return (-1);
			index++;
		}
		else
		{
			if (write(1, &format[index], 1) < 0)
				return (-1);
			(*len)++;
			index++;
		}
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	if (ft_process(format, &len, args) == -1)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (len);
}

/* #include <stdio.h>

int	main(void)
{
	int a = -2147483647;
	int	r = 0;
	int rf = 0;
	int	*p = NULL;

	r = ft_printf("%x %X %d\n", a, a, a);
	rf = printf("%x %X %d\n", a, a, a);

	printf("%d %d\n", r, rf);

	r = ft_printf("%p\n", p);
	rf = printf("%p\n", p);

	printf("%d %d\n", r, rf);
}
 */