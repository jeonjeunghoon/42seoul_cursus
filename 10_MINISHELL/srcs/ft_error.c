/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/20 15:48:55 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	too_many_arguments(char *cmd)
{
	printf("%s: too many arguments\n", cmd);
	exit_num_set(1);
}

void	command_not_found(char *cmd)
{
	printf("minishell: command not found: %s\n", cmd);
	exit_num_set(127);
}

void	error_msg(char *cmd, char *argv, char *msg)
{
	printf("minishell: %s: %s: %s\n", cmd, argv, msg);
	exit_num_set(1);
}

void	ft_error(void)
{
	printf("Minishell error !!!\n");
	exit_num_set(1);
	exit(1);
}
