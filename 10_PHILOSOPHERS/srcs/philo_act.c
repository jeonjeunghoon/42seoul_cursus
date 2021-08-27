/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:07:30 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/28 01:18:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	thinking(t_base *base, t_arg *arg, t_philo *philo)
{
	if ((is_die(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	time_stamp(base, philo, IS_THINKING);
	return (0);
}

int	sleeping(t_base *base, t_arg *arg, t_philo *philo)
{
	if ((is_die(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if ((is_enough(base, arg, philo, arg->sleep_ms)) == IS_DIE)
		return (IS_DIE);
	time_stamp(base, philo, IS_SLEEPING);
	ft_usleep_ms(arg->sleep_ms);
	philo->num_sleeping++;
	if ((is_die(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	return (0);
}

int	put_fork(t_base *base, t_arg *arg, t_philo *philo)
{
	base->philo_fork[philo->left_fork] = 1;
	base->philo_fork[philo->right_fork] = 1;
	pthread_mutex_unlock(&(base->fork[philo->left_fork]));
	pthread_mutex_unlock(&(base->fork[philo->right_fork]));
	return (0);
}

int	eating(t_base *base, t_arg *arg, t_philo *philo)
{
	if ((is_die(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	if ((is_enough(base, arg, philo, arg->eat_ms)) == IS_DIE)
		return (IS_DIE);
	time_stamp(base, philo, IS_EATING);
	ft_usleep_ms(arg->eat_ms);
	philo->num_eating++;
	philo->start_ms = get_time_ms();
	if ((is_die(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	return (0);
}

int	take_fork(t_base *base, t_arg *arg, t_philo *philo)
{
	if ((is_die(base, arg, philo)) == IS_DIE)
		return (IS_DIE);
	pthread_mutex_lock(&(base->fork[philo->left_fork]));
	base->philo_fork[philo->left_fork] = 0;
	time_stamp(base, philo, IS_FORK);
	pthread_mutex_lock(&(base->fork[philo->right_fork]));
	base->philo_fork[philo->right_fork] = 0;
	time_stamp(base, philo, IS_FORK);
	return (0);
}
