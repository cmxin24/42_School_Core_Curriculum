/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:50:07 by xin               #+#    #+#             */
/*   Updated: 2025/09/25 21:07:00 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	is_valid_number(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (1);
}


int	ft_check_argv(int argc, char **argv)
{
	(void)argv;
	if ((argc != 5) && (argc != 6))
		return (-1);
	if (is_valid_number(argv[1]) && is_valid_number(argv[2])
		&& is_valid_number(argv[3]) && is_valid_number(argv[4]))
		return (-1);
	if (argc == 6)
		if (!is_valid_number(argv[5]))
			return (-1);
	return (0);
}

