#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *strs;
	int rtn;
	if (0 >= ( fd = open("test.txt", 0)))
		return (0);
	while (1)
	{
		rtn = get_next_line(fd, &strs);
		printf("%s\n", strs);
		if (rtn != 1)
			break;
	}
	return (0);
}
