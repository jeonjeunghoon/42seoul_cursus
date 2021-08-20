/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:55:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/20 16:57:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, const char **argv)
{
	t_base	*base;

	base = (t_base *)malloc(sizeof(t_base));
	if (base == NULL)
		exit(1);
	if ((base_init(argc, argv, base)) == IS_ERROR)
		exit(1);
	pthread_mutex_init(&g_mutex, NULL);
	if ((philo_func(base, base->arg, base->philo)) == IS_ERROR)
		exit(1);
	pthread_mutex_destroy(&g_mutex);
	return (0);
}
