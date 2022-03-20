/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:35 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/06 17:11:38 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_unset_argv(char **argv, int *size)
{
	int		i;
	int		j;
	char	*msg_argv;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] != '_' \
				&& !(argv[i][j] >= 'a' && argv[i][j] <= 'z') \
				&& !(argv[i][j] >= 'A' && argv[i][j] <= 'Z') \
				&& !(argv[i][j] >= '0' && argv[i][j] <= '9')) \
				|| (argv[i][0] >= '0' && argv[i][0] <= '9'))
			{
				msg_argv = ft_strjoin_bothside("`", argv[i], "'");
				error_2(argv[0], msg_argv, "not a valid identifier", 1);
				free(msg_argv);
				(*size)--;
				return (ERROR);
			}
		}
	}
	return (0);
}

void	unset_list(char ***list, t_argv *argv)
{
	int		size;
	int		*position;
	char	**new_list;

	position = NULL;
	new_list = NULL;
	size = ft_two_dimension_size(argv->argv) - 1;
	position_init(&position, &size, *list, argv->argv);
	get_position(position, *list, argv->argv);
	size = ft_two_dimension_size(*list) - ft_numlen(position);
	new_list = create_unset_envp(*list, position, size);
	ft_two_dimension_free(list);
	*list = new_list;
	free(position);
	position = NULL;
}

void	ft_unset(t_mini *mini, t_argv *argv)
{
	int		size;

	exit_num_set(0);
	size = ft_two_dimension_size(argv->argv) - 1;
	if (size == 0)
		return ;
	if (check_unset_argv(argv->argv, &size) == ERROR)
		return ;
	if (size != 0)
	{
		unset_list(&(mini->env_list), argv);
		unset_list(&(mini->export_list), argv);
	}
}
