#include <unistd.h>

int main(int argc, char **argv)
{
	char arr[255];
	int i;
	int j;

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
		{
			arr[i] = 0;
			i++;
		}
		i = 2;
		j = 0;
		while (argv[i][j])
		{
			arr[argv[i][j]] = 1;
			j++;
		}
		i = 1;
		j = 0;
		while (argv[i][j])
		{
			if (arr[argv[i][j]] == 1)
			{
				write(1, &argv[i][j], 1);
				arr[argv[i][j]]++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}