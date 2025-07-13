/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:31:47 by meyu              #+#    #+#             */
/*   Updated: 2025/07/12 22:05:55 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		num = (unsigned int)(-(long)n);
	}
	else
		num = n;
	temp = print_unsigned_decimal(num);
	if (temp < 0)
		return (-1);
	return (len + temp);
}
