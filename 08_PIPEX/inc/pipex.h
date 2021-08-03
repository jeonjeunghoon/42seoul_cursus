/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:50:08 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/03 22:17:11 by jeunjeon         ###   ########.fr       */
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
# include "get_next_line.h"

# define IS_ERROR -1
# define FD_EXIT 0
# define FD_ENTRY 1

typedef struct s_arg
{
	int			is_heredoc;
	char		*eof;
	char		*infile;
	char		*outfile;
	char		*cmd1;
	char		*cmd2;
	char		**cmd_arg1;
	char		**cmd_arg2;
	char		**cmd_envp;
}	t_arg;

// arg_init.c
int		parse_argv(const char **argv, t_arg *arg);
int		parse_envp_path(char ***ptr, char **envp);
int		arg_init(int argc, char const **argv, char **envp, t_arg **arg);

// parse_func.c
void	free_cmd_arg(char **cmd_arg);
char	*make_cmd_path(t_arg *arg, char *arg_cmd);
int		make_arg(char ***ptr, char const **argv, int start_point);
int		parse_solo_quotation(const char **argv, t_arg **arg);
int		parse_double_quotation(const char **argv, t_arg **arg);

// redirect.c
void	redirect_out(char *file_path, int is_heredoc);
void	redirect_in(char *file_path);

// pipex.c
int		clear_temp(void);
int		heredoc(const char *eof);
void	connect_pipe(int *fildes, int io);
int		pipex_bonus(t_arg *arg, int *fildes, char **envp, pid_t *pid);
int		pipex(t_arg *arg, int *fildes, char **envp, pid_t *pid);

#endif
