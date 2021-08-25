/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:07:30 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/25 18:08:04 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	sleeping(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
	is_enough(base, arg, philo, arg->time_sleep_ms);
	ft_usleep_ms(arg->time_sleep_ms);
	philo->num_sleeping++;
	time_stamp(base, arg, philo, IS_SLEEPING);
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
}

void	put_fork(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
	if (base->fork[philo->left_fork] == 0 && \
		base->fork[philo->right_fork] == 0 && \
		base->arg->num_philo != 1)
	{
		pthread_mutex_lock(&(base->mutex));
		base->fork[philo->left_fork] = 1;
		base->fork[philo->right_fork] = 1;
		pthread_mutex_unlock(&(base->mutex));
	}
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
}

int	take_fork(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
	if (base->fork[philo->left_fork] == 1 && \
		base->fork[philo->right_fork] == 1 && \
		base->arg->num_philo != 1)
	{
		pthread_mutex_lock(&(base->mutex));
		base->fork[philo->left_fork] = 0;
		base->fork[philo->right_fork] = 0;
		time_stamp(base, arg, philo, IS_FORK);
		pthread_mutex_unlock(&(base->mutex));
		return (1);
	}
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
	return (0);
}

void	eating(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
	if (base->fork[philo->left_fork] == 0 && \
		base->fork[philo->right_fork] == 0)
	{
		is_enough(base, arg, philo, arg->time_eat_ms);
		ft_usleep_ms(arg->time_eat_ms);
		philo->start_time_ms = get_time_ms();
		philo->num_eating++;
		time_stamp(base, arg, philo, IS_EATING);
	}
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
}

void	thinking(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time_ms = get_time_ms();
	is_died(base, arg, philo);
	time_stamp(base, arg, philo, IS_THINKING);
}
