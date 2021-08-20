/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:49:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/20 14:58:57 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_dead(t_base base, t_philo philo, t_arg arg)
{
	int	i;

	if (philo.end_time - philo.start_time < arg.time_die_ms)
		return (0);
	else
	{
		printf("\n###################\nthread[%d] - death\n###################\n", philo.num);
		i = 0;
		while (i < base.num_thread)
		{
			pthread_detach(*(philo.thread));
			i++;
		}
	}
	exit(1);
}

long long	get_time_ms(void)
{
	struct timeval	time;
	long long		ret_time;

	gettimeofday(&time, NULL);
	ret_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret_time);
}
