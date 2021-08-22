/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/22 21:13:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	sleeping(t_base base, t_arg arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	if ((is_dead(base, arg, philo)) == 1)
		return (IS_DEAD);
	philo->num_sleeping++;
	ft_usleep_ms(arg.time_sleep_ms);
	philo->end_time = get_time_ms();
	if ((is_dead(base, arg, philo)) == 1)
		return (IS_DEAD);
	return (0);
}

int	switch_fork(t_base base, t_arg arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	if ((is_dead(base, arg, philo)) == 1)
		return (IS_DEAD);
	if (philo->left_fork == 1 && philo->right_fork == 1)
	{
		philo->left_fork = 0;
		philo->right_fork = 0;
	}
	else if (philo->left_fork == 0 && philo->right_fork == 0)
	{
		philo->left_fork = 1;
		philo->right_fork = 1;
	}
	else
		return (IS_ERROR);
	return (0);
}

int	eating(t_base base, t_arg arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	if ((is_dead(base, arg, philo)) == 1)
		return (IS_DEAD);
	if ((switch_fork(base, arg, philo)) == 1)
		return (IS_DEAD);
	philo->num_eating++;
	ft_usleep_ms(arg.time_eat_ms);
	philo->start_time = get_time_ms();
	if ((switch_fork(base, arg, philo)) == 1)
		return (IS_DEAD);
	philo->end_time = get_time_ms();
	if ((is_dead(base, arg, philo)) == 1)
		return (IS_DEAD);
	return (0);
}

int	philo_act(t_base base, t_arg arg, t_philo *philo)
{
	while (1)
	{
		philo->end_time = get_time_ms();
		if ((is_dead(base, arg, philo)) == 1)
			return (IS_DEAD);
		if (base.fork[philo->left_fork] == 1 && \
			base.fork[philo->right_fork] == 1)
		{
			philo->end_time = get_time_ms();
			if ((is_dead(base, arg, philo)) == 1)
				return (IS_DEAD);
			pthread_mutex_lock(&g_mutex);
			if ((eating(base, arg, philo)) == 1)
				return (IS_DEAD);
			pthread_mutex_unlock(&g_mutex);
			philo->end_time = get_time_ms();
			if ((is_dead(base, arg, philo)) == 1)
				return (IS_DEAD);
			if (arg.num_eat > 0 && (philo->num_eating == arg.num_eat))
			{
				// 대기 시키자
				return (IS_DONE);
			}
			break ;
		}
	}
	if ((sleeping(base, arg, philo)) == 1)
		return (IS_DEAD);
	printf("\nthread[%d]\nnum_eating = %lld num_sleeping = %lld\n", philo->num, philo->num_eating, philo->num_sleeping);
	printf("-------------------------------------------------------------------------\n\n\n");
	return (0);
}
