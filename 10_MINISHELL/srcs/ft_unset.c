/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:35 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/20 23:49:59 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_numlen(int *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != -1)
		i++;
	return (i);
}

char	**create_new_envp(char **envp, int *offset)
{
	char	**new;
	int		size;
	int		i;
	int		j;
	int		k;

	size = ft_two_dimension_size(envp) - ft_numlen(offset);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	i = 0;
	j = 0;
	k = 0;
	while (i < size && envp[j])
	{
		if (j == offset[k] && offset[k] != -1)
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

void	get_offset(int *offset, char **envp, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*envname;

	i = 1;
	k = 0;
	while (argv[i])
	{
		if (ft_getenv(envp, argv[i]) != NULL)
		{
			j = 0;
			envname = get_envname(argv[i]);
			while (envp[j] && offset[k] != -1)
			{
				if (ft_strncmp(envp[j], envname, ft_strlen(envname)) == 0)
					offset[k++] = j;
				j++;
			}
			free(envname);
			envname = NULL;
		}
		i++;
	}
}

void	offset_init(int **offset, char **envp, char **argv)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (argv[i] != NULL)
	{
		if (ft_getenv(envp, argv[i]) != NULL)
			size++;
		i++;
	}
	*offset = (int *)malloc(sizeof(int) * (size + 1));
	(*offset)[size] = -1;
	i = 0;
	while ((*offset)[i] != -1)
	{
		(*offset)[i] = 0;
		i++;
	}
}

void	ft_unset(t_mini *mini, char **argv)
{
	int		*offset;
	char	**new;

	mini->flag->minicmd_flag = TRUE;
	if (ft_two_dimension_size(argv) > 1)
	{
		offset_init(&offset, mini->envp, argv);
		get_offset(offset, mini->envp, argv);
		if (ft_numlen(offset) != 0)
		{
			new = create_new_envp(mini->envp, offset);
			ft_two_dimension_free(&(mini->envp));
			mini->envp = new;
		}
		free(offset);
		offset = NULL;
	}
	exit_num_set(EXIT_SUCCESS);
}
