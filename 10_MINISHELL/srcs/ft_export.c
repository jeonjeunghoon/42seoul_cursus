/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/20 11:34:48 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_export(char **export_list)
{
	int		i;
	int		j;

	i = 0;
	while (export_list[i] != NULL)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		j = 0;
		while (export_list[i][j])
		{
			ft_putchar_fd(export_list[i][j], STDOUT_FILENO);
			if (export_list[i][j] == '=')
				break ;
			j++;
		}
		j++;
		if (export_list[i][j] != '\0')
		{
			ft_putchar_fd('\"', STDOUT_FILENO);
			ft_putstr_fd(&(export_list[i][j]), STDOUT_FILENO);
			ft_putchar_fd('\"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

void	export_list(char ***list, t_argv *argv, int i)
{
	char	**new_list;

	new_list = NULL;
	new_list = create_export_envp(*list, argv->argv[i]);
	ft_two_dimension_free(list);
	*list = new_list;
}

int	check_export_argv(char *argv)
{
	int		i;
	char	*error_msg;
	t_bool	is_env;

	is_env = FALSE;
	i = 0;
	while (argv[i])
	{
		if (is_valid_export(argv, i) == ERROR)
		{
			error_msg = ft_strjoin_bothside("`", argv, "'");
			error_2("export", error_msg, "not a valid identifier", 1);
			ft_free(&error_msg);
			return (ERROR);
		}
		if (argv[i] == '=')
			is_env = TRUE;
		i++;
	}
	return (is_env);
}

void	ft_export(t_mini *mini, t_argv *argv)
{
	int		i;
	int		ret;

	exit_num_set(0);
	if (ft_two_dimension_size(argv->argv) > 1)
	{
		i = 1;
		while (argv->argv[i])
		{
			ret = check_export_argv(argv->argv[i]);
			if (ret != ERROR)
			{
				export_list(&(mini->export_list), argv, i);
				if (ret == TRUE)
					export_list(&(mini->env_list), argv, i);
			}
			i++;
		}
	}
	else
		print_export(mini->export_list);
}
