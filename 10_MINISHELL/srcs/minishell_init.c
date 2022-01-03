/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:48:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 10:57:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

int	minishell_init(t_mini **mini)
{
	*mini = (t_mini *)malloc(sizeof(t_mini));
	if (*mini == NULL)
		return (ERROR);
	(*mini)->env = (t_env *)malloc(sizeof(t_env));
	if ((*mini)->env == NULL)
		return (ERROR);
	prompt_init(*mini);
	return (0);
}
