/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/10/19 13:40:55 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_resource(t_mini *mini)
{
	
}

int	execute_command(t_mini *mini)
{
	return (0);	
}

int	check_command(t_mini *mini)
{
	return (0);
}

int	is_exit(t_mini *mini) // 종료 시그널 체크 함수
{
	if (mini->exit_flag == 0)
		return (0);
	else if (mini->exit_flag == 1)
		return (1);
}

int	new_prompt(t_mini *mini) // 프롬프트 생성 함수
{
	printf("%s: ", mini->pwd);
	mini->line = readline("");
	add_history(mini->line);
	return (0);
}

int	minishell_init(t_mini **mini)
{
	*mini = (t_mini *)malloc(sizeof(t_mini));
	if (*mini == NULL)
		return (1);
	(*mini)->line = NULL;
	(*mini)->exit_flag = 0;
	return (0);
}

int	loop_init(t_mini *mini) // 현재 위치 갱신 함수
{
	mini->pwd = ft_strdup();
	if (mini->pwd == NULL)
		return (1);
	return (0);
}

int	main(int argc, const char **argv) // return (1)은 에러 시그널
{
	t_mini	*mini;

	if ((minishell_init(&mini)) == 1)
		exit(1);
	while (1)
	{
		if ((loop_init(mini)) == 1)
			continue ;
		new_prompt(mini);
		if ((is_exit(mini)) == 1)
			break ;
		if ((check_command(mini)) == 1)
			continue ;
		mini->exit_flag = execute_command(mini);
	}
	free_resource(mini);
	return (0);
}
