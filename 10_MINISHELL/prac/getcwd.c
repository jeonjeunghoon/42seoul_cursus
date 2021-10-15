#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char path[100];
	char *ptr;

	ptr = getcwd(path, 100);
	printf("%s\n", path);
	printf("%s\n", ptr);
	return (0);
}