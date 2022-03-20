/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:51:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/04 16:45:34 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	dollar_str(t_mini *mini, t_refine *refine)
{
	if (refine->str[refine->i + 1] == '?')
		exitnum_str(mini, refine);
	else if (refine->str[refine->i + 1] == '*')
		refine->i += 2;
	else if ((refine->str[refine->i + 1] == '\'' || \
			refine->str[refine->i + 1] == '\"') && \
			refine->is_basic == TRUE)
		refine->i++;
	else if (refine->str[refine->i + 1] >= '0' && \
			refine->str[refine->i + 1] <= '9')
		num_after_dollor(refine);
	else if ((refine->str[refine->i + 1] >= 'a' && \
			refine->str[refine->i + 1] <= 'z') || \
			(refine->str[refine->i + 1] >= 'A' && \
			refine->str[refine->i + 1] <= 'Z') || \
			(refine->str[refine->i + 1] >= '0' && \
			refine->str[refine->i + 1] <= '9') || \
			refine->str[refine->i + 1] == '_')
		env_after_dollor(refine);
	else
		basic_str(refine);
}

void	double_quote_str(t_mini *mini, t_refine *refine)
{
	refine->is_double = TRUE;
	refine->is_basic = FALSE;
	while (refine->str[refine->i] == '\"' && refine->str[refine->i] != '\0')
		refine->i++;
	while (refine->str[refine->i] != '\"' && refine->str[refine->i] != '\0')
	{
		if (refine->str[refine->i] == '$')
			dollar_str(mini, refine);
		else
			basic_str(refine);
	}
	while (refine->str[refine->i] == '\"' && refine->str[refine->i] != '\0')
		refine->i++;
	if (!mini->wild_chk && refine->new_str[0] == '\0')
		ft_strlcpy(refine->new_str, refine->str, ft_strlen(refine->str) + 1);
	refine->is_double = FALSE;
	refine->is_basic = TRUE;
}

void	single_quote_str(t_mini *mini, t_refine *refine)
{
	int	num;

	num = 0;
	refine->is_single = TRUE;
	refine->is_basic = FALSE;
	while (refine->str[refine->i] == '\'' && refine->str[refine->i] != '\0')
	{
		refine->i++;
		num++;
	}
	while (refine->str[refine->i] != '\'' && refine->str[refine->i] != '\0')
	{
		if (num % 2 == 0 && refine->str[refine->i] == '$')
			dollar_str(mini, refine);
		else
			basic_str(refine);
	}
	while (refine->str[refine->i] == '\'' && refine->str[refine->i] != '\0')
		refine->i++;
	if (!mini->wild_chk && refine->new_str[0] == '\0')
		ft_strlcpy(refine->new_str, refine->str, ft_strlen(refine->str) + 1);
	refine->is_single = FALSE;
	refine->is_basic = TRUE;
}

void	swung_dash_str(t_refine *refine)
{
	if ((refine->str[refine->i + 1] == '\0' || \
		refine->str[refine->i + 1] == '/') && \
		refine->i == 0)
	{
		refine->i++;
		refine->env = ft_getenv(refine->envp, "HOME");
		if (refine->env == NULL)
			ft_error("$Home env error", 1);
		else
			env_str(refine);
	}
	else
		basic_str(refine);
}

int	create_refined_str(t_mini *mini, t_refine *refine)
{
	int	len;
	int	i;

	len = ft_strlen(refine->str);
	refine->new_str = (char *)malloc(sizeof(char) * (len + 1));
	refine->new_str[len] = '\0';
	i = 0;
	while (i < len)
		refine->new_str[i++] = '\0';
	while (refine->str[refine->i])
	{
		if (refine->str[refine->i] == '~' && mini->wild_chk == 0)
			swung_dash_str(refine);
		else if (refine->str[refine->i] == '\'')
			single_quote_str(mini, refine);
		else if (refine->str[refine->i] == '\"')
			double_quote_str(mini, refine);
		else if (refine->str[refine->i] == '$')
			dollar_str(mini, refine);
		else
			basic_str(refine);
	}
	if (refine->new_str[0] == '\0')
		return (ERROR);
	return (0);
}
