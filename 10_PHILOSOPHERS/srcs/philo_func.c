/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/27 14:46:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	wait_create_thread(t_base *base, t_arg *arg, t_philo *philo)
{
	while (1)
	{
		if (base->thread_index == arg->num_philo - 1)
		{
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
	wait_create_thread(base, arg, philo);
	if (philo->num % 2 == 1)
		usleep(100 * (arg->num_philo - base->thread_index));
	if ((is_die(base, arg, philo)) == IS_DIE)
		return ((void **)IS_DIE);
	while (1)
	{
		if ((philo_act(base, arg, philo)) == IS_DIE)
			return ((void **)IS_DIE);
	}
}

int	philo_func(t_base *base, t_arg *arg, t_philo *philo)
{
	int		i;
	void	**value_ptr;

	i = 0;
	while (i < arg->num_philo)
	{
		base->thread_index = i;
		if (base->thread_index == arg->num_philo - 2)
			base->timestamp_start_ms = get_time_ms();
		pthread_create(philo[i].thread, base->attr, \
						(void *)philo_routine, (void *)base->routine_arg);
		usleep(200);
		i++;
	}
	value_ptr = NULL;
	i = 0;
	while (i < arg->num_philo)
	{
		pthread_join(*(philo[i].thread), value_ptr);
		i++;
	}
	return (0);
}
