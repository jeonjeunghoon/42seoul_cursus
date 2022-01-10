/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 15:28:52 by jeunjeon         ###   ########.fr       */
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

typedef struct s_node
{
	int				is_head;
	char			**argv;
	struct s_node	*next;
}	t_node;

typedef struct s_mini
{
	char	*locate;
	char	*prompt;
	char	*path_of_cmd;
	char	**envp;
	int		continue_flag;
	int		minicmd_flag;
}	t_mini;

int	g_exit_state;

// main

// minishell_init
int		minishell_init(t_mini **mini);

// load_prompt
int		load_prompt(t_mini *mini);

// ft_prompt
int		ft_prompt(t_mini *mini);

// tokenize_input
int		tokenize_input(char *user_input);

// set_input
t_node	*set_input(t_mini *mini);

// ft_command
int		ft_command(t_mini *mini, t_node *head);

// error_msg
void	too_many_arguments(char *cmd);
void	command_not_found(char *cmd);
void	error_msg(char *cmd, char *argv, char *error_msg);

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
