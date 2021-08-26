/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:07:30 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/27 01:37:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	sleeping(t_base *base, t_arg *arg, t_philo *philo)
{
	is_died(base, arg, philo);
	is_enough(base, arg, philo, arg->sleep_ms);
	time_stamp(base, philo, IS_SLEEPING);
	ft_usleep_ms(arg->sleep_ms);
	philo->num_sleeping++;
	is_died(base, arg, philo);
}

void	put_fork(t_base *base, t_arg *arg, t_philo *philo)
{
	is_died(base, arg, philo);
	pthread_mutex_unlock(&(base->fork[philo->left_fork]));
	pthread_mutex_unlock(&(base->fork[philo->right_fork]));
}

int	take_fork(t_base *base, t_arg *arg, t_philo *philo)
{
	is_died(base, arg, philo);
	pthread_mutex_lock(&(base->fork[philo->left_fork]));
	pthread_mutex_lock(&(base->fork[philo->right_fork]));
	time_stamp(base, philo, IS_FORK);
	time_stamp(base, philo, IS_FORK);
	is_died(base, arg, philo);
	return (0);
}

void	eating(t_base *base, t_arg *arg, t_philo *philo)
{
	is_died(base, arg, philo);
	is_enough(base, arg, philo, arg->eat_ms);
	time_stamp(base, philo, IS_EATING);
	ft_usleep_ms(arg->eat_ms);
	philo->num_eating++;
	philo->start_ms = get_time_ms();
	is_died(base, arg, philo);
}

void	thinking(t_base *base, t_arg *arg, t_philo *philo)
{
	is_died(base, arg, philo);
	time_stamp(base, philo, IS_THINKING);
}
