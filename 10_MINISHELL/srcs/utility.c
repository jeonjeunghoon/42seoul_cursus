/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/08 17:40:15 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	too_many_arguments(char *cmd)
{
	printf("%s: too many arguments\n", cmd);
}

void	command_not_found(char *cmd)
{
	printf("bash: command not found: %s\n", cmd);
}

void	error_msg(char *cmd, char *error_msg)
{
	printf("bash: %s: %s\n", cmd, error_msg);
}
