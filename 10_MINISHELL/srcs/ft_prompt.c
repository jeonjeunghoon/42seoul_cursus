/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 16:54:33 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	prompt_set(t_mini *mini)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp = ft_strjoin(mini->prompt->locate, " ");
	if (tmp == NULL)
		return (ERROR);
	tmp2 = NULL;
	tmp2 = ft_strjoin(getenv("USER"), "$ ");
	if (tmp2 == NULL)
		return (ERROR);
	mini->prompt->prompt = ft_strjoin(tmp, tmp2);
	if (mini->prompt->prompt == NULL)
		return (ERROR);
	free(tmp);
	tmp = NULL;
	free(tmp2);
	tmp2 = NULL;
	return (0);
}

int	locate_set(t_mini *mini, char *buffer)
{
	char	**splitted_strs;
	int		strs_len;

	splitted_strs = NULL;
	strs_len = 0;
	splitted_strs = ft_split(buffer, '/');
	strs_len = ft_two_dimension_size(splitted_strs);
	if (strs_len == 0)
		mini->prompt->locate = ft_strdup("/");
	else if (strs_len == 2)
		mini->prompt->locate = ft_strdup("~");
	else
		mini->prompt->locate = ft_strdup(splitted_strs[strs_len - 1]);
	ft_two_dimension_free(splitted_strs);
	splitted_strs = NULL;
	return (0);
}

int	ft_prompt(t_mini *mini)
{
	char	*buffer;

	buffer = NULL;
	buffer = getcwd(NULL, 0);
	if (buffer == NULL)
		return (ERROR);
	if ((locate_set(mini, buffer)) == ERROR)
		return (ERROR);
	free(buffer);
	buffer = NULL;
	if ((prompt_set(mini)) == ERROR)
		return (ERROR);
	mini->input->user_input = readline(mini->prompt->prompt);
	if (mini->input->user_input == NULL)
		return (ERROR);
	add_history(mini->input->user_input);
	return (0);
}
