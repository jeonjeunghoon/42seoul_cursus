/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:55:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/30 20:16:12 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, const char **argv)
{
	t_base	*base;

	if ((base_init(argc, argv, &base)) == IS_ERROR)
		exit(1);
	if ((philo_func(base, base->arg, base->philo)) == IS_ERROR)
		exit(1);
	if ((base_free(&base)) == IS_ERROR)
		exit(1);
	return (0);
}
