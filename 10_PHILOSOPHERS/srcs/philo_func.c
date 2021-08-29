/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/30 00:19:11 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo_act(t_base *base, t_arg *arg, t_philo *philo)
{
	if ((take_fork(base, arg, philo)) == IS_FINISH)
		return (IS_FINISH);
	if ((eating(base, arg, philo)) == IS_FINISH)
		return (IS_FINISH);
	if ((put_fork(base, arg, philo)) == IS_FINISH)
		return (IS_FINISH);
	if ((sleeping(base, arg, philo)) == IS_FINISH)
		return (IS_FINISH);
	if ((thinking(base, arg, philo)) == IS_FINISH)
		return (IS_FINISH);
	if (arg->num_eat > 0)
	{
		if ((is_done(base, arg, philo)) == IS_FINISH)
			return (IS_FINISH);
	}
	return (1);
}

void	wait_create_thread(t_base *base, t_arg *arg, t_philo *philo)
{
	while (1)
	{
		if (base->thread_index == arg->num_philo - 1)
		{
			philo->start_ms = base->timestamp_start_ms;
			usleep(100);
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
	pthread_mutex_lock(&(base->ft_mutex));
	base->timestamp_start_ms = get_time_ms();
	pthread_mutex_unlock(&(base->ft_mutex));
	wait_create_thread(base, arg, philo);
	if (philo->num % 2 == 1)
		usleep(200 * (arg->num_philo - philo->num + 1));
	if ((act_except(base, arg, philo)) == IS_FINISH)
		return ((void **)IS_FINISH);
	while (base->is_finish != IS_FINISH)
	{
		if ((philo_act(base, arg, philo)) == IS_FINISH)
			break ;
	}
	return ((void **)IS_FINISH);
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
