/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:56:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/03 13:13:50 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	env_after_dollor(t_refine *refine)
{
	refine->i++;
	refine->name = get_envname_parse(refine->str, &refine->i);
	refine->env = ft_getenv(refine->envp, refine->name);
	ft_free(&refine->name);
	if (refine->env == NULL)
		return (ERROR);
	else
		env_str(refine);
	refine->env = NULL;
	return (0);
}

void	show_minishell(t_refine *refine)
{
	char	*ptr;

	ptr = ft_strjoin(refine->new_str, "-minishell");
	ft_free(&refine->new_str);
	refine->new_str = ptr;
	refine->j = ft_strlen(refine->new_str);
}

void	num_after_dollor(t_refine *refine)
{
	if (refine->str[refine->i + 1] == '0')
		show_minishell(refine);
	refine->i += 2;
}

void	basic_str(t_refine *refine)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(refine->new_str) + 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	ptr[len] = '\0';
	i = 0;
	while (i < len - 1)
	{
		ptr[i] = refine->new_str[i];
		i++;
	}
	ptr[i] = refine->str[refine->i];
	ft_free(&refine->new_str);
	refine->new_str = ptr;
	refine->j = i + 1;
	refine->i++;
}

void	exitnum_str(t_mini *mini, t_refine *refine)
{
	char	*exitnum;
	char	*tmp;

	exitnum = ft_itoa(mini->sig->exitnum);
	refine->new_str[refine->j] = '\0';
	tmp = ft_strjoin(refine->new_str, exitnum);
	ft_free(&exitnum);
	ft_free(&refine->new_str);
	refine->new_str = tmp;
	refine->i += 2;
	refine->j = ft_strlen(refine->new_str);
}
