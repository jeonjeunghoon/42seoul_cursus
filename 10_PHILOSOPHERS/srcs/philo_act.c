/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:34:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/24 16:29:19 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	time_stamp(t_base *base, t_arg *arg, t_philo *philo, int flag)
{
	if (flag == IS_DIED)
		printf("timestamp_in_ms %d died\n", philo->num);
	else if (flag == IS_FORK)
		printf("timestamp_in_ms %d has taken a fork\n", philo->num);
	else if (flag == IS_EATING)
		printf("timestamp_in_ms %d is eating\n", philo->num);
	else if (flag == IS_SLEEPING)
		printf("timestamp_in_ms %d is sleeping\n", philo->num);
	else if (flag == IS_THINKING)
		printf("timestamp_in_ms %d is thinking\n", philo->num);
}

int	sleeping(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	if ((is_died(*arg, philo)) == IS_DIED)
		return (IS_DIED);
	// 가능한지 검사
	ft_usleep_ms(arg->time_sleep_ms);
	philo->num_sleeping++;
	return (0);
}

int	switch_fork(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	if ((is_died(*arg, philo)) == IS_DIED)
		return (IS_DIED);
	if (philo->left_fork == 1 && philo->right_fork == 1)
	{
		philo->left_fork = 0;
		philo->right_fork = 0;
		// time_stamp 호출;
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

int	eating(t_base *base, t_arg *arg, t_philo *philo)
{
	philo->end_time = get_time_ms();
	if ((is_died(*arg, philo)) == IS_DIED)
		return (IS_DIED);
	if ((switch_fork(base, arg, philo)) == IS_ERROR)
		return (IS_ERROR);
	// 가능한 지 검사
	ft_usleep_ms(arg->time_eat_ms);
	philo->num_eating++;
	philo->start_time = get_time_ms();
	if ((switch_fork(base, arg, philo)) == IS_ERROR)
		return (IS_ERROR);
	return (0);
}

int	philo_act(t_base *base, t_arg *arg, t_philo *philo)
{
	while (1)
	{
		// thinking 함수
		if (base->fork[philo->left_fork] == 1 && \
			base->fork[philo->right_fork] == 1 && \
			base->arg->num_philo != 1)
		{
			// 세가지 함수로 나누가
			pthread_mutex_lock(&base->mutex);
			if ((eating(base, arg, philo)) == IS_DIED)
				return (IS_DIED);
			pthread_mutex_unlock(&base->mutex);
			// 요기 까지

			// 6번째 인자 있을 때
			if (arg->num_eat > 0 && (philo->num_eating == arg->num_eat) && philo->flag_eat != 1)
			{
				arg->is_done++;
				philo->flag_eat = 1;
				if (arg->is_done == arg->num_philo)
					return (IS_DONE);
			}
			// 사용
			
			break ;
		}
	}
	if ((sleeping(base, arg, philo)) == IS_DIED)
		return (IS_DIED);
	return (1);
}
