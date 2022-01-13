/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/13 13:13:26 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/errno.h>
# include <signal.h>
# include <dirent.h>
# include <term.h>
# include <curses.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef int BOOL;

typedef struct s_token
{
	char	*token;
	bool	single_quote;
	bool	double_quote;
	bool	pipe_flag; // |
	bool	output; // >
	bool	append;	// >>
	bool	input; // <
	bool	heredoc; // <<
	bool	ampersand; // &&
	bool	vertical; // ||
}	t_token;

typedef struct s_argv
{
	char	**argv;
}	t_argv;

typedef struct s_input
{
	t_list	*token_lst;
	t_list	*argv_lst;
	char	*user_input;
}	t_input;

typedef struct s_prompt
{
	char	*locate;
	char	*prompt;
	char	*path_of_cmd;
	char	**envp;
}	t_prompt;

typedef struct s_flag
{
	bool	single_flag;
	bool	double_flag;
	bool	minicmd_flag;
}	t_flag;

typedef struct s_mini
{
	t_input		*input;
	t_prompt	*prompt;
	t_flag		*flag;
}	t_mini;

int	g_exit_state;

// main
int		main(int argc, const char **argv);

// ft_prompt
int		ft_prompt(t_mini *mini);

// ft_parsing
int		ft_parsing(t_mini *mini);

// ft_signal
int		ft_signal(t_mini *mini);

// ft_stream
int		ft_stream(t_mini *mini);

// ft_command
int		ft_command(t_mini *mini, t_token *head);

// ft_echo
int		ft_echo(t_mini *mini, char **argv);

// ft_cd
void	ft_cd(t_mini *mini, char **argv);

// ft_pwd
void	ft_pwd(t_mini *mini, char **argv);

// ft_export
void	ft_export(t_mini *mini, char **argv);

// ft_unset
void	ft_unset(t_mini *mini, char **argv);

// ft_env
void	ft_env(t_mini *mini, char **argv);

// ft_exit
void	ft_exit(t_mini *mini, char **argv);

// error_msg
void	ft_error(void);
void	too_many_arguments(char *cmd);
void	command_not_found(char *cmd);
void	error_msg(char *cmd, char *argv, char *error_msg);

#endif
