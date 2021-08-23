/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:49:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/23 18:33:19 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_usleep_ms(long long usleep_time)
{
	long long	start_time;
	long long	end_time;
	long long	diff_time;

	start_time = get_time_ms();
	diff_time = 0;
	while (diff_time < usleep_time)
	{
		end_time = get_time_ms();
		diff_time = end_time - start_time;
		usleep(100);
	}
}

int	is_dead(t_arg *arg, t_philo *philo)
{
	if (philo->end_time - philo->start_time < arg.time_die_ms)
		return (0);
	else
		return (IS_DEAD);
}

long long	get_time_ms(void)
{
	struct timeval	time;
	long long		ret_time;

	gettimeofday(&time, NULL);
	ret_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret_time);
}
