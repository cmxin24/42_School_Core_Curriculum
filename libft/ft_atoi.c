/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:23:39 by xin               #+#    #+#             */
/*   Updated: 2025/07/11 12:25:41 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_sign(const char *str, int *start, int *sign)
{
	while (str[*start] == '+' || str[*start] == '-')
	{
		if (str[*start] == '-')
			*sign = -*sign;
		(*start)++;
	}
}

int	ft_atoi(const char *str)
{
	int	start;
	int	len;
	int	num;
	int	sign;

	start = 0;
	len = 0;
	num = 0;
	sign = 1;
	while (str[start] == ' ' || (str[start] >= 9 && str[start] <= 13))
		start++;
	ft_sign(str, &start, &sign);
	len = start;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	while (start < len)
	{
		num = num * 10 + (str[start] - 48);
		start++;
	}
	if (sign == -1)
		num = -num;
	return (num);
}
