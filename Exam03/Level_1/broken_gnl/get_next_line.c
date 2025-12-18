#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
	if (!s)
		return NULL;
	size_t i = 0;
	while (s[i])
	{
		if (s[i]== (char)c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	while(i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i ++;
	}
  return dest;
}

size_t ft_strlen(char *s)
{
	size_t i = 0;

	if (!s)
		return 0;
	while (s[i])
		i++;
	return i;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t size1 = (*s1) ? ft_strlen(*s1) : 0;
	char *tmp = malloc(size2 + size1 + 1);
	if (!tmp)
	{
		if (*s1)
			free(*s1);
		*s1 = NULL;
		return 0;
	}
	if (*s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return 1; 
}

int str_append_str(char **s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
  size_t i = 0;

	if (!dest || !src)
		return dest;
	if (dest < src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else{
		i = n;
		while (i > 0)
			((char *)dest)[i] = ((char *)src)[i];
	}
  return dest;
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1] = "";
	char *line;
	char *newline;
	int		bytes;

	if (fd < 0 || BUFFER_SIZE <=0)
		return NULL;
	line = NULL;
	newline = ft_strchr(buffer, '\n');

	while (!newline)
	{
		if (buffer[0])
		{
			if (!str_append_str(&line, buffer))
				return NULL;
			buffer[0] = '\0';
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		buffer[bytes] = '\0';
		newline = ft_strchr(buffer, '\n');
	}
	if (newline)
	{
		if (!str_append_mem(&line, buffer, newline - buffer + 1))
			return NULL;
		ft_memmove(buffer, newline + 1, ft_strlen(newline + 1) +1);
		return line;
	}
	if (line && *line)
		return line;
	free(line);
	return NULL;
}

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// {
//     printf("%s", line);
//     free(line);
// }
// }