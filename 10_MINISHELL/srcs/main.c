/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/12/27 17:31:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	error_func(t_mini *mini)
{
	exit(1);
}

void	free_resource(t_mini **mini)
{
	free((*mini)->line);
	free((*mini)->cmd);
	free((*mini)->locate);
	free((*mini)->pwd);
	free((*mini));
}

void	execute_command(t_mini *mini)
{

}

void	check_command(t_mini *mini)
{
	
}

void	is_exit(t_mini *mini) // 종료 시그널 체크 함수
{
	if (mini->exit_flag == 0)
		return ;
	free_resource(&mini);
	exit(0);
}

void	new_prompt(t_mini *mini) // 프롬프트 생성 함수
{
	char	*str;

	str = NULL;
	printf("%s ", mini->locate);
	str = readline("");
	mini->cmd = ft_strdup(str);
	add_history(str);
	free(str);
}

void	loop_init(t_mini *mini) // 현재 위치 갱신 함수
{
	char	**split_str;
	int		i;

	getcwd(mini->pwd, 1024);
	split_str = ft_split(mini->pwd, '/');
	if (split_str == NULL)
		error_func(mini);
	i = 0;
	while (split_str[i])
		i++;
	if (i == 2)
		mini->locate = ft_strdup("~");
	else
		mini->locate = ft_strdup(split_str[i - 1]);
	i = 0;
	while (split_str[i])
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
}

void	minishell_init(t_mini **mini)
{
	*mini = (t_mini *)malloc(sizeof(t_mini));
	if (*mini == NULL)
		error_func(*mini);
	(*mini)->pwd = (char *)malloc(sizeof(char) * 1024);
	if ((*mini)->pwd == NULL)
		error_func(*mini);
	(*mini)->exit_flag = 0;
}

int	main(int argc, const char **argv) // return (1)은 에러 시그널
{
	t_mini	*mini; // 구조체를 포인터로 선언하는 이유는 함수로 넘어갈 때 매개변수가 복사되어 넘어간다/구조체가 커질 수록 메모리 관리에 비효율적이다.

	minishell_init(&mini);
	while (1)
	{
		loop_init(mini);
		new_prompt(mini);
		is_exit(mini);
		check_command(mini);
		execute_command(mini);
		free(mini->line);
	}
	return (0);
}
