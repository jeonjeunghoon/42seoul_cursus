/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:49:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/26 15:11:19 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	time_stamp(t_base *base, t_philo *philo, int flag)
{
	base->timestamp_end_ms = get_time_ms();
	base->timestamp_diff_ms = base->timestamp_end_ms - base->timestamp_start_ms;
	if (flag == IS_DIED)
		printf("%lld %d died\n", base->timestamp_diff_ms, philo->num);
	else if (flag == IS_FORK)
		printf("%lld %d has taken a fork\n", base->timestamp_diff_ms, \
											philo->num);
	else if (flag == IS_EATING)
		printf("%lld %d is eating\n", \
		base->timestamp_diff_ms, philo->num);
	else if (flag == IS_SLEEPING)
		printf("%lld %d is sleeping\n", \
		base->timestamp_diff_ms, philo->num);
	// else if (flag == IS_THINKING)
	// 	printf("%lld %d is thinking\n", base->timestamp_diff_ms, philo->num);
	else if (flag == IS_DONE)
		printf("%lld philosophers are full\n", base->timestamp_diff_ms);
}

void	is_enough(t_base *base, t_arg *arg, t_philo *philo, \
				long long required_time_ms)
{
	long long	left_time_ms;

	philo->end_time_ms = get_time_ms();
	left_time_ms = philo->end_time_ms - philo->start_time_ms + required_time_ms;
	if (left_time_ms >= arg->time_die_ms)
	{
		time_stamp(base, philo, IS_DIED);
		exit(1);
	}
}

void	ft_usleep_ms(long long usleep_time)
{
	long long	start_time_ms;
	long long	end_time_ms;
	long long	diff_time_ms;

	start_time_ms = get_time_ms();
	diff_time_ms = 0;
	while (diff_time_ms < usleep_time)
	{
		end_time_ms = get_time_ms();
		diff_time_ms = end_time_ms - start_time_ms;
		usleep(50);
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
