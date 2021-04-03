/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:42:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/03 20:46:00 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int					get_wall_height(t_cub *cub, double dist)
{
	double			h;
	int				wall_h;

	h = 2.0 * dist * tan(cub->player.fov_v / 2.0);
	wall_h = (int)(cub->map.r[1] * (WALL_H / h));
	return (wall_h);
}

int					encode_color(int r, int g, int b)
{
	int				color;

	color = (r * 256 * 256) + (g * 256) + b;
	return (color);
}

void				decode_color(int color, int *r, int *g, int *b)
{
	*r = ((color >> 16) & 0xFF);
	*g = ((color >> 8) & 0xFF);
	*b = (color & 0xFF);
}

int					get_texture_color(t_cub *cub, int tx, int ty)
{
	int				color;

	color = cub->tex.texture[cub->ray.wdir][ty * TW + tx];
	return (color);
}
