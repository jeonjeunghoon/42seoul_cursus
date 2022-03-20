/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/06 16:09:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_prompt(char *locate, char **envp)
{
	char	*prompt;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp = ft_strjoin(locate, " ");
	if (tmp == NULL)
		return (NULL);
	tmp2 = NULL;
	tmp2 = ft_strjoin(ft_getenv(envp, "USER"), "$ ");
	if (tmp2 == NULL)
		return (NULL);
	prompt = ft_strjoin(tmp, tmp2);
	if (prompt == NULL)
		return (NULL);
	free(tmp);
	tmp = NULL;
	free(tmp2);
	tmp2 = NULL;
	return (prompt);
}

char	*get_locate(void)
{
	char	**splitted_strs;
	int		strs_len;
	char	*buffer;
	char	*locate;

	splitted_strs = NULL;
	strs_len = 0;
	buffer = NULL;
	locate = NULL;
	buffer = getcwd(NULL, 0);
	if (buffer == NULL)
		return (NULL);
	splitted_strs = ft_split(buffer, '/');
	free(buffer);
	if (splitted_strs == NULL)
		return (NULL);
	strs_len = ft_two_dimension_size(splitted_strs);
	if (strs_len == 0)
		locate = ft_strdup("/");
	else if (strs_len == 2)
		locate = ft_strdup("~");
	else
		locate = ft_strdup(splitted_strs[strs_len - 1]);
	ft_two_dimension_free(&splitted_strs);
	return (locate);
}

int	ft_prompt(t_mini *mini)
{
	char	*locate;
	char	*prompt;

	locate = NULL;
	prompt = NULL;
	locate = get_locate();
	if (locate == NULL)
		return (ERROR);
	prompt = get_prompt(locate, mini->export_list);
	if (prompt == NULL)
		return (ERROR);
	mini->input->user_input = readline(prompt);
	free(locate);
	locate = NULL;
	free(prompt);
	prompt = NULL;
	if (mini->input->user_input == NULL)
	{
		printf("exit\n");
		exit_num_set(1);
		exit(g_sig->exitnum);
	}
	return (0);
}
