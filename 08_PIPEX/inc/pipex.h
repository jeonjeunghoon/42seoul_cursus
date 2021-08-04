/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:50:08 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/04 22:54:15 by jeunjeon         ###   ########.fr       */
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
# define FD_EXIT 0
# define FD_ENTRY 1

typedef struct s_arg
{
	char		*infile;
	char		*outfile;
	char		*cmd1;
	char		*cmd2;
	char		**cmd_arg1;
	char		**cmd_arg2;
	char		**cmd_envp;
}	t_arg;

// arg_init.c
char	*is_valid_cmd(t_arg *arg, char *arg_cmd);
int		parse_argv(char **argv, t_arg *arg);
int		parse_envp_path(char ***ptr, char **envp);
int		arg_init(int argc, char **argv, char **envp, t_arg **arg);

// redirect.c
void	redirect_out(char *file_path);
void	redirect_in(char *file_path);

// pipex.c
void	pipe_out(int *fildes);
void	pipe_in(int *fildes);
int		pipex(t_arg *arg, int *fildes, char **envp, pid_t *pid);

#endif
