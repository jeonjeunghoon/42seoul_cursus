/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:40 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/03 20:30:04 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double			deg_to_rad(double deg)
{
	double		rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

double			rad_to_deg(double rad)
{
	double		deg;

	deg = rad * (180 / M_PI);
	return (deg);
}

double			get_min(double x, double y)
{
	if (x < y)
		return (x);
	return (y);
}

double			get_max(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

int				get_cell(t_cub *cub, int x, int y)
{
	if (x >= 0 && x < (cub->map.mx) && y >= 0 && y < cub->map.my)
		return (cub->map.map[y][x]);
	return (-1);
}
