#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *strs;
	int r;
	if (0 >= ( fd = open("test.txt", 0)))
		return (0);
	while ((r = get_next_line(fd, &strs)) > 0)
	{
		printf("%2d-%s\n", r, strs);
		if (strs)
		{
			free(strs);
			strs = NULL;
		}

	}
	if (r >= 0)
		printf("%2d-%s\n---\n", r, strs);
	return (0);
}
