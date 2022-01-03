/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:53:32 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 15:51:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	create_prompt(t_mini *mini)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(mini->locate, " ");
	if (tmp == NULL)
		return (ERROR);
	free(mini->locate);
	mini->locate = NULL;
	tmp2 = ft_strjoin(getenv("USER"), "$ ");
	if (tmp2 == NULL)
		return (ERROR);
	mini->prompt = ft_strjoin(tmp, tmp2);
	if (mini->prompt == NULL)
		return (ERROR);
	free(tmp);
	free(tmp2);
	return (0);
}

int	locate_init(t_mini *mini, char *buffer)
{
	char	**splitted_strs;
	int		strs_len;

	splitted_strs = ft_split(buffer, '/');
	strs_len = ft_two_dimension_size(splitted_strs);
	if (strs_len == 0)
		mini->locate = ft_strdup("/");
	else if (strs_len == 2)
		mini->locate = ft_strdup("~");
	else
		mini->locate = ft_strdup(splitted_strs[strs_len - 1]);
	ft_two_dimension_free(splitted_strs);
	return (0);
}

int	prompt_init(t_mini *mini)
{
	char	*buffer;

	buffer = getcwd(NULL, 0);
	if (buffer == NULL)
		return (ERROR);
	if ((locate_init(mini, buffer)) == ERROR)
		return (ERROR);
	if ((create_prompt(mini)) == ERROR)
		return (ERROR);
	free(buffer);
	buffer = NULL;
	return (0);
}
