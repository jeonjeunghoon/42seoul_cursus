/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/28 12:41:54 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_done(t_base *base, t_arg *arg, t_philo *philo)
{
	if ((is_die(base, arg, philo)) == IS_FINISH)
		return (IS_FINISH);
	if ((philo->num_eating == arg->num_eat) && philo->flag_eat != 1)
	{
		arg->is_done++;
		philo->flag_eat = 1;
		if (arg->is_done == arg->num_philo)
		{
			time_stamp(base, philo, IS_DONE);
			base->is_finish = IS_FINISH;
			base->is_done = 1;
			return (IS_DONE);
		}
	}
	if ((is_die(base, arg, philo)) == IS_FINISH)
		return (IS_FINISH);
	return (0);
}

int	is_die(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_ms = get_time_ms();
	if ((philo->end_ms - philo->start_ms < arg->die_ms) && \
		base->is_finish != IS_FINISH)
		return (0);
	if (base->philo_fork[philo->left_fork] == 0)
	{
		base->philo_fork[philo->left_fork] = 1;
		pthread_mutex_unlock(&(base->fork[philo->left_fork]));
	}
	if (base->philo_fork[philo->right_fork] == 0)
	{
		base->philo_fork[philo->right_fork] = 1;
		pthread_mutex_unlock(&(base->fork[philo->right_fork]));
	}
	if (base->is_done == 1)
		return (IS_FINISH);
	time_stamp(base, philo, IS_FINISH);
	base->is_finish = IS_FINISH;
	return (IS_FINISH);
}

int	act_except(t_base *base, t_arg *arg, t_philo *philo)
{
	if (arg->num_philo == 1)
	{
		ft_usleep_ms(arg->die_ms);
		if ((is_die(base, arg, philo)) == IS_FINISH)
			return (IS_FINISH);
	}
	return (0);
}
