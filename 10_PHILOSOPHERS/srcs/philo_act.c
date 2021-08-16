/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/16 22:07:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	sleeping(t_philo *philo, int *start, int *end)
{
	usleep(philo->arg->time_to_sleep * 1000);
	if ((is_dead(start, end, philo)) == IS_DEAD)
			return (IS_DEAD);
	return (0);
}

int	switch_fork(int left_fork, int right_fork)
{
	if (left_fork == 1 && right_fork == 1)
	{
		left_fork = 0;
		right_fork = 0;
	}
	else if (left_fork == 0 && right_fork == 0)
	{
		left_fork = 1;
		right_fork = 1;
	}
	else
		return (IS_ERROR);
	return (0);
}

int	eating(t_philo *philo, int order)
{
	pthread_mutex_lock(&g_mutex);
	switch_fork(philo->fork[(order + 1) % philo->arg->num_of_fork], \
				philo->fork[order]);
	usleep(philo->arg->time_to_eat * 1000);
	switch_fork(philo->fork[(order + 1) % philo->arg->num_of_fork], \
				philo->fork[order]);
	pthread_mutex_unlock(&g_mutex);
	return (0);
}

int	philo_act(t_philo *philo, int order, int *start, int *end)
{
	if ((is_dead(start, end, philo)) == IS_DEAD)
			return (IS_DEAD);
	while (1)
	{
		get_time(start, philo->die_start);
		if (philo->fork[(order + 1) % philo->arg->num_of_fork] && \
			philo->fork[order])
		{
			if ((is_dead(start, end, philo)) == IS_DEAD)
				return (IS_DEAD);
			eating(philo, order);
			get_time(start, philo->die_start);
			break ;
		}
		if ((is_dead(start, end, philo)) == IS_DEAD)
			return (IS_DEAD);
	}
	if ((is_dead(start, end, philo)) == IS_DEAD)
			return (IS_DEAD);
	get_time(start, philo->die_start);
	sleeping(philo, start, end);
	get_time(start, philo->die_start);
	return (0);
}
