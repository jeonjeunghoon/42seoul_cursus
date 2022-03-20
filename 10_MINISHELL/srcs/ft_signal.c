/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:52:37 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/03 21:01:56 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sigquit_func(int signum)
{
	if (signum != SIGQUIT)
		return ;
	printf("Quit: 3\n");
	g_sig->exitnum = 131;
}

void	sigint_func(int signum)
{
	if (signum != SIGINT)
		return ;
	if (g_sig->type == BASIC || g_sig->type == HEREDOC)
	{
		if (g_sig->type == BASIC)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
		}
		else
		{
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
			g_sig->signum = SIGINT;
		}
		exit_num_set(1);
	}
	else
	{
		printf("\n");
		g_sig->exitnum = 130;
	}
}

void	ft_signal(void)
{
	if (g_sig->type == BASIC)
		signal(SIGINT, sigint_func);
	else if (g_sig->type == HEREDOC)
		signal(SIGINT, sigint_func);
	else if (g_sig->type == EXECVE)
		signal(SIGINT, sigint_func);
	if (g_sig->type == BASIC || g_sig->type == HEREDOC)
		signal(SIGQUIT, SIG_IGN);
	else
		signal(SIGQUIT, sigquit_func);
}
