/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/28 16:39:42 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	error_symbol(char symbol)
{
	printf("minishell: syntax error near unexpected token `%c'\n", symbol);
}

void	error_1(char *cmd, char *msg)
{
	printf("minishell: %s: %s\n", cmd, msg);
}

void	error_2(char *cmd, char *argv, char *msg)
{
	printf("minishell: %s: %s: %s\n", cmd, argv, msg);
}

void	ft_error(void)
{
	printf("Minishell error !!!\n");
	exit_num_set(1);
	exit(g_exit_state);
}
