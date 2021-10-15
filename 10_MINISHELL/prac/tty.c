#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int fd;
	char *path;

	fd = ttyslot();
	path = ttyname(fd);
	if (isatty(fd))
		printf("ttyname - %s\n", path);
	else
		return (1);
	return (0);
}