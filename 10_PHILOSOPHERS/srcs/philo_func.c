/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:57:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/17 18:04:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *routine_arg)
{
	t_base	*base;
	t_philo	*philo;
	t_arg	*arg;

	base = (t_base *)routine_arg;
	philo = base->philo;
	arg = base->arg;
	printf("thread[%d]\n", philo->num);
	base->start_time = get_time_ms();
	while (1)
		philo_act(base);
}

int	philo_func(t_base *base, t_philo *philo, t_arg *arg)
{
	int		i;
	void	**value_ptr;

	i = 0;
	while (i < arg->num_philo)
	{
		pthread_create(&(philo->thread[i]), NULL, \
						(void *)philo_routine, (void *)philo->routine_arg);
		usleep(200);
		i++;
	}
	i = 0;
	while (i < arg->num_philo)
	{
		pthread_detach(philo->thread[i]);
		// pthread_join(philo->thread[i], value_ptr);
		i++;
	}
	return (0);
}
