/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:44:06 by meyu              #+#    #+#             */
/*   Updated: 2025/07/12 22:05:58 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);

int	print_char(char c);
int	print_string(const char *s);
int	print_pointer_hexa(void *p);
int	print_decimal_num(int n);
int	print_unsigned_decimal(unsigned int n);
int	print_hexa_decimal(unsigned int n, int if_uppercase);
int	print_percent(void);

#endif