/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/12/29 18:14:56 by jeunjeon         ###   ########.fr       */
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

int	loop_init(t_mini *mini) // 현재 위치 갱신 함수
{
	char	**splited_strs;
	char	*working_dir;
	int		strs_len;

	getcwd(mini->pwd, 1024);
	if (mini->pwd == NULL)
		return (-1);
	splited_strs = ft_split(mini->pwd, '/');
	strs_len = ft_veclen(splited_strs);
	// strs_len을 이용해 working_dir 문자열 완성
	// working_dir과 usr 문자열을 이용해 프롬프트 표시 문자열 완성
	// splited_strs 프리 필요
	return (0);
}

int	minishell_init(t_mini **mini)
{
	*mini = (t_mini *)malloc(sizeof(t_mini));
	if (*mini == NULL)
		return (-1);
	(*mini)->pwd = (char *)malloc(sizeof(char) * 1024);
	if ((*mini)->pwd == NULL)
		return (-1);
	(*mini)->exit_flag = 0;
	return (0);
}

int	main(int argc, const char **argv) // return (1)은 에러 시그널
{
	t_mini	*mini;
	/*
	구조체를 포인터로 선언하는 이유는 함수로 넘어갈 때 매개변수가 복사되어 넘어간다
	구조체가 커질 수록 메모리 관리에 비효율적이다.
	*/

	if ((minishell_init(&mini)) == -1)
		error_func(mini);
	while (1)
	{
		if ((loop_init(mini)) == -1)
			error_func(mini);
		new_prompt(mini);
		is_exit(mini);
		check_command(mini);
		execute_command(mini);
		free(mini->line);
	}
	return (0);
}
