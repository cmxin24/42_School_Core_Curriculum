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
	size_t	s_len;
	size_t	index = 0;

	if (argc != 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	s = argv[1];
	s_len = strlen(s);
	while (1)
	{
		bytes = read(0, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (print_error());
		if (bytes == 0)
			break ;
		input = realloc(input, input_len + bytes + 1);
		if (!input)
			return (print_error());
		memmove(input + input_len, buffer, bytes);
		input_len += bytes;
		input[input_len] = '\0';
	}
	size_t left = input_len;
	char *position;
	char *input_copy = input;
	while ((position = memmem(input_copy, left, s, s_len)))
	{
		int i = position - input;
		for(index = 0; index < s_len; index++)
		{
			input[i + index] = '*';
		}
		input_copy = position + s_len;
		left = input_len - (input_copy - input);
	}
	printf("%s", input);
	free(input);
	return (0);
}
