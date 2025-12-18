#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define BUF_SIZE 4096

static int	error_exit(void)
{
	perror("Error");
	return (1);
}

int	main(int argc, char **argv)
{
	char	*pattern;
	size_t	pat_len;
	char	read_buf[BUF_SIZE];
	char	*stash;
	size_t	stash_len;
	ssize_t	r;

	if (argc != 2 || !argv[1][0])
		return (1);

	pattern = argv[1];
	pat_len = strlen(pattern);
	stash = NULL;
	stash_len = 0;

	while ((r = read(0, read_buf, BUF_SIZE)) > 0)
	{
		char	*new_stash;
		char	*pos;
		size_t	offset;

		new_stash = realloc(stash, stash_len + r);
		if (!new_stash)
		{
			free(stash);
			return (error_exit());
		}
		stash = new_stash;
		memmove(stash + stash_len, read_buf, r);
		stash_len += r;

		offset = 0;
		while ((pos = memmem(stash + offset,
					stash_len - offset,
					pattern, pat_len)))
		{
			size_t	idx = pos - stash;

			write(1, stash + offset, idx - offset);
			for (size_t i = 0; i < pat_len; i++)
				write(1, "*", 1);
			offset = idx + pat_len;
		}

		if (offset > 0)
		{
			memmove(stash, stash + offset, stash_len - offset);
			stash_len -= offset;
		}
	}

	if (r < 0)
	{
		free(stash);
		return (error_exit());
	}

	if (stash_len > 0)
		write(1, stash, stash_len);

	free(stash);
	return (0);
}
