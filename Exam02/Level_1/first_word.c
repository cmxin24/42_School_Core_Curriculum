/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:47:20 by meyu              #+#    #+#             */
/*   Updated: 2025/08/18 14:28:07 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	int total_len = 0;
	while (argv[1][total_len] != '\0')
		total_len++;
	int	space_start = 0;
	while (i < total_len)
	{
		if (argv[1][space_start] == ' ' || argv[1][space_start] == '	')
			space_start++;
		i++;
	}
	if (space_start == total_len)
	{
		write (1, "\n", 1);
		return (0);
	}
	int	word = space_start;
	while (word < total_len)
	{
		if (argv[1][word] > 33 && argv[1][word] < 126)
		{
			write(1, &argv[1][word], 1);
			word++;
		}
		if (argv[1][word] == ' ' || argv[1][word] == '	')
			return (0);
	}
	return (0);
}
