/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:50:08 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/01 14:23:11 by jeunjeon         ###   ########.fr       */
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

// main.c
int		is_valid_arg(int argc, const char **argv);
int		arg_init(int argc, char const **argv, char **envp, t_arg **arg);
int		pipex(t_arg *arg, int *fildes, char **envp);

// arg_init.c
int		parse_envp_path(char ***ptr, char **envp);
char	*make_cmd_path(t_arg *arg, char *arg_cmd);
int		make_arg(char ***ptr, char const **argv, int start_point);
int		parse_solo_quotation(const char **argv, t_arg **arg);
int		parse_double_quotation(const char **argv, t_arg **arg);

// redirect.c
void	redirect_out(t_arg *arg);
void	redirect_in(t_arg *arg);

// pipe.c
void	connect_pipe(int *fildes, int io);

// free_all.c
void	free_all(t_arg **arg);

#endif
