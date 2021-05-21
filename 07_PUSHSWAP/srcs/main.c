#include "../inc/push_swap.h"

void		ft_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

void		arg_except(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		ft_exit();
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
				j++;
			if (argv[i] >= '0' && argv[i] <= '9')
				j++;
			else
				ft_exit();
		}
		i++;
	}
}

void		stack_init(list_t a_head, list_t b_head, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		
	}
}

int			main(int argc, char **argv)
{
	list_t	a_head;
	list_t	b_head;

	arg_except(argc, argv);
	stack_init(a_head, b_head, argc + 1);
	return (0);
}
