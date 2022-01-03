/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:53:32 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 11:06:08 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

int	create_prompt(t_mini *mini)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(mini->locate, " ");
	if (tmp == NULL)
		return (ERROR);
	tmp2 = ft_strjoin(mini->env->user, "$ ");
	if (tmp2 == NULL)
		return (ERROR);
	mini->prompt = ft_strjoin(tmp, tmp2);
	if (mini->prompt == NULL)
		return (ERROR);
	free(tmp);
	free(tmp2);
	return (0);
}

int	env_init(t_env *env)
{
	env->user = getenv("USER");
	if (env->user == NULL)
		return (ERROR);
	return (0);
}
int	locate_init(t_mini *mini)
{
	char	**splited_strs;
	int		strs_len;
	int		i;

	splited_strs = ft_split(mini->pwd, '/');
	strs_len = ft_veclen(splited_strs);
	if (strs_len == 0)
		mini->locate = ft_strdup("/");
	else if (strs_len == 2)
		mini->locate = ft_strdup("~");
	else
		mini->locate = ft_strdup(splited_strs[strs_len - 1]);
	i = 0;
	while (splited_strs[i])
	{
		free(splited_strs[i]);
		splited_strs[i] = NULL;
		i++;
	}
	free(splited_strs);
	splited_strs = NULL;
	return (0);
}

int	prompt_init(t_mini *mini)
{
	mini->pwd = getcwd(NULL, 1024);
	if (mini->pwd == NULL)
		return (ERROR);
	if ((locate_init(mini)) == ERROR)
		return (ERROR);
	if ((env_init(mini->env)) == ERROR)
		return (ERROR);
	if ((create_prompt(mini)) == ERROR)
		return (ERROR);
	return (0);
}
