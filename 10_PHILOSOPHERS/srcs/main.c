/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:55:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/17 18:12:06 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, const char **argv)
{
	t_base	*base;

	base = (t_base *)malloc(sizeof(t_base));
	if (base == NULL)
		exit(1);
	base->arg = (t_arg *)malloc(sizeof(t_arg));
	if (base->arg == NULL)
		exit(1);
	base->philo = (t_philo *)malloc(sizeof(t_philo));
	if (base->philo == NULL)
		exit(1);
	if ((init(argc, argv, base)) == IS_ERROR)
		exit(1);
	if ((philo_func(base, base->philo, base->arg)) == IS_ERROR)
		exit(1);
	pthread_mutex_destroy(&g_mutex);
	return (0);
}
