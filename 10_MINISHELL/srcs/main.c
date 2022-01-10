/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 13:13:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, const char **argv)
{
	t_mini	*mini;

	mini = NULL;
	minishell_init(&mini);
	while (TRUE)
		ft_prompt(mini);
	return (0);
}
