#include "../inc/push_swap.h"

void		ft_exit(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int			is_valid_arg(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 2)
		return (0);
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
				return (0);
		}
		i++;
	}
	return (1);
}

void		num_init(int argc, char **argv, int *num_ptr)
{
	
}

void		arg_init(int argc, char **argv, int *num_ptr)
{
	if ((is_valid_arg(argc, argv) == 0))
		ft_exit();
	num_init(argc, argv, num_ptr);
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
	int		*num_arr;

	arg_init(argc, argv, num_arr);
	stack_init(a_head, b_head, argc + 1);
	return (0);
}
