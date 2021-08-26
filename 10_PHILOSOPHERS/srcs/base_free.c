/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:37:41 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/27 02:12:19 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	fork_mutex_free(t_base *base, int num_fork)
{
	int	i;

	i = 0;
	while (i < num_fork)
	{
		pthread_mutex_destroy(&(base->fork[i]));
		i++;
	}
	return (0);
}

int	philo_free(t_philo **philo, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		free((*philo)[i].thread);
		i++;
	}
	free(*philo);
	return (0);
}

int	arg_free(t_arg **arg)
{
	free(*arg);
	return (0);
}

int	base_free(t_base **base)
{
	int	num;

	num = (*base)->arg->num_philo;
	if ((arg_free(&((*base)->arg))) == IS_ERROR)
		return (IS_ERROR);
	if ((philo_free(&((*base)->philo), num)) == IS_ERROR)
		return (IS_ERROR);
	if ((fork_mutex_free(*base, num)) == IS_ERROR)
		return (IS_ERROR);
	free(*base);
	return (0);
}
