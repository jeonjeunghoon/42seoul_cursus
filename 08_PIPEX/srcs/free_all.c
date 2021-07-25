/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:18:59 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/25 19:02:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_all(t_arg **arg)
{
	free((*arg)->infile);
	free((*arg)->outfile);
	free((*arg)->path1);
	free((*arg)->path2);
	free(*arg);
}
