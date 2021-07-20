/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:47:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/18 22:51:05 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_all(t_arg **arg)
{
	free((*arg)->infile);
	free((*arg)->outfile);
	free((*arg)->cmd1);
	free((*arg)->cmd2);
	free(*arg);
}

void	arg_init(int argc, char **argv, t_arg **arg)
{
	if (argc != 5)
		ft_exit("Error\n");
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if (!(*arg))
		ft_exit("Error\n");
	(*arg)->infile = ft_strdup(argv[1]);
	(*arg)->cmd1 = ft_strdup(argv[2]);
	(*arg)->cmd2 = ft_strdup(argv[3]);
	(*arg)->outfile = ft_strdup(argv[4]);
}

int	main(int argc, char **argv)
{
	t_arg	*arg;

	arg_init(argc, argv, &arg);
	free_all(&arg);
	return (0);
}
