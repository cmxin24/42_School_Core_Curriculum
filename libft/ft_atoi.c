/* ************************************************************************** */
/*\\\\\\\\\\\\\\\ */
/*\\\\\\\\\\\ :::\ ::::::::   */
/*   ft_atoi.c\\\\\\\\  :+:\ :+:    :+:   */
/*\\\\\\\\\\  +:+ +:+\    +:+\*/
/*   By: meyu <meyu@student.42.fr>\\\   +#+  +:+\  +#+\   */
/*\\\\\\\\\   +#+#+#+#+#+   +#+\\ */
/*   Created: 2025/07/08 20:23:39 by xin\\\#+#    #+#\\   */
/*   Updated: 2025/07/11 14:40:41 by meyu\\   ###   ########.fr\  */
/*\\\\\\\\\\\\\\\ */
/* ************************************************************************** */

static void	ft_sign(const char *str, int *start, int *sign)
{
	if (str[*start] == '-')
		*sign = -*sign;
	if (str[*start] == '-' || str[*start] == '+')
		(*start)++;
}

int	ft_atoi(const char *str)
{
	int	len;
	int	num;
	int	sign;
	int	start;

	len = 0;
	num = 0;
	sign = 1;
	start = 0;
	while (str[start] == ' ' || (str[start] >= 9 && str[start] <= 13))
		start++;
	ft_sign(str, &start, &sign);
	while (str[len + start] >= '0' && str[len + start] <= '9')
		len++;
	while (len)
	{
		num = num * 10 + (str[start] - 48);
		start++;
		len--;
	}
	if (sign == -1)
		num = -num;
	return (num);
}

/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *str = "--47";

	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));

	char *str1 = "47";

	printf("%d\n", atoi(str1));
	printf("%d\n", ft_atoi(str1));

	char *str2 = "+47";

	printf("%d\n", atoi(str2));
	printf("%d\n", ft_atoi(str2));
	
	char *str3 = "\n\n\n  -46\b9 \n5d6";

	printf("%d\n", atoi(str3));
	printf("%d\n", ft_atoi(str3));
}
 */