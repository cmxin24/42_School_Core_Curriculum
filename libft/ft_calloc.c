/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:39:17 by xin               #+#    #+#             */
/*   Updated: 2025/07/09 20:13:17 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	register void	*ptr;
	size_t			i;
	unsigned char	*m;

	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	m = (unsigned char *)ptr;
	while (i < count * size)
	{
		m[i] = 0;
		i++;
	}
	return (ptr);
}
