/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:51:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 22:36:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	basic_str(t_refine *refine)
{
	refine->new_str[refine->j] = refine->str[refine->i];
	refine->i++;
	refine->j++;
}

void	dollar_str(t_refine *refine)
{
	if (refine->str[refine->i + 1] == '\0')
		basic_str(refine);
	else if ((refine->str[refine->i + 1] == '\'' || \
			refine->str[refine->i + 1] == '\"') && refine->is_basic == TRUE)
		refine->i++;
	else if (refine->str[refine->i + 1] == '?')
		exitnum_str(refine);
	else
	{
		refine->i++;
		refine->name = get_envname_parse(refine->str, &refine->i);
		refine->env = ft_getenv(refine->envp, refine->name);
		ft_free(&refine->name);
		if (refine->env == NULL)
		{
			if (refine->str[refine->i] != '\"' || \
				refine->str[refine->i] != '\0')
			{
				refine->new_str[refine->j] = '$';
				refine->j++;
			}
		}
		else
			env_str(refine);
	}
}

void	double_quote_str(t_refine *refine)
{
	refine->is_double = TRUE;
	refine->is_basic = FALSE;
	if (refine->str[refine->i] == '\"')
		refine->i++;
	while (refine->str[refine->i] && refine->str[refine->i] != '\"')
	{
		if (refine->str[refine->i] == '$')
			dollar_str(refine);
		else
			basic_str(refine);
	}
	if (refine->str[refine->i] == '\"')
		refine->i++;
	refine->is_double = FALSE;
	refine->is_basic = TRUE;
}

void	single_quote_str(t_refine *refine)
{
	refine->is_single = TRUE;
	refine->is_basic = FALSE;
	if (refine->str[refine->i] == '\'')
		(refine->i)++;
	while (refine->str[refine->i] && refine->str[refine->i] != '\'')
		basic_str(refine);
	if (refine->str[refine->i] == '\'')
		(refine->i)++;
	refine->is_single = FALSE;
	refine->is_basic = TRUE;
}

void	create_refined_str(t_refine *refine)
{
	int	len;

	len = ft_strlen(refine->str);
	refine->new_str = (char *)malloc(sizeof(char) * (len + 1));
	refine->new_str[len] = '\0';
	while (refine->str[refine->i])
	{
		if (refine->str[refine->i] == '\'')
			single_quote_str(refine);
		else if (refine->str[refine->i] == '\"')
			double_quote_str(refine);
		else if (refine->str[refine->i] == '$')
			dollar_str(refine);
		else
			basic_str(refine);
	}
	if (refine->str[refine->i] == '\0')
		refine->new_str[refine->j] = '\0';
}
