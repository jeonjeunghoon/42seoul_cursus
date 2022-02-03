/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:56:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 18:04:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	exitnum_str(t_refine *refine)
{
	char	*exit_num;
	char	*tmp_str;
	int		len;
	int		i;
	int		j;
	
	exit_num = ft_itoa(g_exit_state);
	len = ft_strlen(exit_num) + ft_strlen(refine->new_str);
	tmp_str = malloc(sizeof(char) * (len + 1));
	tmp_str[len] = '\0';
	i = 0;
	refine->new_str[refine->j] = '\0';
	while (refine->new_str[i] && i < refine->j)
	{
		tmp_str[i] = refine->new_str[i];
		i++;
	}
	j = 0;
	while (exit_num[j])
	{
		tmp_str[i] = exit_num[j];
		i++;
		j++;
	}
	free(exit_num);
	exit_num = NULL;
	free(refine->new_str);
	refine->new_str = ft_strdup(tmp_str);
	free(tmp_str);
	refine->i += 2;
	refine->j = i;
}
