/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbol_utility2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:10:41 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/06 16:08:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_bool	is_symbol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_stream(str[i]) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	symbol_free(char **symbol, char **near_symbol)
{
	if (*symbol != NULL)
		ft_free(symbol);
	if (*near_symbol != NULL)
		ft_free(near_symbol);
}

void	refine_heredoc(t_mini *mini, char **input)
{
	t_refine	*refine;

	refine = (t_refine *)malloc(sizeof(t_refine));
	refine_init(refine);
	refine->envp = mini->export_list;
	refine->str = *input;
	create_refined_str(mini, refine);
	ft_free(input);
	*input = ft_strdup(refine->new_str);
	ft_free(&refine->new_str);
	refine_init(refine);
	free(refine);
	refine = NULL;
}

void	heredoc_catch_signal(void)
{
	if (g_sig->signum != SIGINT)
	{
		ft_putstr_fd("\x1b[1A", STDOUT_FILENO);
		ft_putstr_fd("> ", STDOUT_FILENO);
	}
}

t_bool	is_signal_heredoc(char *input)
{
	if (g_sig->signum == SIGINT || input == NULL)
	{
		heredoc_catch_signal();
		unlink(".heredoc_tmp");
		return (SIGNAL);
	}
	return (FALSE);
}
