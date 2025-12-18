#include "1.broken_GNL.h"
#include <stdio.h>

// while检查部分要更新条件
// while 之后要看看是否有遗留。如果是EOF， 那就回归static var 为0 ， 然后科学清理

//ft_strchr 有问题，这里要检查s是否为NULL
char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	// while (s[i] != c)
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

//循环有问题，死循环
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	// for (size_t i = 0; i < n; i++)
	// 	((char *)dest)[i] = ((char *)src)[i];

	size_t i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

// *s1 可能是NULL
int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t size1;

	if (*s1 == NULL) //added
		size1 = 0; //added
	else //added
		size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (*s1) //added
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}


//条件错误
//假设dest 和 src 都不是 NULL
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	// if (dest > src) //des 应该在src 左边
	if (dest < src) //des 应该在src 左边 //memcpy适用于 右边往左边覆盖的
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	//size_t	i = ft_strlen((char *)src) - 1;
	size_t	i = n - 1; //改成 n - 1 是n 不是 strlen
	while (i >= 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i--;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;

	char	*tmp = ft_strchr(b, '\n');
	//有就一直循环
	while (!tmp)
	{
		// append b to ret
		if (!str_append_str(&ret, b))
			return (NULL);
		b[0] = 0; // 最好清空，不然可能有一些垃圾数据


		int	read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		if (read_ret == 0) // added: when EOF
			break ;
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n'); // added: update tmp
	}
	if (tmp) // 最后一点append，然后更新
	{
		if (!str_append_mem(&ret, b, tmp - b + 1)) // + 1 to include \n
		{
			free(ret);
			return (NULL);
		}
		ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1); // 更新都用memmove
	}
	else // when EOF (break from while)
	{
		b[0] = '\0'; // clear b since b is static
		if (!ret || !*ret) //NULL：free(NULL) 什么也不做，但它不会导致程序崩溃。empty： 指向了一个由 malloc 分配的内存块
		{
			free(ret);
			return (NULL);
		}

	}
	return (ret);
}

int main()
{
	int fd = open("c", O_RDONLY);
	char *line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
