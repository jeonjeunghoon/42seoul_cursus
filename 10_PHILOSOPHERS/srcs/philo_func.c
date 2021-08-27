/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/28 01:16:33 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	wait_create_thread(t_base *base, t_arg *arg, t_philo *philo)
{
	while (1)
	{
		if (base->thread_index == arg->num_philo - 1)
		{
			usleep(100);
			philo->start_ms = base->timestamp_start_ms;
			break ;
		}
	}
}

void	*philo_routine(void *routine_arg)
{
	t_base	*base;
	t_arg	*arg;
	t_philo	*philo;

	base = (t_base *)routine_arg;
	arg = base->arg;
	philo = &(base->philo[base->thread_index]);
	philo->num = base->thread_index;
	base->timestamp_start_ms = get_time_ms();
	pthread_mutex_lock(&(base->ft_mutex));
	wait_create_thread(base, arg, philo);
	pthread_mutex_unlock(&(base->ft_mutex));
	if (philo->num % 2 == 1)
		usleep(200 * (arg->num_philo - philo->num + 1));
	if ((act_except(base, arg, philo)) == IS_DIE)
		return ((void **)IS_DIE);
	while (base->is_die != IS_DIE)
	{
		if ((take_fork(base, arg, philo)) == IS_DIE)
			break ;
		if ((eating(base, arg, philo)) == IS_DIE)
			break ;
		if ((put_fork(base, arg, philo)) == IS_DIE)
			break ;
		if ((sleeping(base, arg, philo)) == IS_DIE)
			break ;
		if ((thinking(base, arg, philo)) == IS_DIE)
			break ;
		if (arg->num_eat > 0)
		{
			if ((is_done(base, arg, philo)) == IS_DIE)
				break ;
		}
	}
	return ((void **)IS_DIE);
}

int	philo_func(t_base *base, t_arg *arg, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < arg->num_philo)
	{
		base->thread_index = i;
		pthread_create(philo[base->thread_index].thread, base->attr, \
						(void *)philo_routine, (void *)base->routine_arg);
		usleep(200);
		i++;
	}
	i = 0;
	while (i < arg->num_philo)
	{
		pthread_join(*(philo[i].thread), NULL);
		i++;
	}
	return (0);
}
