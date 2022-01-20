/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:35 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/20 19:08:28 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**create_new_envp(char ***envp, char *offset)
{
	char	**new;
	int		size;
	int		i;
	int		j;
	int		k;

	size = ft_two_dimension_size(*envp) - ft_strlen(offset);
	new = (char **)malloc(sizeof(char *) * size);
	new[size - 1] = NULL;
	i = 0;
	j = 0;
	k = 0;
	while (i < size && (*envp)[j])
	{
		if (j == offset[k])
		{
			j++;
			k++;
		}
		new[i] = ft_strdup((*envp)[j]);
		printf("new[%d]=%s\n", i, new[i]);
		i++;
		j++;
	}
	printf("size======%d\n", ft_two_dimension_size(new)); // 이부분 진짜 이상함
	ft_two_dimension_free((*envp));
	*envp = NULL;
	return (new);
}

void	get_offset(char *offset, char **envp, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		if (ft_getenv(envp, argv[i]) != NULL)
		{
			j = 0;
			while (envp[j])
			{
				if (ft_strncmp(envp[j], argv[i], ft_strlen(argv[i])) == 0)
				{
					offset[k] = j;
					k++;
				}
				j++;
			}
		}
		i++;
	}
}

void	offset_init(char **offset, char **envp, char **argv)
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
	*offset = (char *)malloc(sizeof(char) * (size + 1));
	(*offset)[size] = '\0';
}

void	ft_unset(t_mini *mini, char **argv)
{
	int		i;
	char	*offset;

	mini->flag->minicmd_flag = TRUE;
	i = 1;
	if (ft_two_dimension_size(argv) > 1)
	{
		// printf("1\n");
		offset_init(&offset, mini->envp, argv);
		// printf("2\n");
		get_offset(offset, mini->envp, argv);
		if (ft_strlen(offset) != 0)
			mini->envp = create_new_envp(&(mini->envp), offset);
		// printf("3\n");
		free(offset);
		offset = NULL;
	}
	exit_num_set(EXIT_SUCCESS);
	return ;
}
