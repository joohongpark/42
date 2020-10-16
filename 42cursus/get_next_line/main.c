#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *strs;
	if (0 >= ( fd = open("test.txt", 0)))
		return (0);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	printf("%d, [%s]\n", get_next_line(fd, &strs), strs);
	return (0);
}
