/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/26 15:12:43 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *routine_arg)
{
	t_base	*base;
	t_arg	*arg;
	t_philo	*philo;

	base = (t_base *)routine_arg;
	arg = base->arg;
	philo = &(base->philo[base->thread_index]);
	base->timestamp_start_ms = get_time_ms();
	philo->start_time_ms = get_time_ms();
	if (philo->num % 2 == 1)
		usleep(10 * (arg->num_philo - base->thread_index));
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
	while (1)
		philo_act(base, arg, philo);
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
	value_ptr = NULL;
	i = 0;
	while (i < arg->num_philo)
	{
		pthread_join(*(philo[i].thread), value_ptr);
		i++;
	}
	return (0);
}
