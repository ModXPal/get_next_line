#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line); 
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line); 
	printf("%s\n", line);
}
