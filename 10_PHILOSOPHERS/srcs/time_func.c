/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:49:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/16 22:08:33 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_dead(int *start, int *end, t_philo *philo)
{
	get_time(end, philo->die_end);
	if ((time_diff(start, end)) < 0)
		return (IS_DEAD);
	return (0);
}

int	time_diff(int *start, int *end)
{
	int	left_time;

	left_time = ((end[0] - start[0]) * 1000) + ((end[1] - start[1]) / 1000);
	return (left_time);
}

int	get_time(int *arr, struct timeval time)
{
	gettimeofday(&time, NULL);
	arr[0] = time.tv_sec;
	arr[1] = time.tv_usec;
	return (0);
}
