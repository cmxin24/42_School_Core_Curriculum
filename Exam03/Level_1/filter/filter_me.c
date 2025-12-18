#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

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
	ssize_t	bytes = 1;

	if (argc != 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	
	while (bytes > 0)
	{
		bytes = read(0, buffer, BUFFER_SIZE);
	}
	

}
