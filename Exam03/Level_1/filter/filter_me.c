#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int	print_error()
{
	perror("Error");
	return (1);
}

int	main(int argc, char *argv[])
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes = BUFFER_SIZE;
	char	*input = NULL;
	int		input_len = 0;
	char	*s;
	char	s_len;
	int		index = 0;

	if (argc != 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	s = argv[1];
	s_len = strlen(s);
	while (bytes > 0)
	{
		bytes = read(0, buffer, BUFFER_SIZE);
		if (bytes < BUFFER_SIZE)
		{
			input = realloc(input, input_len + bytes + 1);
			if (!input)
				return (print_error());
			memmove(input + input_len, buffer, bytes);
			input_len += bytes;
			input[input_len] = '\0';
			break ;
		}
		else if (bytes == BUFFER_SIZE)
		{
			input = realloc(input, input_len + BUFFER_SIZE + 1);
			if (!input)
				return (print_error());
			memmove(input + input_len, buffer, BUFFER_SIZE);
			input_len += BUFFER_SIZE;
			input[input_len] = '\0';
		}
	}
	char *position;
	while ((position = memmem(input, input_len, s, s_len)))
	{
		int i = position - input;
		for(index = 0; index < s_len; index++)
		{
			input[i + index] = '*';
		}
	}
	printf("%s", input);
	free(input);
	return (0);
}
