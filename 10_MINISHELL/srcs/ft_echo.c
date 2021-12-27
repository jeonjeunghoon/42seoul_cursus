#include "../inc/minishell.h"

int		ft_echo(char **argv)
{
	int	i;
	int	n_flag;

	n_flag = FALSE;
	if (argv[0] == NULL)
	{
		write(1, "\n", 1);
		return (1);
	}
	else if (argv[0][0] == '-' && argv[0][1] == 'n' && argv[0][2] == '\0')
		n_flag = TRUE;
	i = 0;
	if (n_flag == TRUE)
		i = 1;
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] == NULL && n_flag == FALSE)
			write(1, "\n", 1);
		i++;
	}
	return (1);
}
