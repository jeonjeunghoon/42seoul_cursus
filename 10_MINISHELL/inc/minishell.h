/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 14:00:26 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define ENTER 1

typedef struct s_env
{
	char	*user;			// 환경변수 USER
}	t_env;

typedef struct s_mini
{
	char	*pwd;
	char	*locate;		// 현재 셸의 위치
	char	*prompt;
	char	*line;			// 유저의 입력 라인
	char	*cmd;			// 유저가 입력한 커맨드
	int		exit_flag;		// 셸의 종료 시그널
	t_env	*env;			// 환경변수 구조체
}	t_mini;

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <signal.h>
#include <dirent.h>
#include <term.h>
#include <curses.h>

// main

// minishell_init
int	minishell_init(t_mini **mini);

// prompt_init
int		env_init(t_env *env);
int		create_prompt(t_mini *mini);
int		locate_init(t_mini *mini);
int		prompt_init(t_mini *mini);

// ft_prompt
int		ft_prompt(t_mini *mini);

// ft_command
void	execute_command(t_mini *mini);
int		check_command(t_mini *mini);
int		ft_command(t_mini *mini, char *user_input);

// utility
void	error_msg(char *input, char *error_msg);
void	error_func(t_mini *mini);

// ft_pwd.c
void	ft_pwd(void);

#endif
