/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:47:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/28 22:59:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	is_valid_arg(int argc, const char **argv)
{
	int	i;
	int	num_of_cmd;

	num_of_cmd = 0;
	i = 2;
	while (argv[i] && (i < argc - 1))
	{
		if (num_of_cmd > 2)
			return (IS_ERROR);
		else if (argv[i][0] >= 'a' && argv[i][0] <= 'z')
		{
			num_of_cmd++;
			i++;
		}
		else if (argv[i][0] == '-')
			i++;
		else
			return (IS_ERROR);
	}
	return (0);
}

int	main(int argc, const char **argv, const char **envp)
{
	t_arg	*arg;
	int		fildes[2];

	for (int i = 0; envp[i]; i++)
		printf("%s\n", envp[i]);
	if ((is_valid_arg(argc, argv)) == IS_ERROR)
		ft_exit("illegal arg\n");
	if ((arg_init(argc, argv, &arg)) == IS_ERROR)
		ft_exit("Error\n");
	if ((pipe(fildes)) == IS_ERROR)
	{
		perror("pipe");
		ft_exit(NULL);
	}
	if ((pipex(arg, fildes)) == IS_ERROR)
	{
		perror(NULL);
		ft_exit(NULL);
	}
	return (0);
}
