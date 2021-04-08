/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:11:30 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/04/09 02:45:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			get_sprite(t_cub *cub, int x, int y, t_sprite *sp)
{
	sp->tex = DIR_SP;
	sp->x = x + 0.5;
	sp->y = y + 0.5;
	sp->th = atan2(sp->y - cub->player.y, sp->x - cub->player.x);
	if (sp->th < 0)
		sp->th += deg_to_rad(360);
	sp->dist = ft_dist(cub->player.x, cub->player.y, sp->x, sp->y);
	sp->dist *= cos(cub->player.th - sp->th);
}

t_sprite		*get_visible_sprites(t_cub *cub)
{
	int			n;
	int			x;
	int			y;
	t_sprite	*sp;

	n = 0;
	sp = NULL;
	y = -1;
	while (++y < cub->map.my)
	{
		x = -1;
		while (++x < cub->map.mx)
		{
			if (cub->sp.vis[y][x] == 0 || cub->map.map[y][x] != 2)
				continue ;
			if (n == 0)
				sp = (t_sprite *)malloc(sizeof(t_sprite));
			else
				sp = sprite_realloc(sp, n);
			get_sprite(cub, x, y, &sp[n]);
			n++;
		}
	}
	cub->sp.nsp = n;
	return (sp);
}

void			draw_col(t_cub *cub, int x, int y)
{
	int			y0;
	int			y1;
	int			add;

	cub->sp.txratio = (double)(x - cub->sp.cx) / cub->sp.sph + 0.5;
	cub->sp.tx = (int)(cub->sp.txratio * 120);
	y0 = (int)((cub->map.r[1] - cub->sp.sph) / 2.0);
	y1 = y0 + cub->sp.sph;
	add = 0;
	if (y0 < 0)
		add = y0 * -1;
	y0 = get_max(0, y0);
	y1 = get_min(cub->map.r[1], y1);
	y = y0 - 1;
	while (++y < y1)
	{
		cub->sp.ty = (int)((double)(y - y0 + add) * 120 / cub->sp.sph);
		cub->sp.color = get_sprite_color(cub, cub->sp.tx, cub->sp.ty);
		if ((cub->sp.color & 0x00ffffff) == 0 || \
			(y < TILE * cub->map.my && x < TILE * cub->map.mx))
			continue ;
		draw_pixel(cub, x, y, cub->sp.color);
	}
}

void			draw_sprite(t_cub *cub, t_sprite *sp, int i)
{
	int			x;
	int			y;

	cub->sp.cx = (int)((cub->player.fovh_2 - cub->sp.angle) * \
				cub->sp.pixel_per_angle);
	cub->sp.xmin = get_max(0, cub->sp.cx - cub->sp.sph / 2);
	cub->sp.xmax = get_min(cub->map.r[0], cub->sp.cx + cub->sp.sph / 2);
	x = cub->sp.xmin - 1;
	y = 0;
	while (++x < cub->sp.xmax)
	{
		if (sp[i].dist > cub->sp.zbuf[x])
			continue ;
		if (sp[i].dist <= 0.5)
			continue ;
		draw_col(cub, x, y);
	}
}

void			ft_sprite(t_cub *cub)
{
	t_sprite	*sp;
	int			i;

	cub->sp.pixel_per_angle = (cub->map.r[0] - 1) / cub->player.fov_h;
	sp = get_visible_sprites(cub);
	ft_qsort(sp, 0, cub->sp.nsp - 1);
	i = -1;
	while (++i < cub->sp.nsp)
	{
		cub->sp.sph = get_wall_height(cub, sp[i].dist);
		cub->ray.wdir = sp[i].tex;
		cub->sp.angle = sp[i].th - cub->player.th;
		if (cub->sp.angle > M_PI)
			cub->sp.angle -= M_PI * 2;
		else if (cub->sp.angle < -M_PI)
			cub->sp.angle += M_PI * 2;
		draw_sprite(cub, sp, i);
	}
	if (cub->sp.nsp > 0)
		free(sp);
}
