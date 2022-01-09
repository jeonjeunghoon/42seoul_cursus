/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/09 17:48:36 by jeunjeon         ###   ########.fr       */
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
	char	**argv;
	char	**envp;
	int		exit_flag;
	int		continue_flag;
	int		minicmd_flag;
}	t_mini;

int	g_exit_state;

// main

// minishell_init
int		minishell_init(t_mini **mini);

// load_prompt
int		create_prompt(t_mini *mini);
int		locate_init(t_mini *mini, char *buffer);
int		load_prompt(t_mini *mini);

// ft_prompt
void	clear_resource(t_node **head, char ***argv, char *user_input);
int		is_empty_input(char **argv);
int		get_user_input(char **prompt, char **user_input, char ***argv);
int		ft_prompt(t_mini *mini);

// set_input
void	print_list(t_node *head);
void	make_input_node(t_node *head, char **argv, int start, int end);
int		need_split(char *argv);
t_node	*set_input(t_mini *mini, char **argv);

// ft_command
char	*shell_command(t_mini *mini, char *cmd);
int		mini_command(t_mini *mini, char *cmd, char **argv);
int		ft_command(t_mini *mini, t_node *head);

// utility
void	too_many_arguments(char *cmd);
void	command_not_found(char *cmd);
void	error_msg(char *cmd, char *argv, char *error_msg);

// ft_echo
int		n_option(char *argv, int *start_ptr);
int		ft_echo(t_mini *mini, char **argv);

// ft_cd
char	*get_path(char *argv);
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
