/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:02:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/25 17:22:28 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo_init(int argc, const char **argv, t_base *base)
{
	int	i;

	i = 0;
	while (i < base->arg->num_philo)
	{
		base->philo[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		if (base->philo[i].thread == NULL)
			return (IS_ERROR);
		base->philo[i].num = i + 1;
		base->philo[i].left_fork = (base->philo[i].num) % base->arg->num_fork;
		base->philo[i].right_fork = base->philo[i].num - 1;
		base->philo[i].num_eating = 0;
		base->philo[i].num_sleeping = 0;
		base->philo[i].start_time_ms = 0;
		base->philo[i].end_time_ms = 0;
		base->philo[i].flag_eat = 0;
		i++;
	}
	return (0);
}

int	arg_check(int argc, const char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		return (IS_ERROR);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((ft_isdigit(argv[i][j])) == 0)
				return (IS_ERROR);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_init(int argc, const char **argv, t_arg *arg)
{
	int	i;

	if ((arg_check(argc, argv)) == IS_ERROR)
		return (IS_ERROR);
	arg->num_philo = ft_atoi(argv[1]);
	if (arg->num_philo == 0)
		return (IS_ERROR);
	arg->num_fork = arg->num_philo;
	arg->time_die_ms = ft_atoi(argv[2]);
	arg->time_eat_ms = ft_atoi(argv[3]);
	arg->time_sleep_ms = ft_atoi(argv[4]);
	if (argc == 6)
	{
		arg->num_eat = ft_atoi(argv[5]);
		arg->is_done = 0;
	}
	else
		arg->num_eat = 0;
	return (0);
}

int	base_init(int argc, const char **argv, t_base *base)
{
	int	i;

	base->arg = (t_arg *)malloc(sizeof(t_arg));
	if (base->arg == NULL)
		return (IS_ERROR);
	if ((arg_init(argc, argv, base->arg)) == IS_ERROR)
		return (IS_ERROR);
	base->philo = (t_philo *)malloc(sizeof(t_philo) * (base->arg->num_philo));
	if (base->philo == NULL)
		return (IS_ERROR);
	if ((philo_init(argc, argv, base)) == IS_ERROR)
		return (IS_ERROR);
	base->attr = NULL;
	base->routine_arg = (void *)base;
	pthread_mutex_init(&(base->mutex), NULL);
	base->fork = (int *)malloc(sizeof(int) * (base->arg->num_fork));
	if (base->fork == NULL)
		return (IS_ERROR);
	i = 0;
	while (i < base->arg->num_fork)
		base->fork[i++] = 1;
	base->thread_index = 0;
	base->finish_flag = 1;
	base->timestamp_start_ms = 0;
	base->timestamp_end_ms = 0;
	base->timestamp_diff_ms = 0;
	return (0);
}
