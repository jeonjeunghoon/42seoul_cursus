/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:55:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/24 15:35:22 by jeunjeon         ###   ########.fr       */
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
	if ((philo_func(base, base->arg, base->philo)) == IS_ERROR)
		exit(1);
	pthread_mutex_destroy(&(base->mutex));
	return (0);
}
