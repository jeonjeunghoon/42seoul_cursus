#include <stdio.h>         // puts()
#include <string.h>        // strlen()
#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()

# define BUFF_SIZE   1024

ssize_t		ft_read(int fildes, void *buf, size_t nbyte);

int			main()
{
	char	buff[BUFF_SIZE];
	char	buff1[BUFF_SIZE];
	int		fd;

	if (0 < (fd = open( "./text.txt", O_RDONLY)))
	{
		printf("ft_read = %zd\n", ft_read(fd, buff, BUFF_SIZE));
		printf("%s\n", buff);
		close( fd);
	}
	else
		printf( "파일 열기에 실패했습니다.\n");
	if (0 < (fd = open( "./text.txt", O_RDONLY)))
	{
		printf("C__read = %zd\n",    read(fd, buff1, BUFF_SIZE));
		printf("%s\n", buff1);
		close( fd);
	}
	else
		printf( "파일 열기에 실패했습니다.\n");
	return 0;
}