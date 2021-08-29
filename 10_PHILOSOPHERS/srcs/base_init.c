/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:02:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/30 00:06:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	fork_mutex_init(t_base *base)
{
	int	i;

	base->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
											(base->arg->num_fork));
	if (base->fork == NULL)
		return (IS_ERROR);
	base->table_fork = (int *)malloc(sizeof(int) * base->arg->num_fork);
	if (base->table_fork == NULL)
		return (IS_ERROR);
	i = 0;
	while (i < base->arg->num_fork)
	{
		pthread_mutex_init(&(base->fork[i]), NULL);
		base->table_fork[i] = 1;
		i++;
	}
	pthread_mutex_init(&(base->ft_mutex), NULL);
	return (0);
}

int	philo_init(t_base *base)
{
	int	i;

	base->philo = (t_philo *)malloc(sizeof(t_philo) * (base->arg->num_philo));
	if (base->philo == NULL)
		return (IS_ERROR);
	i = 0;
	while (i < base->arg->num_philo)
	{
		base->philo[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		if (base->philo[i].thread == NULL)
			return (IS_ERROR);
		base->philo[i].left_fork = i;
		base->philo[i].right_fork = (i + 1) % base->arg->num_fork;
		base->philo[i].start_ms = 0;
		base->philo[i].end_ms = 0;
		base->philo[i].num_eating = 0;
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

int	arg_init(int argc, const char **argv, t_base *base)
{
	base->arg = (t_arg *)malloc(sizeof(t_arg));
	if (base->arg == NULL)
		return (IS_ERROR);
	if ((arg_check(argc, argv)) == IS_ERROR)
		return (IS_ERROR);
	base->arg->num_philo = ft_atoi(argv[1]);
	if (base->arg->num_philo == 0)
		return (IS_ERROR);
	base->arg->num_fork = base->arg->num_philo;
	base->arg->die_ms = ft_atoi(argv[2]);
	base->arg->eat_ms = ft_atoi(argv[3]);
	base->arg->sleep_ms = ft_atoi(argv[4]);
	if (argc == 6)
	{
		base->arg->num_eat = ft_atoi(argv[5]);
		base->arg->is_done = 0;
	}
	else
		base->arg->num_eat = 0;
	return (0);
}

int	base_init(int argc, const char **argv, t_base **base)
{
	(*base) = (t_base *)malloc(sizeof(t_base));
	(*base)->attr = NULL;
	(*base)->routine_arg = (void *)(*base);
	if ((*base) == NULL)
		exit(1);
	if ((arg_init(argc, argv, *base)) == IS_ERROR)
		return (IS_ERROR);
	if ((philo_init(*base)) == IS_ERROR)
		return (IS_ERROR);
	if ((fork_mutex_init(*base)) == IS_ERROR)
		return (IS_ERROR);
	(*base)->is_finish = 0;
	(*base)->is_done = 0;
	return (0);
}
