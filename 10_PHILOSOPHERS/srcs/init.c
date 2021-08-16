/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:02:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/16 21:41:14 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	philo_init(int argc, const char **argv, t_philo *philo)
{
	philo->thread = (pthread_t *)malloc(sizeof(pthread_t) * \
					(philo->arg->num_of_philo));
	philo->fork = (int *)malloc(sizeof(int) * (philo->arg->num_of_fork));
	if (philo->thread == NULL || philo->fork == NULL)
		return (IS_ERROR);
	memset(philo->fork, 1, philo->arg->num_of_fork);
	pthread_mutex_init(&g_mutex, NULL);
	philo->order = 0;
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
	arg->num_of_philo = ft_atoi(argv[1]);
	if (arg->num_of_philo == 0)
		return (IS_ERROR);
	arg->num_of_fork = arg->num_of_philo;
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->must_eat_times = ft_atoi(argv[5]);
	return (0);
}

int	init(int argc, const char **argv, t_philo *philo)
{
	if ((arg_init(argc, argv, philo->arg)) == IS_ERROR)
		return (IS_ERROR);
	if ((philo_init(argc, argv, philo)) == IS_ERROR)
		return (IS_ERROR);
	return (0);
}
