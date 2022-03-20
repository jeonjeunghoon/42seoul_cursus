/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/20 12:02:28 by jeunjeon         ###   ########.fr       */
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

# define BASIC 1
# define EXECVE 2
# define HEREDOC 3
# define WRITE 1
# define READ 0
# define SIGNAL -1

typedef struct s_sig
{
	int		type;
	int		signum;
	int		exitnum;
}	t_sig;

t_sig	*g_sig;

typedef struct s_refine
{
	char	*new_str;
	char	*str;
	char	**envp;
	char	*name;
	char	*env;
	int		i;
	int		j;
	t_bool	is_basic;
	t_bool	is_single;
	t_bool	is_double;
}	t_refine;

typedef struct s_token
{
	char	*token;
	char	*add_str;
	t_bool	single_quote;
	t_bool	double_quote;
	t_bool	is_stream;
}	t_token;

typedef struct s_argv
{
	char	**argv;
	int		redirect_stream;
	t_bool	is_redirect;
	t_bool	is_heredoc;
	t_bool	is_stream;
	t_bool	was_pipe;
	t_bool	is_pipe;
	t_bool	is_and;
	t_bool	is_or;
	t_bool	is_wildcard;
	t_bool	hav_cmd;
}	t_argv;

typedef struct s_input
{
	t_list	*token_lst;
	t_list	*argv_lst;
	char	*user_input;
}	t_input;

typedef struct s_mini
{
	struct termios	org_term;
	struct termios	new_term;
	char			**env_list;
	char			**export_list;
	char			**path;
	t_input			*input;
	int				origin_fd[2];
	int				pipe_fd[2];
	t_sig			*sig;
	t_bool			wild_chk;
}	t_mini;

typedef struct s_wild
{
	int		i;
	int		start_idx;
	int		flag;
	t_token	tmp_token;
	char	*str;
}	t_wild;

// main
void	clear_resource(t_mini *mini);
void	minishell_init(t_mini *mini);
int		memory_allocation(t_mini **mini, char **envp);
int		main(int argc, const char **argv, char **envp);

// ft_prompt
char	*get_prompt(char *locate, char **envp);
char	*get_locate(void);
int		ft_prompt(t_mini *mini);

// ft_parsing
int		create_argv_lst(t_list **argv_lst, t_list *token_lst);
void	create_token_lst(t_mini *mini, t_list **lst, char *input);
int		exception_handling(char *input);
int		ft_parsing(t_mini *mini);

// check_stream_symbol
int		stream_symbol_error(char *prev_str, char *next_str, \
							char *symbol, char *near_symbol);
void	near_symbol_exist(char **near_symbol, char *str, int i);
int		check_symbol(char **symbol, char **near_symbol, char *str);
t_bool	is_valid_symbol(t_mini *mini, char *str, char *prev_str, \
						char *next_str);
int		check_stream_symbol(t_mini *mini, t_list *token_lst);

// symbol_error_utility
int		error_check_another(char *symbol);
int		error_check_nearsymbol(char *near_symbol);
int		error_check_redirect(char *next_str);
int		error_check_pipe(char *prev_str, char *next_str, char *symbol);
int		error_check_and_or(char *prev_str, char *next_str, char *symbol);

// check_stream_utility
int		open_heredoc(t_mini *mini, char *next_str);
int		open_file(t_mini *mini, char *symbol, char *next_str);
int		create_file(char *symbol, char *next_str);
char	*valid_symbol_list(char *str, int i);

// check_stream_utility2
t_bool	is_symbol(char *str);
void	symbol_free(char **symbol, char **near_symbol);
void	refine_heredoc(t_mini *mini, char **input);
void	heredoc_catch_signal(void);
t_bool	is_signal_heredoc(char *input);

// ft_signal
void	sig_func(int signum);
void	ft_signal(void);

// minishell
t_bool	check_and_or(t_argv *argv);
int		minishell(t_mini *mini);

// create_argv_set
char	**create_first_redirect(t_list **head, t_argv *argv, \
								t_argv *file, char ***cmd);
void	combine_argvs(t_list **head, t_argv *argv, t_argv *file);
void	is_redirect(t_list **head, t_argv *argv);
t_bool	stream_check(t_list **head, t_argv *argv);
void	create_argv_set(t_list **head, t_argv *argv);

// create_argv_set2
void	refine_file(t_argv *file);
char	**modify_file_argv(t_argv *file);
char	**create_cmd(t_argv *argv, t_argv *file);
void	finish_create(t_argv *argv, char ***cmd, char ***redirect_file);
void	cmd_argv_exist(char ***cmd, char ***cmd_argv, char ***tmp);

// ft_command
int		mini_command(t_mini *mini, char *cmd, t_argv *argv);
int		pid_zero(t_mini *mini, t_argv *argv, char **cmd_path, t_bool is_child);
void	pid_not_zero(t_mini *mini, t_argv *argv, int pid, int *stat_loc);
int		pipe_set(t_mini *mini, t_argv *argv, int *pid, t_bool *is_child);
int		ft_command(t_mini *mini, t_argv *argv);

// ft_echo
void	print_msg(char **argv, int start_ptr, int n_flag);
int		n_option(char **argv, int *start_ptr);
void	ft_echo(t_argv *argv);

// ft_cd
void	set_env_cd(t_mini *mini, char *old_pwd);
int		check_path(char *path);
char	*get_path(char **envp, char *argv);
void	ft_cd(t_mini *mini, t_argv *argv);

// ft_pwd
void	ft_pwd(t_argv *argv);

// ft_export
void	print_export(char **export_list);
void	export_list(char ***list, t_argv *argv, int i);
int		check_export_argv(char *argv);
void	ft_export(t_mini *mini, t_argv *argv);

// export_utility
char	*get_envname_export(char *argv);
char	**create_export_envp(char **envp, char *env);
int		is_valid_export(char *argv, int i);

// ft_unset
void	unset_list(char ***list, t_argv *argv);
int		check_unset_argv(char **argv, int *size);
void	ft_unset(t_mini *mini, t_argv *argv);

// unset_utility
char	**create_unset_envp(char **envp, int *position, int size);
void	get_position(int *position, char **envp, char **argv);
void	position_init(int **position, int *size, char **envp, char **argv);

// ft_env
void	show_env(char **envp);
void	ft_env(t_mini *mini, t_argv *argv);

// ft_exit
int		check_argv(char *argv);
int		exit_exception(int argc, char **argv);
void	ft_exit(t_argv *argv);

// ft_error
void	error_symbol(char *symbol, int exit_num);
void	error_2(char *cmd, char *argv, char *msg, int exit_num);
void	error_1(char *cmd, char *msg, int exit_num);
void	ft_error(char *msg, int exit_num);

// utility
char	*get_envname(char *name);
char	*ft_getenv(char **envp, char *name);
void	exit_num_set(int num);
void	token_free(t_list *lst);
void	argv_free(t_list *lst);

// parse_utility
int		stream_flag_str(t_token *token);
void	token_init(t_token *token);
void	create_stream(t_argv **stream, t_token *token, t_list **argv_lst);
void	create_argv(t_argv **argv, t_list *token_lst, \
					t_list **argv_lst, int size);

// parse_utility2
void	exception_utility(char c, t_bool *sin, t_bool *dou);
void	argv_lst_init(t_argv **str, t_argv **stream, int *size);
void	argv_init(t_argv *argv);

// tokenize
void	refine_init(t_refine *refine);
int		refine_str(t_mini *mini, t_token *token, char **envp);
int		stream_parse(t_token *token, char *input, int *end);
int		str_parse(t_token *token, char *input, int *end);
t_list	*tokenize(t_mini *mini, t_token *token, char *input, int *start);

// tokenize_utility
void	basic_str(t_refine *refine);
void	dollar_str(t_mini *mini, t_refine *refine);
void	double_quote_str(t_mini *mini, t_refine *refine);
void	single_quote_str(t_mini *mini, t_refine *refine);
int		create_refined_str(t_mini *mini, t_refine *refine);

// tokenize_utility2
char	*get_envname_parse(char *str, int *i);
void	create_new_str(t_refine *refine, int env_len, char *tmp);
void	env_str(t_refine *refine);
t_bool	is_stream(char c);
t_bool	str_condition(char c, t_token *token);

// tokenize_utility3
int		env_after_dollor(t_refine *refine);
void	show_minishell(t_refine *refine);
void	num_after_dollor(t_refine *refine);
void	basic_str(t_refine *refine);
void	exitnum_str(t_mini *mini, t_refine *refine);

// command_utility
void	create_path_bundle(t_mini *mini);
void	set_absolute_path(char **file_path, char *cmd);
void	create_cmdpath(t_mini *mini, char *cmd, char **cmd_path);

// exe_cmd
void	remove_redirection(t_argv *argv);
int		set_redirect(t_argv *argv);
void	exe_child(t_mini *mini, char **argv, char *cmd_path, char **envp);
void	exe_cmd(t_mini *mini, char *cmd_path, t_argv *argv, t_bool is_child);

// command_utility3
void	save_origin_fd(t_mini *mini);
void	load_origin_fd(t_mini *mini);

// w_utility
t_bool	ft_s_isreg(int mode);
t_bool	ft_s_isdir(int mode);
int		ft_wexitstatus(int stat_loc);
int		ft_wstopsig(int stat_loc);
t_bool	ft_wifexited(int stat_loc);

// redirect_utility
int		heredoc(char *argv, int *i);
int		append(char *argv, char *file, int *i);
int		rtol(char *argv, char *file, int *i);
int		ltor(char *argv, char *file, int *i);

//ft_wildcard
void	init_get_wild_str(t_wild *wild, t_list **wild_token);
void	wild_isin(t_list **lst, t_list *wild_str, t_token **token);
t_list	*get_wild_str(t_mini *mini, char *token);
t_list	*get_ls_list(char **envp);
t_list	*find_wild_str(t_list *wild_token, t_list *ls_lst, int flag);
void	flag_set(t_wild	*wild, t_bool null_flag);
void	flag_set2(t_wild	*wild, t_bool null_flag);

#endif
