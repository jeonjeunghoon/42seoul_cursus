/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/26 15:11:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	is_done(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
	if ((philo->num_eating == arg->num_eat) && philo->flag_eat != 1)
	{
		arg->is_done++;
		philo->flag_eat = 1;
		if (arg->is_done == arg->num_philo)
		{
			time_stamp(base, philo, IS_DONE);
			exit(1);
		}
	}
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
}

void	is_died(t_base *base, t_arg *arg, t_philo *philo)
{
	if (philo->end_time_ms - philo->start_time_ms < arg->time_die_ms)
		return ;
	time_stamp(base, philo, IS_DIED);
	exit(1);
}

int	philo_act(t_base *base, t_arg *arg, t_philo *philo)
{
	while (1)
	{
		thinking(base, arg, philo);
		if ((take_fork(base, arg, philo)) == 1)
			break ;
	}
	eating(base, arg, philo);
	put_fork(base, arg, philo);
	if (arg->num_eat > 0)
		is_done(base, arg, philo);
	sleeping(base, arg, philo);
	return (1);
}
