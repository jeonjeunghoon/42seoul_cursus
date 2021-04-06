/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:46 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/06 20:39:00 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			draw_pixel(t_cub *cub, int x, int y, int color)
{
	cub->img.data[y * cub->map.r[0] + x] = color;
}

int				ft_sgn(double d)
{
	if (fabs(d) < 1e-06)
		return (0);
	else if (d > 0)
		return (1);
	return (-1);
}

double			ft_dist(double s_x, double s_y, double e_x, double e_y)
{
	double		dx;
	double		dy;
	double		dist;

	dx = s_x - e_x;
	dy = s_y - e_y;
	dist = sqrt(pow(dx, 2) + pow(dy, 2));
	return (dist);
}

void			ft_swap(t_sprite *sprite, int i, int j)
{
	t_sprite	buf;

	buf = sprite[i];
	sprite[i] = sprite[j];
	sprite[j] = buf;
}

void			ft_qsort(t_sprite *sprite, int start, int end)
{
	int			pivot_i;
	int			pivot_dist;
	int			i;

	if (start < end)
	{
		pivot_dist = sprite[end].dist;
		i = start - 1;
		while (start < end)
		{
			if (pivot_dist > sprite[start].dist)
			{
				i++;
				ft_swap(sprite, start, i);
			}
			start++;
		}
		ft_swap(sprite, end, i + 1);
		pivot_i = i + 1;
		ft_qsort(sprite, start, pivot_i - 1);
		ft_qsort(sprite, pivot_i + 1, end);
	}
}
