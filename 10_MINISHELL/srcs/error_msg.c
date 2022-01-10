/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 15:29:07 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	too_many_arguments(char *cmd)
{
	printf("%s: too many arguments\n", cmd);
}

void	command_not_found(char *cmd)
{
	printf("minishell: command not found: %s\n", cmd);
}

void	error_msg(char *cmd, char *argv, char *msg)
{
	printf("minishell: %s: %s: %s\n", cmd, argv, msg);
}
