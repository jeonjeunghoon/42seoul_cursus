/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/25 17:38:05 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	wait_thread(t_base *base)
{
	while (1)
	{
		if (base->thread_index == base->arg->num_philo - 1)
			return (0);
	}
}

void	*philo_routine(void *routine_arg)
{
	t_base	*base;
	t_arg	*arg;
	t_philo	philo;

	base = (t_base *)routine_arg;
	arg = base->arg;
	philo = base->philo[base->thread_index];
	// wait_thread(base);
	base->timestamp_start_ms = get_time_ms();
	philo.start_time_ms = get_time_ms();
	if (philo.num % 2 == 0)
		usleep(100 * (arg->num_philo - base->thread_index));
	while (1)
		philo_act(base, arg, &philo);
}

int	philo_func(t_base *base, t_arg *arg, t_philo *philo)
{
	int		i;
	void	**value_ptr;

	i = 0;
	while (i < arg->num_philo)
	{
		base->thread_index = i;
		pthread_create(philo[i].thread, base->attr, \
						(void *)philo_routine, (void *)base->routine_arg);
		usleep(200);
		i++;
	}
	i = 0;
	while (i < arg->num_philo)
	{
		pthread_join(*(philo[i].thread), value_ptr);
		i++;
	}
	return (0);
}
