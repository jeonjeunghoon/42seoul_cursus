/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:51:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 17:55:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	basic_str(t_refine *refine)
{
	(refine->new_str)[(refine->j)] = (refine->str)[(refine->i)];
	(refine->i)++;
	(refine->j)++;
}

void	dollar_str(t_refine *refine)
{
	if (refine->str[refine->i + 1] == '\0' || refine->str[refine->i + 1] == '\"')
		basic_str(refine);
	else if (refine->str[refine->i + 1] == '?')
	{
		exitnum_str(refine);
	}
	else
	{
		(refine->i)++;
		refine->name = get_envname_parse(refine->str, &(refine->i));
		refine->env = ft_getenv(refine->envp, refine->name);
		ft_free(&(refine->name));
		if (refine->env == NULL)
		{
			if (refine->str[refine->i] != '\"' || refine->str[refine->i] != '\0')
			{
				(refine->new_str)[(refine->j)] = '$';
				refine->j++;
			}
			return ;
		}
		env_str(refine);
	}
}

void	double_quote_str(t_refine *refine)
{
	if ((refine->str)[(refine->i)] == '\"')
		(refine->i)++;
	while ((refine->str)[(refine->i)] && (refine->str)[(refine->i)] != '\"')
	{
		if ((refine->str)[(refine->i)] == '$')
			dollar_str(refine);
		else
			basic_str(refine);
	}
	if ((refine->str)[(refine->i)] == '\"')
		(refine->i)++;
}

void	single_quote_str(t_refine *refine)
{
	if ((refine->str)[refine->i] == '\'')
		(refine->i)++;
	while ((refine->str)[refine->i] && (refine->str)[refine->i] != '\'')
		basic_str(refine);
	if ((refine->str)[refine->i] == '\'')
		(refine->i)++;
}

void	create_refined_str(t_refine *refine)
{
	refine->new_str = (char *)malloc(sizeof(char) * \
						(ft_strlen(refine->str) + 1));
	refine->new_str[ft_strlen(refine->str)] = '\0';
	while ((refine->str)[refine->i])
	{
		if ((refine->str)[refine->i] == '\'')
			single_quote_str(refine);
		else if ((refine->str)[refine->i] == '\"')
			double_quote_str(refine);
		else if ((refine->str)[refine->i] == '$')
			dollar_str(refine);
		else
			basic_str(refine);
	}
}
