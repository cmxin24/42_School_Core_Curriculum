/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:41:15 by meyu              #+#    #+#             */
/*   Updated: 2025/08/22 11:57:23 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	num;
	int	i;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	num = atoi(argv[1]);
	if (num == 1)
	{
		printf("1\n");
		return (0);
	}
	i = 2;
	while (i <= num)
	{
		if (num % i == 0)
		{
			printf("%d", num);
			if (num != i)
				printf("*");
		}
		else
			i++;
	}
	printf("\n");
	return (0);
}
