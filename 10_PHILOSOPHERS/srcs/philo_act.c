/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/27 01:38:10 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	is_done(t_base *base, t_arg *arg, t_philo *philo)
{
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
	is_died(base, arg, philo);
}

void	is_died(t_base *base, t_arg *arg, t_philo *philo)
{
	long long	end_ms;

	end_ms = get_time_ms();
	if (end_ms - philo->start_ms < arg->die_ms)
		return ;
	time_stamp(base, philo, IS_DIED);
	exit(1);
}

void	act_except(t_base *base, t_arg *arg, t_philo *philo)
{
	if (arg->num_philo == 1)
	{
		ft_usleep_ms(arg->die_ms);
		is_died(base, arg, philo);
	}
}

int	philo_act(t_base *base, t_arg *arg, t_philo *philo)
{
	act_except(base, arg, philo);
	take_fork(base, arg, philo);
	eating(base, arg, philo);
	put_fork(base, arg, philo);
	sleeping(base, arg, philo);
	thinking(base, arg, philo);
	if (arg->num_eat > 0)
		is_done(base, arg, philo);
	return (1);
}
