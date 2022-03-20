/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/02 16:09:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	error_symbol(char *symbol, int exitnum)
{
	write(2, "-minishell: syntax error near unexpected token `", 49);
	write(2, symbol, ft_strlen(symbol));
	write(2, "'\n", 3);
	exit_num_set(exitnum);
}

void	error_2(char *cmd, char *argv, char *msg, int exitnum)
{
	write(2, "-minishell: ", 13);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, argv, ft_strlen(argv));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit_num_set(exitnum);
}

void	error_1(char *cmd, char *msg, int exitnum)
{
	write(2, "-minishell: ", 13);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit_num_set(exitnum);
}

void	ft_error(char *msg, int exitnum)
{
	write(2, "-minishell: ", 13);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit_num_set(exitnum);
}
