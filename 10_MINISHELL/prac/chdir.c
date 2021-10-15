#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
	char a[1024];
	// char *b = NULL;
	// char *c = NULL;
	// char *d = NULL;

	getcwd(a, 1024);
	printf("a = %d\n%s\n", a);
	// printf("b = %d\n%s\n\n", b);
	// printf("c = %d\n%s\n", c);
	// printf("d = %d\n%s\n\n", d);
	return (0);
}