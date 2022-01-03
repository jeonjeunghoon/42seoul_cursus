/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 17:24:34 by jeunjeon         ###   ########.fr       */
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
	int		exit_flag;
	char	*user;
	char	**splitted_input;
	char	**envp;
}	t_mini;

// main

// minishell_init
int		minishell_init(t_mini **mini);

// prompt_init
int		create_prompt(t_mini *mini);
int		locate_init(t_mini *mini, char *buffer);
int		prompt_init(t_mini *mini);

// ft_prompt
int		ft_prompt(t_mini *mini);

// ft_command
void	execute_command(t_mini *mini);
int		check_command(t_mini *mini);
int		ft_command(t_mini *mini, char *input, char **strs);

// utility
void	error_msg(char *input, char *error_msg);
void	error_func(t_mini *mini);

// ft_pwd.c
void	ft_pwd(void);

#endif
