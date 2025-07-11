/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin <xin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 08:03:39 by xin               #+#    #+#             */
/*   Updated: 2025/07/11 09:24:13 by xin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_new_str_cpy(char **str, size_t len, size_t start, char const *s1)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		(*str)[i] = s1[start + i];
		i++;
	}
	(*str)[i] = '\0';
	return (*str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start;
	size_t	end;
	size_t	new_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_find_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end > 0)
		end --;
	while (end > start && ft_find_set(s1[end], set))
		end --;
	if (end >= start)
		new_len = end - start + 1;
	else
		new_len = 0;
	new_str = (char *)malloc (new_len + 1);
	if (!new_str)
		return (NULL);
	return (ft_new_str_cpy(&new_str, new_len, start, s1));
}
