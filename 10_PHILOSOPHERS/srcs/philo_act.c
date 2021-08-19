/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/19 18:22:24 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	thinking(t_philo *philo)
{
	// printf("thread[%d] : thinking . . .\n", philo->num);
	philo->num_thinking++;
	return ;
}

int	sleeping(t_base base, t_arg arg, t_philo *philo)
{
	printf("thread[%d] : sleeping . . .\n", philo->num);
	philo->num_sleeping++;
	usleep(arg.time_sleep * 1000);
	return (0);
}

int	switch_fork(int *left_fork, int *right_fork)
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

int	eating(t_base base, t_arg arg, t_philo *philo)
{
	printf("thread[%d] : get fork!\n", philo->num);
	switch_fork(&(base.fork[philo->left_fork]), \
				&(base.fork[philo->right_fork]));
	printf("fork status === %d %d\n", base.fork[philo->left_fork], base.fork[philo->right_fork]);

	printf("thread[%d] : eating . . .\n", philo->num);
	philo->num_eating++;
	usleep(arg.time_eat * 1000);
	printf("thread[%d] : finish eating\n", philo->num);

	printf("thread[%d] : put fork!\n", philo->num);
	switch_fork(&(base.fork[philo->left_fork]), \
				&(base.fork[philo->right_fork]));
	printf("fork status === %d %d\n", base.fork[philo->left_fork], base.fork[philo->right_fork]);
	return (0);
}

int	philo_act(t_base base, t_arg arg, t_philo *philo)
{
	while (1)
	{
		if (base.fork[philo->left_fork] == 1 && \
			base.fork[philo->right_fork] == 1)
		{
			pthread_mutex_lock(&g_mutex);
			eating(base, arg, philo);
			pthread_mutex_unlock(&g_mutex);
			break ;
		}
		else
			thinking(philo);
	}
	sleeping(base, arg, philo);
	printf("\nthread[%d]\nnum_eating = %lld num_sleeping = %lld num_thinking = %lld\n", philo->num, philo->num_eating, philo->num_sleeping, philo->num_thinking);
	printf("-------------------------------------------------------------------------\n\n\n");
	return (0);
}
