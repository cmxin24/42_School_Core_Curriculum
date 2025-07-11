/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyu <meyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:12:26 by xin               #+#    #+#             */
/*   Updated: 2025/07/11 14:54:56 by meyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_len(char **subs, size_t s_len, unsigned int start)
{
	if (start >= s_len)
	{
		*subs = (char *)malloc(1);
		if (!(*subs))
			return (-1);
		(*subs)[0] = '\0';
		return (0);
	}
	return (1);
}

static size_t	ft_count_len(size_t s_len, size_t len, unsigned int start)
{
	size_t	subs_len;

	if (s_len - start < len)
		subs_len = s_len - start;
	else
		subs_len = len;
	return (subs_len);
}

static void	copy(char *subs, size_t subs_len, unsigned int start, char const *s)
{
	size_t	i;

	i = 0;
	while (i < subs_len)
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[subs_len] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;
	size_t	subs_len;
	int		check;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	check = ft_check_len(&subs, s_len, start);
	if (check == -1)
		return (NULL);
	else if (check == 0)
		return (subs);
	subs_len = ft_count_len(s_len, len, start);
	subs = malloc(subs_len + 1);
	if (!subs)
		return (NULL);
	copy(subs, subs_len, start, s);
	return (subs);
}
