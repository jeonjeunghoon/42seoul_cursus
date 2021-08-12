/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:55:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/12 22:33:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	printf("thread\n");
}

int	philo_init(t_philo *philo, t_arg *arg)
{
	int		i;
	void	**value_ptr;

	philo->thread = (pthread_t *)malloc(sizeof(pthread_t) * (arg->num_of_philo + 1));
	if (philo->thread == NULL)
		return (IS_ERROR);
	i = 1;
	philo->arg = NULL;
	while (i < arg->num_of_philo + 1)
	{
		pthread_create(&(philo->thread[i]), NULL, (void *)routine, (void *)philo->arg);
		i++;
	}
	i = 1;
	while (i < arg->num_of_philo + 1)
	{
		pthread_join(philo->thread[i], value_ptr);
		i++;
	}
	return (0);
}

int	arg_init(int argc, const char **argv, t_arg *arg)
{
	if (argc != 5 && argc != 6)
		return (IS_ERROR);
	arg->num_of_philo = ft_atoi(argv[1]);
	arg->num_of_fork = arg->num_of_philo;
	if (arg->num_of_philo == 0 || arg->num_of_fork == 0)
		return (IS_ERROR);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->must_eat_times = ft_atoi(argv[5]);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_arg	*arg;
	t_philo	*philo;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (arg == NULL)
		exit(1);
	if ((arg_init(argc, argv, arg)) == IS_ERROR)
		exit(1);
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		exit(1);
	if ((philo_init(philo, arg)) == IS_ERROR)
		exit(1);
	return (0);
}
