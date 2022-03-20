/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:45:34 by seungcoh          #+#    #+#             */
/*   Updated: 2022/03/04 10:55:25 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_get_wild_str(t_wild *wild, t_list **wild_token)
{
	wild->i = 0;
	wild->start_idx = 0;
	*wild_token = 0;
	wild->flag = 0;
	wild->str = 0;
}

void	wild_isin(t_list **lst, t_list *wild_str, t_token **token)
{
	t_list	*tmp;
	t_token	*new_token;

	tmp = NULL;
	new_token = NULL;
	while (wild_str)
	{
		tmp = wild_str->next;
		new_token = (t_token *)malloc(sizeof(t_token));
		new_token->double_quote = (*token)->double_quote;
		new_token->is_stream = (*token)->is_stream;
		new_token->single_quote = (*token)->single_quote;
		new_token->token = (char *)wild_str->content;
		ft_lstadd_back(lst, ft_lstnew(new_token));
		free(wild_str);
		wild_str = tmp;
	}
	ft_free(&((*token)->token));
	free(*token);
}

void	mk_ls_lst(t_list **ls_lst)
{
	int		fd;
	char	*line;

	fd = open(".ls_tmp", O_RDONLY, 0644);
	while (get_next_line(fd, &line))
		ft_lstadd_back(ls_lst, ft_lstnew(line));
	free(line);
	unlink(".ls_tmp");
}

void	exec_ls(char **argv, char **envp)
{
	int	fd;

	fd = open(".ls_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (execve("/bin/ls", argv, envp) == ERROR)
	{
		ft_error(strerror(errno), 1);
		exit(g_sig->exitnum);
	}
}

t_list	*get_ls_list(char **envp)
{
	int		val;
	char	**argv;
	pid_t	pid;
	t_list	*ls_lst;

	argv = (char **)malloc(sizeof(char *) * 2);
	argv[0] = (char *)malloc(sizeof(char) * 3);
	ft_strlcpy(argv[0], "ls", 3);
	argv[1] = 0;
	ls_lst = 0;
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &val, 0x00000002);
		free(argv[0]);
		free(argv);
		if (ft_wifexited(val) == TRUE)
			exit_num_set(ft_wstopsig(val));
		mk_ls_lst(&ls_lst);
		return (ls_lst);
	}
	else if (pid == 0)
		exec_ls(argv, envp);
	return (0);
}
