#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int idx;

	if (argc == 1)
	{
		fprintf(stderr, "Usage : %s {file1} [file2] ...\n", argv[0]);
		return 1;
	}
	for (idx = 1; idx < argc; idx++)
	{
		if (unlink(argv[idx]) == -1)
			printf("error\n");
		else
			printf("%s file이 삭제되었습니다.\n", argv[idx]);
	}
	return 0;
}