/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:44:06 by meyu              #+#    #+#             */
/*   Updated: 2025/08/12 14:20:18 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# if defined(__APPLE__)
#  define NULL_POINTER_STR "0x0"
#  define NULL_POINTER_LEN 3
# elif defined(__linux__)
#  define NULL_POINTER_STR "(nil)" 
#  define NULL_POINTER_LEN 5
# else
#  define NULL_POINTER_STR "0x0"
#  define NULL_POINTER_LEN 3
# endif

int	ft_printf(const char *format, ...);

int	print_char(char c);
int	print_string(const char *s);
int	print_pointer_hexa(void *p);
int	print_decimal_num(int n);
int	print_unsigned_decimal(unsigned int n);
int	print_hexa_decimal(unsigned int n, int if_uppercase);
int	print_percent(void);

#endif