/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:49:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/17 17:33:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	get_time_ms(void)
{
	struct timeval	time;
	long long		ret_time;

	gettimeofday(&time, NULL);
	ret_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret_time);
}
