/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/05 16:22:16 by jeunjeon         ###   ########.fr       */
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
# define ENTER 1

typedef struct s_mini
{
	char	*pwd;
	char	*locate;
	char	*prompt;
	char	*line;
	char	*cmd;
	char	*user;
	char	**input;
	char	**splitted_input;
	char	**envp;
	int		exit_flag;
	int		minicmd_flag;
}	t_mini;

// main

// minishell_init
int		minishell_init(t_mini **mini);

// prompt_init
int		create_prompt(t_mini *mini);
int		locate_init(t_mini *mini, char *buffer);
int		load_prompt(t_mini *mini);

// ft_prompt
int		ft_prompt(t_mini *mini);

// ft_command
void	builtin_command(t_mini *mini);
char	*shell_command(t_mini *mini, char *cmd);
int		mini_command(t_mini *mini, char **argv);
int		ft_command(t_mini *mini, char *input, char **strs);

// utility
void	error_msg(char *input, char *error_msg);
void	error_func(t_mini *mini);

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

#endif
