/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:49:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/28 01:24:08 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	time_stamp(t_base *base, t_philo *philo, int flag)
{
	int	philo_num;

	philo_num = philo->num + 1;
	pthread_mutex_lock(&(base->ft_mutex));
	base->timestamp_end_ms = get_time_ms();
	base->timestamp_diff_ms = base->timestamp_end_ms - base->timestamp_start_ms;
	if (flag == IS_DIE)
		printf("%lld %d died\n", base->timestamp_diff_ms, philo_num);
	else if (flag == IS_FORK)
		printf("%lld %d has taken a fork\n", base->timestamp_diff_ms, philo_num);
	else if (flag == IS_EATING)
		printf("%lld %d is eating\n", base->timestamp_diff_ms, philo_num);
	else if (flag == IS_SLEEPING)
		printf("%lld %d is sleeping\n", base->timestamp_diff_ms, philo_num);
	else if (flag == IS_THINKING)
		printf("%lld %d is thinking\n", base->timestamp_diff_ms, philo_num);
	else if (flag == IS_DONE)
		printf("%lld philosophers are full\n", base->timestamp_diff_ms);
	pthread_mutex_unlock(&(base->ft_mutex));
}

int	is_enough(t_base *base, t_arg *arg, t_philo *philo, \
				long long required_ms)
{
	long long	left_ms;
	long long	time_ms;

	philo->end_ms = get_time_ms();
	left_ms = philo->end_ms - philo->start_ms + required_ms;
	if (left_ms >= arg->die_ms)
	{
		time_ms = arg->die_ms - (philo->end_ms - philo->start_ms);
		ft_usleep_ms(time_ms);
		is_die(base, arg, philo);
		return (IS_DIE);
	}
	return (0);
}

void	ft_usleep_ms(long long time_ms)
{
	long long	start_ms;
	long long	end_ms;
	long long	diff_ms;

	start_ms = get_time_ms();
	diff_ms = 0;
	while (diff_ms < time_ms)
	{
		end_ms = get_time_ms();
		diff_ms = end_ms - start_ms;
		usleep(100);
	}
}

long long	get_time_ms(void)
{
	struct timeval	start_time;
	long long		time_ms;

	gettimeofday(&start_time, NULL);
	time_ms = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	return (time_ms);
}
