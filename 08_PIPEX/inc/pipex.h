/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:50:08 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/27 11:13:21 by jeunjeon         ###   ########.fr       */
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

# define IS_ERROR -1
# define FD_READ 0
# define FD_WRITE 1

typedef struct s_arg
{
	char		*infile;
	char		*outfile;
	char		*path1;
	char		*path2;
	char *const	*cmd_arg1;
	char *const	*cmd_arg2;
	char *const	*cmd_envp1;
	char *const	*cmd_envp2;
}	t_arg;

// arg_init.c
int		parse_cmd(const char **argv, t_arg **arg);
int		arg_init(int argc, char const **argv, t_arg **arg);

// redirect.c
void	redirect_out(t_arg *arg);
void	redirect_in(t_arg *arg);

// pipe.c
void	pipe_init(int *fildes, int io);
int		pipex(t_arg *arg, int *fildes);

// free_all.c
void	free_all(t_arg **arg);

#endif
