/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/20 17:16:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *routine_arg)
{
	t_base	*base;
	t_philo	philo;
	t_arg	arg;

	base = (t_base *)routine_arg;
	philo = base->philo[base->num_thread];
	arg = *(base->arg);
	while (1)
	{
		if (base->num_thread == arg.num_philo - 1)
			break ;
	}
	while (1)
	{
		philo.start_time = get_time_ms();
		philo_act(*base, arg, &philo);
	}
}

int	philo_func(t_base *base, t_arg *arg, t_philo *philo)
{
	int		i;
	void	**value_ptr;

	i = 0;
	while (i < arg->num_philo)
	{
		base->num_thread = i;
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
