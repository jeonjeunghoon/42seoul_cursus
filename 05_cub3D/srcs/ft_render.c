/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:22:27 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/03 21:33:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
