/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/20 17:09:31 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ftd_usleep_divide(long long set_usleep)
{
	long long	time;

	time = get_time_ms();
	while (time < set_usleep)
		usleep(100);
}

int	sleeping(t_base base, t_arg arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	is_dead(base, arg, *philo);
	philo->num_sleeping++;
	usleep(arg.time_sleep_ms * 1000);
	philo->end_time = get_time_ms();
	is_dead(base, arg, *philo);
	return (0);
}

int	switch_fork(t_base base, t_arg arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	is_dead(base, arg, *philo);
	if (philo->left_fork == 1 && philo->right_fork == 1)
	{
		philo->left_fork = 0;
		philo->right_fork = 0;
	}
	else if (philo->left_fork == 0 && philo->right_fork == 0)
	{
		philo->left_fork = 1;
		philo->right_fork = 1;
	}
	else
		return (IS_ERROR);
	return (0);
}

int	eating(t_base base, t_arg arg, t_philo *philo)
{
	switch_fork(base, arg, philo);
	philo->num_eating++;
	usleep(arg.time_eat_ms * 1000);
	philo->start_time = get_time_ms();
	switch_fork(base, arg, philo);
	return (0);
}

int	philo_act(t_base base, t_arg arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	is_dead(base, arg, *philo);
	while (1)
	{
		philo->end_time = get_time_ms();
		is_dead(base, arg, *philo);
		if (base.fork[philo->left_fork] == 1 && \
			base.fork[philo->right_fork] == 1)
		{
			pthread_mutex_lock(&g_mutex);
			eating(base, arg, philo);
			pthread_mutex_unlock(&g_mutex);
			if (arg.num_eat > 0 && (philo->num_eating == arg.num_eat))
			{
				printf("thread[%d] is exit\n", philo->num);
				return (IS_DONE);
			}
			break ;
		}
	}
	sleeping(base, arg, philo);
	printf("\nthread[%d]\nnum_eating = %lld num_sleeping = %lld num_thinking = %lld\n", philo->num, philo->num_eating, philo->num_sleeping, philo->num_thinking);
	printf("-------------------------------------------------------------------------\n\n\n");
	return (0);
}
