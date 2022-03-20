/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:11:15 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/06 17:12:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**create_unset_envp(char **envp, int *position, int size)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	i = 0;
	j = 0;
	k = 0;
	while (i < size && envp[j])
	{
		if (j == position[k] && position[k] != -1)
		{
			j++;
			k++;
		}
		new[i] = ft_strdup(envp[j]);
		i++;
		j++;
	}
	return (new);
}

void	get_position(int *position, char **envp, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*envname;

	i = 0;
	k = 0;
	while (argv[++i])
	{
		if (ft_getenv(envp, argv[i]) != NULL)
		{
			envname = get_envname(argv[i]);
			j = -1;
			while (envp[++j] && position[k] != -1)
			{
				if (ft_strncmp(envp[j], envname, ft_strlen(envname) - 1) == 0 \
				&& (envp[j][ft_strlen(envname) - 1] == '=' \
				|| envp[j][ft_strlen(envname) - 1] == '\0'))
					position[k++] = j;
			}
			free(envname);
			envname = NULL;
		}
	}
}

void	position_init(int **position, int *size, char **envp, char **argv)
{
	int	i;

	*size = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_getenv(envp, argv[i]) != NULL)
			(*size)++;
		i++;
	}
	*position = (int *)malloc(sizeof(int) * ((*size) + 1));
	(*position)[(*size)] = -1;
	i = 0;
	while ((*position)[i] != -1)
	{
		(*position)[i] = 0;
		i++;
	}
	(*size) = 0;
}
