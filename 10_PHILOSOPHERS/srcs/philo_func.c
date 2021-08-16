/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/16 22:08:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	int			order;
	int			start[2];
	int			end[2];

	philo = (t_philo *)arg;
	order = philo->order;
	while (1)
	{
		get_time(start, philo->die_start);
		if ((philo_act(philo, order, start, end)) == IS_DEAD)
		{
			printf("is DEAD!!!!!!!!!!!!!!\n\n");
			return ((void *)IS_DEAD);
		}
		if ((is_dead(start, end, philo)) == IS_DEAD)
			return ((void *)IS_DEAD);
	}
}

int	philo_func(t_philo *philo)
{
	int		i;
	void	**value_ptr;

	i = 0;
	while (i < philo->arg->num_of_philo)
	{
		philo->philo_arg = (void *)philo;
		philo->order = i;
		pthread_create(&(philo->thread[i]), NULL, \
						(void *)philo_routine, (void *)philo->philo_arg);
		usleep(200);
		i++;
	}
	i = 0;
	while (i < philo->arg->num_of_philo)
	{
		pthread_detach(philo->thread[i]);
		// pthread_join(philo->thread[i], value_ptr);
		i++;
	}
	return (0);
}
