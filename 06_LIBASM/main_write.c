#include <unistd.h>
#include <stdio.h>
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

int main(void)
{
	printf("%zd\n", ft_write(1, "Hello, World!\n", 14));
	printf("%zd\n", write(1, "Hello, World!\n", 14));
	return (0);
}