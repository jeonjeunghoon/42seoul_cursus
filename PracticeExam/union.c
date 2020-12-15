#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
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
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (arr[argv[i][j]] == 1)
					break ;
				else
				{
					arr[argv[i][j]] = 1;
					ft_putchar(argv[i][j]);
				}
				j++;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
