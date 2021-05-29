#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	int fd2;
	int flag;
	char *line = NULL;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("attente.txt", O_RDONLY);
	flag = 1;
	while (flag)
	{
		flag = get_next_line(fd, &line);
		printf("line is -----> %s\n", line);
	}
	printf("get_next_line fd return -----> %d\n", get_next_line(fd, &line));
	printf("get_next_line return -----> %d\n", get_next_line(fd2, &line));
	printf("line is -----> %s\n", line);
}
