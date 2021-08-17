/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/17 18:28:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	thinking(void)
{
	return ;
}

int	sleeping(t_base *base)
{
	usleep(base->arg->time_sleep * 1000);
	return (0);
}

int	switch_fork(char *left_fork, char *right_fork)
{
	if (*left_fork == 1 && *right_fork == 1)
	{
		*left_fork = 0;
		*right_fork = 0;
	}
	else if (*left_fork == 0 && *right_fork == 0)
	{
		*left_fork = 1;
		*right_fork = 1;
	}
	else
		return (IS_ERROR);
	return (0);
}

int	eating(t_base *base)
{
	switch_fork(&(base->fork[base->philo->left_fork]), \
				&(base->fork[base->philo->right_fork]));
	printf("thread[%d] : get fork!\n", base->philo->num + 1);

	usleep(base->arg->time_eat * 1000);

	printf("thread[%d] : eating . . .\n", base->philo->num + 1);
	switch_fork(&(base->fork[base->philo->left_fork]), \
				&(base->fork[base->philo->right_fork]));
	printf("thread[%d] : put fork!\n\n", base->philo->num + 1);
	return (0);
}

int	philo_act(t_base *base)
{
	while (1)
	{
		if (base->fork[base->philo->left_fork] == 1 && \
			base->fork[base->philo->right_fork] == 1)
		{
			pthread_mutex_lock(&g_mutex);
			printf("thread[%d] : in fork\n", base->philo->num + 1);
			eating(base);
			pthread_mutex_unlock(&g_mutex);
			break ;
		}
		else
		{
			printf("thread[%d] : thinking . . .\n", base->philo->num + 1);
			thinking();
		}
	}
	sleeping(base);
	return (0);
}
