/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:50:08 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/25 18:21:59 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "../lib/libft/libft.h"

typedef struct s_arg
{
	char	*infile;
	char	*outfile;
	char	*path1;
	char	*cmd1;
	char	*cmd1_option;
	char	**cmd1_arg;
	char	*path2;
	char	*cmd2;
	char	*cmd2_option;
	char	**cmd2_arg;
}	t_arg;

// main.c
int		arg_init(int argc, char const **argv, t_arg **arg);

// redirect
int		redirect(t_arg *arg);

// free_all
void	free_two_dimension(char **two_dimention);
void	free_all(t_arg **arg);

#endif