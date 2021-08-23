/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/23 18:30:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	wait_thread(t_base *base)
{
	while (1)
	{
		if (base->num_thread == base->arg->num_philo - 1)
			return (0);
	}
}

void	*philo_routine(void *routine_arg)
{
	t_base	*base;
	t_philo	philo;

	base = (t_base *)routine_arg;
	philo = base->philo[base->num_thread];
	wait_thread(base);
	while (1)
	{
		philo.start_time = get_time_ms();
		base->finish_flag = philo_act(base, base->arg, &philo);
		if (base->finish_flag == IS_DEAD)
		{
			printf("\n\nPhilosopher[%d] is Dead\n\n\n", philo.num);
			exit(1);
		}
		else if (base->finish_flag == IS_DONE)
		{
			printf("\n\nPhilosophers are Full\n\n\n");
			exit(1);
		}
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
