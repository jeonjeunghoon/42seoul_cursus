/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:02:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/17 18:06:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo_init(int argc, const char **argv, t_base *base)
{
	int	i;

	base->philo->thread = (pthread_t *)malloc(sizeof(pthread_t) * \
					(base->arg->num_philo));
	base->fork = (char *)malloc(sizeof(char) * (base->arg->num_fork + 1));
	if (base->philo->thread == NULL || base->fork == NULL)
		return (IS_ERROR);
	memset(base->fork, 1, base->arg->num_fork);
	base->fork[base->arg->num_fork] = '\0';
	base->philo->routine_arg = (void *)base;
	i = 0;
	while (i < base->arg->num_philo)
	{
		base->philo[i].num = i;
		base->philo[i].left_fork = (base->philo->num + 1) % base->arg->num_fork;
		base->philo[i].right_fork = base->philo->num;
		i++;
	}
	pthread_mutex_init(&g_mutex, NULL);
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
	if ((arg_check(argc, argv)) == IS_ERROR)
		return (IS_ERROR);
	arg->num_philo = ft_atoi(argv[1]);
	if (arg->num_philo == 0)
		return (IS_ERROR);
	arg->num_fork = arg->num_philo;
	arg->time_die = ft_atoi(argv[2]);
	arg->time_eat = ft_atoi(argv[3]);
	arg->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->num_eat = ft_atoi(argv[5]);
	return (0);
}

int	init(int argc, const char **argv, t_base *base)
{
	if ((arg_init(argc, argv, base->arg)) == IS_ERROR)
		return (IS_ERROR);
	if ((philo_init(argc, argv, base)) == IS_ERROR)
		return (IS_ERROR);
	return (0);
}
