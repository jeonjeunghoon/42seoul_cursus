/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:29:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/26 17:44:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_envname_export(char *argv)
{
	int		i;
	int		size;
	char	*res;

	size = 0;
	while (argv[size] && argv[size] != '=')
		size++;
	if (argv[size] != '=')
		return (NULL);
	res = (char *)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	i = 0;
	while (i < size && argv[i])
	{
		res[i] = argv[i];
		i++;
	}
	return (res);
}

int	is_valid_export(char *argv, int i)
{
	if ((argv[i] != '_' && argv[i] != '=' && \
		!(argv[i] >= 'a' && argv[i] <= 'z') && \
		!(argv[i] >= 'A' && argv[i] <= 'Z') && \
		!(argv[i] >= '0' && argv[i] <= '9')) || \
		(argv[0] >= '0' && argv[0] <= '9') || \
		(argv[0] == '='))
		return (ERROR);
	return (0);
}
