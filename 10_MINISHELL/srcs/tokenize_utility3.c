/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:56:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 22:19:14 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	create_exitnum_str(t_refine *refine, char *tmp, \
							char *exit_num, int tmp_len)
{
	int	i;
	int	j;
	int	new_len;

	new_len = ft_strlen(refine->new_str);
	i = 0;
	while (refine->new_str[i] && i < new_len)
	{
		tmp[i] = refine->new_str[i];
		i++;
	}
	j = 0;
	while (i < tmp_len && exit_num[j])
	{
		tmp[i] = exit_num[j];
		i++;
		j++;
	}
	refine->i += 2;
	refine->j = i;
}

void	exitnum_str(t_refine *refine)
{
	char	*exit_num;
	char	*tmp;
	int		len;

	exit_num = ft_itoa(g_exit_state);
	refine->new_str[refine->j] = '\0';
	len = ft_strlen(refine->new_str) + ft_strlen(exit_num);
	tmp = malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	create_exitnum_str(refine, tmp, exit_num, len);
	ft_free(&exit_num);
	ft_free(&refine->new_str);
	refine->new_str = ft_strdup(tmp);
	ft_free(&tmp);
}
