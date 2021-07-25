/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:18:59 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/25 18:17:15 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_two_dimension(char **two_dimention)
{
	int	i;

	i = 0;
	while (two_dimention[i])
	{
		free(two_dimention[i]);
		i++;
	}
	free(two_dimention);
}

void	free_all(t_arg **arg)
{
	free((*arg)->infile);
	free((*arg)->outfile);
	free((*arg)->path1);
	free((*arg)->cmd1);
	free((*arg)->cmd1_option);
	free((*arg)->path2);
	free((*arg)->cmd2);
	free((*arg)->cmd2_option);
	free_two_dimension((*arg)->cmd1_arg);
	free_two_dimension((*arg)->cmd2_arg);
	free(*arg);
}
