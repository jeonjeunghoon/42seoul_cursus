#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int num;

	fd = open("/dev/lp0", O_RDWR | O_NDELAY);
	if (fd < 0)
	{
		perror("open error");
		exit(1);
	}
	while (1)
	{
		ioctl(fd, LPGETSTATUS, );
	}
}