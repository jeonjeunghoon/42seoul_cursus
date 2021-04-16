/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:22:27 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/16 10:59:25 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				wall_render(t_cub *cub, int y0, int y1, int wh)
{
	int				color;
	int				y;

	if (cub->ray.wdir == DIR_W || cub->ray.wdir == DIR_E)
		cub->tex.txratio = cub->ray.wy - floor(cub->ray.wy);
	else
		cub->tex.txratio = cub->ray.wx - floor(cub->ray.wx);
	cub->tex.tx = (int)(cub->tex.txratio * TW);
	y = get_max(0, y0);
	while (y <= y1)
	{
		cub->tex.ty = (int)((y - y0) * TH / wh);
		color = get_texture_color(cub, cub->tex.tx, cub->tex.ty);
		draw_pixel(cub, cub->ray.ray_cast, y, color);
		y++;
	}
}

void				ft_render(t_cub *cub)
{
	int				idx;
	int				wh;
	int				y0;
	int				y1;

	cub->ray.dist = ft_dist(cub->player.x, cub->player.y, \
	cub->ray.wx, cub->ray.wy);
	cub->ray.dist *= cos(cub->player.th - cub->ray.ray);
	wh = get_wall_height(cub, cub->ray.dist);
	y0 = (int)((cub->map.r[1] - wh) / 2.0);
	y1 = y0 + wh - 1;
	y1 = get_min(cub->map.r[1] - 1, y1);
	idx = 0;
	while (idx < y0)
		draw_pixel(cub, cub->ray.ray_cast, idx++, \
		encode_color(cub->map.c[0], cub->map.c[1], cub->map.c[2]));
	wall_render(cub, y0, y1, wh);
	idx = y1;
	while (idx < cub->map.r[1] - 1)
		draw_pixel(cub, cub->ray.ray_cast, idx++, \
		encode_color(cub->map.f[0], cub->map.f[1], cub->map.f[2]));
}
