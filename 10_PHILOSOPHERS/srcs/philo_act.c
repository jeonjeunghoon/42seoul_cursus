/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/27 02:07:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_done(t_base *base, t_arg *arg, t_philo *philo)
{
	if ((is_die(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if ((philo->num_eating == arg->num_eat) && philo->flag_eat != 1)
	{
		arg->is_done++;
		philo->flag_eat = 1;
		if (arg->is_done == arg->num_philo)
		{
			time_stamp(base, philo, IS_DONE);
			return (IS_DONE);
		}
	}
	if ((is_die(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	return (0);
}

int	is_die(t_base *base, t_arg *arg, t_philo *philo)
{
	long long	end_ms;

	end_ms = get_time_ms();
	if (end_ms - philo->start_ms < arg->die_ms)
		return (0);
	if (base->philo_fork[philo->left_fork] == 1 && \
	base->philo_fork[philo->right_fork] == 1)
	{
		pthread_mutex_unlock(&(base->fork[philo->left_fork]));
		pthread_mutex_unlock(&(base->fork[philo->right_fork]));
	}
	time_stamp(base, philo, IS_DIE);
	base->is_die = IS_DIE;
	return (IS_DIE);
}

int	act_except(t_base *base, t_arg *arg, t_philo *philo)
{
	if (arg->num_philo == 1)
	{
		ft_usleep_ms(arg->die_ms);
		if ((is_die(base, arg, philo)) == IS_DIE)
			return (IS_DIE);
	}
	return (0);
}

int	philo_act(t_base *base, t_arg *arg, t_philo *philo)
{
	if ((act_except(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if ((take_fork(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if ((eating(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if ((put_fork(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if ((sleeping(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if ((thinking(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if (arg->num_eat > 0)
		is_done(base, arg, philo);
	return (1);
}
