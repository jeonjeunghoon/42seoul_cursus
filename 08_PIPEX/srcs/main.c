/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:47:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/27 12:07:05 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, const char **argv)
{
	t_arg	*arg;
	int		fildes[2];

	if ((arg_init(argc, argv, &arg)) == IS_ERROR)
		ft_exit("Error\n");
	if ((pipex(arg, fildes)) == IS_ERROR)
	{
		perror(NULL);
		ft_exit(NULL);
	}
	return (0);
}
