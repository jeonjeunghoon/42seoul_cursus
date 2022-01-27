/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/28 00:13:56 by jeunjeon         ###   ########.fr       */
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
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/errno.h>
# include <signal.h>
# include <dirent.h>
# include <term.h>
# include <curses.h>

int			g_exit_state;

typedef struct s_token
{
	char	*token;
	t_bool	single_quote;
	t_bool	double_quote;
	t_bool	pipe;
	t_bool	output;
	t_bool	append;
	t_bool	input;
	t_bool	heredoc;
	t_bool	ampersand;
	t_bool	vertical;
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

typedef struct s_mini
{
	char			**envp;
	char			**path;
	t_input			*input;
	struct termios	term;
}	t_mini;

// main
int		main(int argc, const char **argv, char **envp);

// ft_prompt
int		ft_prompt(t_mini *mini);

// ft_parsing
int		ft_parsing(t_mini *mini);

// ft_signal
void	sig_handler(int sig);
void	ft_signal(void);

// minishell
int		ft_command(t_mini *mini, t_argv *argv);
int		ft_stream(t_mini *mini);
int		minishell(t_mini *mini);

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
void	error_1(char *cmd, char *msg);
void	error_2(char *cmd, char *argv, char *error_msg);
void	ft_error(void);

// utility
char	*get_envname(char *name);
char	*ft_getenv(char **envp, char *name);
void	exit_num_set(int num);
void	token_free(t_list *lst);
void	argv_free(t_list *lst);

// parse_utility
int		stream_flag_str(t_token *token);
void	token_init(t_token *token);
void	create_argv(t_argv **argv, t_list *token_lst, t_list **argv_lst, int size);
void	create_argv_stream(t_argv **stream, t_token *token, t_list **argv_lst);

// parse_utility2
void	exception_utility(char c, t_bool *sin, t_bool *dou);
void	argv_lst_init(t_argv **str, t_argv **stream, int *size);

// tokenize
int		single_quote_parse(t_token *token, char *input, int *end);
int		double_quote_parse(t_token *token, char *input, int *end);
int		stream_parse(t_token *token, char *input, int *end);
int		str_parse(t_token *token, char *input, int *end);
int		tokenize(t_token *token, char *input, int *start, char **envp);

// tokenize_utility
char	*remove_double_quote(char *str, char **envp);
char	*remove_single_quote(char *str);
char	*replace_env(char *str, char **envp);

// tokenize_utility2
t_bool	stream_condition(char c);
t_bool	str_condition(char c, t_token *token);

// command_utility
void	create_path_bundle(t_mini *mini);

// export_utility
int		is_valid_export(char *argv, int i);
char	*get_envname_export(char *argv);

#endif
